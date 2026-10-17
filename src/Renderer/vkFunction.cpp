#include "vkFunction.h"
#include "vkUtils.h"

namespace renderer{

namespace vkFct{

VkApplicationInfo getVkApplicationInfo(const char* applicationName, uint32_t applicationVersion, const char* pEngineName, uint32_t engineVersion,uint32_t apiVersion, const void* pNext){
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = applicationName;
	appInfo.pEngineName = pEngineName;
	appInfo.engineVersion = applicationVersion;
	appInfo.apiVersion = apiVersion;
    appInfo.pNext = pNext;
    return appInfo;
}

VkValidationFeaturesEXT getVkValidationFeaturesEXT(uint32_t enabledValidationFeatureCount,const VkValidationFeatureEnableEXT* pEnabledValidationFeatures, uint32_t disabledValidationFeatureCount, const VkValidationFeatureDisableEXT* pDisabledValidationFeatures, const void* pNext){
    VkValidationFeaturesEXT features{};
	features.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
	features.enabledValidationFeatureCount = enabledValidationFeatureCount;
	features.pEnabledValidationFeatures = pEnabledValidationFeatures;
    features.disabledValidationFeatureCount = disabledValidationFeatureCount;
    features.pDisabledValidationFeatures = pDisabledValidationFeatures;
    features.pNext = pNext;
    return features;
}

VkInstanceCreateInfo getVkInstanceCreateInfo(const VkApplicationInfo* pApplicationInfo, uint32_t enabledLayerCount, const char* const* ppEnabledLayerNames,uint32_t enabledExtensionCount, const char* const* ppEnabledExtensionNames, VkInstanceCreateFlags flags,const void* pNext){
    VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = pApplicationInfo;
	createInfo.enabledExtensionCount = enabledExtensionCount;
	createInfo.ppEnabledExtensionNames = ppEnabledExtensionNames;
    createInfo.enabledLayerCount = enabledLayerCount;
    createInfo.ppEnabledLayerNames = ppEnabledLayerNames;
    createInfo.flags = flags;
    createInfo.pNext = pNext;
    return createInfo;
}

VkDeviceQueueCreateInfo getVkDeviceQueueCreateInfo(uint32_t queueFamilyIndex, uint32_t queueCount,  const float* pQueuePriorities, VkDeviceQueueCreateFlags flags = 0, const void* pNext = nullptr){
    VkDeviceQueueCreateInfo	queueCreateInfo{};
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.queueFamilyIndex = queueFamilyIndex;
    queueCreateInfo.queueCount = queueCount;
    queueCreateInfo.pQueuePriorities = pQueuePriorities;
    queueCreateInfo.flags = flags;
    queueCreateInfo.pNext = pNext;
    return queueCreateInfo;
}

VkDeviceCreateInfo getVkDeviceCreateInfo(uint32_t queueCreateInfoCount, const VkDeviceQueueCreateInfo* pQueueCreateInfos,uint32_t enabledLayerCount, const char* const* ppEnabledLayerNames, uint32_t enabledExtensionCount, const char* const* ppEnabledExtensionNames, const VkPhysicalDeviceFeatures* pEnabledFeatures, VkDeviceCreateFlags flags, const void* pNext){
    VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.queueCreateInfoCount = queueCreateInfoCount;
    createInfo.pQueueCreateInfos = pQueueCreateInfos;
    createInfo.enabledLayerCount = enabledLayerCount;
    createInfo.ppEnabledLayerNames = ppEnabledLayerNames;
    createInfo.enabledExtensionCount = enabledExtensionCount;
    createInfo.ppEnabledExtensionNames = ppEnabledExtensionNames;
    createInfo.pEnabledFeatures = pEnabledFeatures;
    createInfo.flags = flags;
    createInfo.pNext = pNext;
    return createInfo;
}

VkDebugUtilsMessengerCreateInfoEXT getVkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessageSeverityFlagsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback, void* pUserData, VkDebugUtilsMessengerCreateFlagsEXT flags, const void* pNext){
    VkDebugUtilsMessengerCreateInfoEXT info;
    info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    info.messageSeverity = messageSeverity;
    info.messageType = messageType;
    info.pfnUserCallback = pfnUserCallback;
    info.pUserData = pUserData;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkAttachmentDescription getVkAttachmentDescription(VkFormat format, VkSampleCountFlagBits samples, VkAttachmentLoadOp loadOp, VkAttachmentStoreOp storeOp, VkAttachmentLoadOp stencilLoadOp, VkAttachmentStoreOp stencilStoreOp, VkImageLayout initialLayout, VkImageLayout finalLayout, VkAttachmentDescriptionFlags flags){
    VkAttachmentDescription attachment{};
    attachment.format = format;
    attachment.samples = samples;
    attachment.loadOp = loadOp;
    attachment.storeOp = storeOp;
    attachment.stencilLoadOp = stencilLoadOp;
    attachment.stencilStoreOp = stencilStoreOp;
    attachment.initialLayout = initialLayout;
    attachment.finalLayout = finalLayout;
    attachment.flags = flags;
    return attachment;
}

VkAttachmentReference getVkAttachmentReference(uint32_t attachment, VkImageLayout layout){
    VkAttachmentReference ref{};
    ref.attachment = attachment;
    ref.layout = layout;
    return ref;
}

VkSubpassDescription getVkSubpassDescription(VkPipelineBindPoint pipelineBindPoint, uint32_t inputAttachmentCount, const VkAttachmentReference* pInputAttachments , uint32_t colorAttachmentCount, const VkAttachmentReference* pColorAttachments, const VkAttachmentReference* pResolveAttachments, const VkAttachmentReference* pDepthStencilAttachment, uint32_t preserveAttachmentCount, const uint32_t* pPreserveAttachments, VkSubpassDescriptionFlags flags){
    VkSubpassDescription sub{};
    sub.pipelineBindPoint = pipelineBindPoint;
    sub.inputAttachmentCount = inputAttachmentCount;
    sub.pInputAttachments = pInputAttachments;
    sub.colorAttachmentCount = colorAttachmentCount;
    sub.pColorAttachments = pColorAttachments;
    sub.pResolveAttachments = pResolveAttachments;
    sub.pDepthStencilAttachment = pDepthStencilAttachment;
    sub.preserveAttachmentCount = preserveAttachmentCount;
    sub.pPreserveAttachments = pPreserveAttachments;
    sub.flags = flags;
    return sub;
}

VkRenderPassCreateInfo getVkRenderPass(uint32_t attachmentCount, const VkAttachmentDescription* pAttachments, uint32_t subpassCount, const VkSubpassDescription* pSubpasses, uint32_t dependencyCount, const VkSubpassDependency* pDependencies, VkRenderPassCreateFlags flags, const void* pNext){
    VkRenderPassCreateInfo info{};
    info.attachmentCount = attachmentCount;
    info.pAttachments = pAttachments;
    info.subpassCount = subpassCount;
    info.pSubpasses = pSubpasses;
    info.dependencyCount = dependencyCount;
    info.pDependencies = pDependencies;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

std::vector<VkExtensionProperties> getVkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName){
    uint32_t count;
    VK_CHECK(vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, &count, nullptr));
    std::vector<VkExtensionProperties> extensions(count);
    VK_CHECK(vkEnumerateDeviceExtensionProperties(physicalDevice,pLayerName, &count, extensions.data()));
    return extensions;
}

std::vector<VkPhysicalDevice> getVkEnumeratePhysicalDevices(VkInstance instance){
    uint32_t count;
    VK_CHECK(vkEnumeratePhysicalDevices(instance, &count, nullptr));
    std::vector<VkPhysicalDevice> gpu(count);
    VK_CHECK(vkEnumeratePhysicalDevices(instance,&count,gpu.data()));
    return gpu;
}

}

}