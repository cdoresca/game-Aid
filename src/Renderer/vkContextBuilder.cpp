#include "vkContextBuilder.h"
#include <set>
#include <string>

#include "queueFamily.h"
#include "swapChainSupportDetail.h"
#include "vkUtils.h"
#include "vkFunction.h"

namespace renderer{

vulkanContextBuilder::vulkanContextBuilder(window window, const std::vector<PhysicalDeviceFeature>& featureBasic, std::vector<const char*> deviceExtensions,VkPhysicalDeviceFeatures2 features2):
	window_(window),featureBasic(featureBasic), deviceExtensions(deviceExtensions), features2(features2) { }

void vulkanContextBuilder::createInstance(){

    VkApplicationInfo appInfo = vkFct::getVkApplicationInfo("game-aid", 1,"no engine", VK_MAKE_VERSION(1, 0, 0),VK_API_VERSION_1_3);
    VkValidationFeaturesEXT features = vkFct::getVkValidationFeaturesEXT(validationFeature.size(), validationFeature.data());
    std::vector<const char*> extensions = getRequiredExtensions();
    
    VkInstanceCreateInfo createInfo{};
	
	if (enableValidationLayers)
	{
		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo = vkFct::getVkDebugUtilsMessengerCreateInfoEXT(VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
			VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
			debugCallback,
			nullptr,
			0,
			&features
		);

		createInfo = vkFct::getVkInstanceCreateInfo(&appInfo, 
			static_cast<uint32_t>(validationLayers.size()), 
			validationLayers.data(), static_cast<uint32_t>(extensions.size()), 
			extensions.data(),
			0,
			(VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo
		);
	}
	else {
		createInfo = vkFct::getVkInstanceCreateInfo(&appInfo, 
			0, 
			nullptr,
			static_cast<uint32_t>(extensions.size()), 
			extensions.data()
		);
	}

    VK_CHECK(vkCreateInstance(&createInfo, nullptr, &context.instance));
}

void vulkanContextBuilder::setupDebugMessenger(){
    if (!enableValidationLayers) return;

	
	VkDebugUtilsMessengerCreateInfoEXT createInfo = vkFct::getVkDebugUtilsMessengerCreateInfoEXT(VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
		VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
		debugCallback
	);

	VK_CHECK(CreateDebugUtilsMessengerEXT(context.instance, &createInfo, nullptr, &context.debugMessenger));
}

void vulkanContextBuilder::createSurface(){ 
	VK_CHECK(glfwCreateWindowSurface(context.instance, window_.get(), nullptr, &context.surface));
}

bool vulkanContextBuilder::isDeviceSuitable(const VkPhysicalDevice& gpu) { 
    return isQueueSuitable(gpu) && 
        isExtensionSuitable(gpu) && 
        isSwapChainSuitable(gpu) &&
		isModernFeatureSuitable(gpu);
}

bool vulkanContextBuilder::isExtensionSuitable(const VkPhysicalDevice& gpu) const
{
	std::vector<VkExtensionProperties> availableExtensions = vkFct::getVkEnumerateDeviceExtensionProperties(gpu);
    
	std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());
	for (const auto& extension : availableExtensions)
		requiredExtensions.erase(extension.extensionName);
    
	return requiredExtensions.empty();
}


bool vulkanContextBuilder::isQueueSuitable(const VkPhysicalDevice& gpu) const{
	QueueFamiliesIndices indices = findQueueFamilies(gpu,context.surface);

	return indices.isComplete();
}

bool vulkanContextBuilder::isSwapChainSuitable(const VkPhysicalDevice& gpu) const{
	SwapChainSupportDetails swapChainSupport = querySwapChainSupport(gpu, context.surface);
	return !swapChainSupport.formats.empty() && !swapChainSupport.presentsModes.empty();
}

bool vulkanContextBuilder::isFeatureSuitable(const VkPhysicalDeviceFeatures& features) const
{
	for (int i = 0; i < featureBasic.size(); i++) 
		if (!(features.*(featureBasic[i].member))) return false;

	return true;
}

void vulkanContextBuilder::choosePhysicalDevice()
{
    std::vector<VkPhysicalDevice> devices = vkFct::getVkEnumeratePhysicalDevices(context.instance);

    for (const auto& gpu : devices) {
        if (isDeviceSuitable(gpu)) {
            context.physicalDevice = gpu;
            break;
        }
    }
}

void vulkanContextBuilder::createInfoQueue(std::vector<VkDeviceQueueCreateInfo>& info)
{
    QueueFamiliesIndices indices = findQueueFamilies(context.physicalDevice, context.surface);

	std::set<uint32_t> uniqueQueueFamilies = { indices.graphicFamily.value(), indices.presentFamily.value() };
	
	for (uint32_t queueFamily : uniqueQueueFamilies) {
		VkDeviceQueueCreateInfo	queueCreateInfo = vkFct::getVkDeviceQueueCreateInfo(queueFamily, 1,&priorityQueue);
		info.push_back(queueCreateInfo);
	}
}

void vulkanContextBuilder::createDevice()
{

	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	createInfoQueue(queueCreateInfos);

	VkDeviceCreateInfo createInfo{};
	
	if (enableValidationLayers)
	{
		createInfo = vkFct::getVkDeviceCreateInfo(static_cast<uint32_t>(queueCreateInfos.size()),queueCreateInfos.data(),static_cast<uint32_t>(validationLayers.size()),validationLayers.data(),static_cast<uint32_t>(deviceExtensions.size()),deviceExtensions.data());	
	}
	else {
		createInfo = vkFct::getVkDeviceCreateInfo(static_cast<uint32_t>(queueCreateInfos.size()),queueCreateInfos.data(), 0 ,nullptr,static_cast<uint32_t>(deviceExtensions.size()),deviceExtensions.data());
	}
	VK_CHECK(vkCreateDevice(context.physicalDevice, &createInfo, nullptr, &context.device));
}

void vulkanContextBuilder::createQueue()
{
	QueueFamiliesIndices indices = findQueueFamilies(context.physicalDevice, context.surface);

	vkGetDeviceQueue(context.device, indices.graphicFamily.value(), 0, &context.graphicsQueue);
	vkGetDeviceQueue(context.device, indices.presentFamily.value(), 0, &context.presentQueue);
	vkGetDeviceQueue(context.device, indices.computeFamily.value(), 0, &context.computeQueue);    
}

void vulkanContextBuilder::reset()
{
	context = {};
}

VkContext vulkanContextBuilder::get() { return context; }

void vulkanContextBuilder::build(){
	createInstance();
	setupDebugMessenger();
	createSurface();
	choosePhysicalDevice();
	createDevice();
	createQueue();
}

}