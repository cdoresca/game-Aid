#include "vkContextBuilder.h"
#include <set>
#include <string>

#include "queueFamily.h"
#include "swapChainSupportDetail.h"
#include "vkUtils.h"

namespace renderer{

vulkanContextBuilder::vulkanContextBuilder(window window, const std::vector<PhysicalDeviceFeature>& featureBasic, std::vector<const char*> deviceExtensions,VkPhysicalDeviceFeatures2 features2):
	window_(window),featureBasic(featureBasic), deviceExtensions(deviceExtensions), features2(features2) { }

void vulkanContextBuilder::createInstance(){

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "game-aid";
	appInfo.pEngineName = "no engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_3;

    VkValidationFeaturesEXT features{};
	features.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
	features.enabledValidationFeatureCount = validationFeature.size();
	features.pEnabledValidationFeatures = validationFeature.data();

    std::vector<const char*> extensions = getRequiredExtensions();
    
    VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();


    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
	if (enableValidationLayers)
	{
		populateDebugMessengerCreateInfo(debugCreateInfo);
		debugCreateInfo.pNext = &features;
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
	}
	else {
		createInfo.enabledLayerCount = 0;
		createInfo.pNext = nullptr;
	}

    VK_CHECK(vkCreateInstance(&createInfo, nullptr, &context.instance));
}

void vulkanContextBuilder::setupDebugMessenger(){
    if (!enableValidationLayers) return;

	VkDebugUtilsMessengerCreateInfoEXT createInfo{};
	populateDebugMessengerCreateInfo(createInfo);

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
    uint32_t extensionCount;
    VK_CHECK(vkEnumerateDeviceExtensionProperties(gpu, nullptr, &extensionCount, nullptr));
    
	std::vector<VkExtensionProperties> availableExtensions(extensionCount);
    VK_CHECK(vkEnumerateDeviceExtensionProperties(gpu, nullptr, &extensionCount, availableExtensions.data()));
    
	std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());
	for (const auto& extension : availableExtensions)
		requiredExtensions.erase(extension.extensionName);
    
	return requiredExtensions.empty();
}

bool vulkanContextBuilder::isModernFeatureSuitable(const VkPhysicalDevice& gpu)
{
	vkGetPhysicalDeviceFeatures2(gpu, &features2);

	auto* base = reinterpret_cast<VkBaseOutStructure*>(features2.pNext);
	while(base != nullptr) {
        

        switch (base->sType)
        {
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
                auto* asf = reinterpret_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base);
                if (!asf->accelerationStructure)
                    return false;
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
                auto* rtf = reinterpret_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base);
                if (!rtf->rayTracingPipeline)
                    return false;
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                auto* bda = reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(base);
                if (!bda->bufferDeviceAddress)
                    return false;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: 
            {
                auto* index = reinterpret_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(base);
                if (!index->descriptorBindingPartiallyBound || 
                    !index->descriptorBindingVariableDescriptorCount ||
                    !index->runtimeDescriptorArray)
                    return false;
                break;
            }
        }

		base = base->pNext;
	}
    return isFeatureSuitable(features2.features);
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
	
    uint32_t deviceCount = 0;

    VK_CHECK(vkEnumeratePhysicalDevices(context.instance, &deviceCount, nullptr));

    std::vector<VkPhysicalDevice> devices(deviceCount);
    VK_CHECK(vkEnumeratePhysicalDevices(context.instance, &deviceCount, devices.data()));

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
		VkDeviceQueueCreateInfo	queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = queueFamily;
		queueCreateInfo.queueCount = 1;
		queueCreateInfo.pQueuePriorities = &priorityQueue;
		info.push_back(queueCreateInfo);
	}
}

void vulkanContextBuilder::createDevice()
{

	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	createInfoQueue(queueCreateInfos);

	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
	createInfo.pQueueCreateInfos = queueCreateInfos.data();
	createInfo.pNext = &features2;
	createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
	createInfo.ppEnabledExtensionNames = deviceExtensions.data();
	if (enableValidationLayers)
	{
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else {
		createInfo.enabledLayerCount = 0;
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