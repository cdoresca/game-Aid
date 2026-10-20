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

VkDeviceQueueCreateInfo getVkDeviceQueueCreateInfo(uint32_t queueFamilyIndex, uint32_t queueCount,  const float* pQueuePriorities, VkDeviceQueueCreateFlags flags, const void* pNext){
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

VkSwapchainCreateInfoKHR getVkSwapchainCreateInfoKHR(VkSurfaceKHR surface, uint32_t minImageCount, VkFormat imageFormat, VkColorSpaceKHR imageColorSpace, VkExtent2D imageExtent, uint32_t imageArrayLayers, VkImageUsageFlags imageUsage, VkSharingMode imageSharingMode, uint32_t queueFamilyIndexCount, const uint32_t* pQueueFamilyIndices, VkSurfaceTransformFlagBitsKHR preTransform, VkCompositeAlphaFlagBitsKHR compositeAlpha, VkPresentModeKHR presentMode, VkBool32 clipped, VkSwapchainKHR oldSwapchain, VkSwapchainCreateFlagsKHR flags, const void* pNext){
   VkSwapchainCreateInfoKHR info{};
   info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
   info.surface = surface;
   info.minImageCount = minImageCount;
   info.imageFormat = imageFormat;
   info.imageColorSpace = imageColorSpace;
   info.imageExtent = imageExtent;
   info.imageArrayLayers = imageArrayLayers;
   info.imageUsage = imageUsage;
   info.imageSharingMode = imageSharingMode;
   info.queueFamilyIndexCount = queueFamilyIndexCount;
   info.pQueueFamilyIndices = pQueueFamilyIndices;
   info.preTransform = preTransform;
   info.compositeAlpha = compositeAlpha;
   info.presentMode = presentMode;
   info.clipped = clipped;
   info.oldSwapchain = oldSwapchain;
   info.flags = flags;
   info.pNext = pNext;
    return info;
}

VkImageViewCreateInfo getVkImageViewCreateInfo(VkImage image, VkImageViewType viewType, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange, VkImageViewCreateFlags flags, const void* pNext){
    VkImageViewCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    info.image = image;
    info.viewType = viewType;
    info.format = format;
    info.components = components;
    info.subresourceRange = subresourceRange;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkShaderModuleCreateInfo getVkShaderModuleCreateInfo(size_t codeSize, const uint32_t* pCode, VkShaderModuleCreateFlags flags, const void* pNext){
   
    VkShaderModuleCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    info.codeSize = codeSize;
    info.pCode = pCode;
    info.flags = flags; 
    info.pNext = pNext;
    return info;
}

VkPipelineShaderStageCreateInfo getVkPipelineShaderStageCreateInfo(VkShaderStageFlagBits stage, VkShaderModule module,const char* pName, const VkSpecializationInfo* pSpecializationInfo, VkPipelineShaderStageCreateFlags flags, const void* pNext){
    VkPipelineShaderStageCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    info.stage = stage;
    info.module = module;
    info.pName = pName;
    info.pSpecializationInfo = pSpecializationInfo;
    info.flags = flags;
    info.pNext = nullptr;
    return info;
}

VkPipelineInputAssemblyStateCreateInfo getVkPipelineInputAssemblyStateCreateInfo(VkPrimitiveTopology topology, VkBool32 primitiveRestartEnable, VkPipelineInputAssemblyStateCreateFlags flags, const void* pNext){
    VkPipelineInputAssemblyStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    info.topology = topology;
    info.primitiveRestartEnable = primitiveRestartEnable;
    info.flags = flags;
    info.pNext;
    return info;
}
VkPipelineVertexInputStateCreateInfo getVkPipelineVertexInputStateCreateInfo(uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription* pVertexAttributeDescriptions, VkPipelineVertexInputStateCreateFlags flags, const void* pNext){
    VkPipelineVertexInputStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    info.vertexBindingDescriptionCount = vertexBindingDescriptionCount;
    info.pVertexBindingDescriptions = pVertexBindingDescriptions;
    info.vertexAttributeDescriptionCount = vertexAttributeDescriptionCount;
    info.pVertexAttributeDescriptions = pVertexAttributeDescriptions;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkPipelineViewportStateCreateInfo getVkPipelineViewportStateCreateInfo(uint32_t viewportCount, const VkViewport* pViewports, uint32_t scissorCount, const VkRect2D* pScissors, VkPipelineViewportStateCreateFlags flags, const void* pNext){
    VkPipelineViewportStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    info.viewportCount = viewportCount;
    info.pViewports = pViewports;
    info.scissorCount = scissorCount;
    info.pScissors = pScissors;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkPipelineRasterizationStateCreateInfo getVkPipelineRasterizationStateCreateInfo(VkBool32 depthClampEnable, VkBool32 rasterizerDiscardEnable, VkPolygonMode polygonMode, VkCullModeFlags cullMode, VkFrontFace frontFace, VkBool32 depthBiasEnable, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor, float lineWidth, VkPipelineRasterizationStateCreateFlags flags, const void* pNext){
    VkPipelineRasterizationStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    info.depthClampEnable = depthClampEnable;
    info.rasterizerDiscardEnable = rasterizerDiscardEnable;
    info.polygonMode = polygonMode;
    info.cullMode = cullMode;
    info.frontFace = frontFace;
    info.depthBiasEnable = depthBiasEnable;
    info.depthBiasConstantFactor = depthBiasConstantFactor;
    info.depthBiasClamp = depthBiasClamp;
    info.depthBiasSlopeFactor = depthBiasSlopeFactor;
    info.lineWidth = lineWidth;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkPipelineMultisampleStateCreateInfo getVkPipelineMultisampleStateCreateInfo(VkSampleCountFlagBits rasterizationSamples, VkBool32 sampleShadingEnable, float minSampleShading, const VkSampleMask* pSampleMask, VkBool32 alphaToCoverageEnable, VkBool32 alphaToOneEnable, VkPipelineMultisampleStateCreateFlags flags, const void* pNext){
    VkPipelineMultisampleStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    info.rasterizationSamples = rasterizationSamples;
    info.sampleShadingEnable = sampleShadingEnable;
    info.minSampleShading = minSampleShading;
    info.pSampleMask = pSampleMask;
    info.alphaToCoverageEnable = alphaToCoverageEnable;
    info.alphaToOneEnable = alphaToOneEnable;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkPipelineColorBlendAttachmentState getVkPipelineColorBlendAttachmentState(VkColorComponentFlags colorWriteMask, VkBool32 blendEnable, VkBlendFactor srcColorBlendFactor, VkBlendFactor dstColorBlendFactor, VkBlendOp colorBlendOp, VkBlendFactor srcAlphaBlendFactor, VkBlendFactor dstAlphaBlendFactor, VkBlendOp alphaBlendOp){
    VkPipelineColorBlendAttachmentState  state{};
    state.colorWriteMask = colorWriteMask;
    state.blendEnable = blendEnable;
    if(blendEnable)
        return state;
    state.srcColorBlendFactor = srcColorBlendFactor;
    state.dstColorBlendFactor = dstColorBlendFactor;
    state.colorBlendOp = colorBlendOp;
    state.srcAlphaBlendFactor = srcAlphaBlendFactor;
    state.dstAlphaBlendFactor = dstAlphaBlendFactor;
    state.alphaBlendOp = alphaBlendOp;
    return state;
}

VkPipelineColorBlendStateCreateInfo getVkPipelineColorBlendStateCreateInfo(VkBool32 logicOpEnable, VkLogicOp logicOp, uint32_t attachmentCount, const VkPipelineColorBlendAttachmentState* pAttachments, float blendConstants[4], VkPipelineColorBlendStateCreateFlags flags, const void* pNext){
    VkPipelineColorBlendStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    info.logicOpEnable = logicOpEnable;
    info.logicOp = logicOp;
    info.attachmentCount = attachmentCount;
    info.pAttachments = pAttachments;
    info.blendConstants[0] = blendConstants[0];
    info.blendConstants[1] = blendConstants[1];
    info.blendConstants[2] = blendConstants[2];
    info.blendConstants[3] = blendConstants[3];
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkPipelineDynamicStateCreateInfo getVkPipelineDynamicStateCreateInfo(uint32_t dynamicStateCount, const VkDynamicState* pDynamicStates, VkPipelineDynamicStateCreateFlags flags, const void* pNext){
    VkPipelineDynamicStateCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    info.dynamicStateCount = dynamicStateCount;
    info.pDynamicStates = pDynamicStates;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkPipelineLayoutCreateInfo getVkPipelineLayoutCreateInfo(uint32_t setLayoutCount, const VkDescriptorSetLayout* pSetLayouts, uint32_t pushConstantRangeCount, const VkPushConstantRange* pPushConstantRanges, VkPipelineLayoutCreateFlags flags, const void* pNext){
    VkPipelineLayoutCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    info.setLayoutCount = setLayoutCount;
    info.pSetLayouts = pSetLayouts;
    info.pushConstantRangeCount = pushConstantRangeCount;
    info.pPushConstantRanges = pPushConstantRanges;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkGraphicsPipelineCreateInfo getVkGraphicsPipelineCreateInfo(VkPipelineLayout layout, VkRenderPass renderPass, uint32_t subpass, uint32_t stageCount,VkPipeline basePipelineHandle, int32_t basePipelineIndex, const VkPipelineShaderStageCreateInfo* pStages, const VkPipelineVertexInputStateCreateInfo* pVertexInputState, const VkPipelineInputAssemblyStateCreateInfo* pInputAssemblyState, const VkPipelineTessellationStateCreateInfo* pTessellationState, const VkPipelineViewportStateCreateInfo* pViewportState, const VkPipelineRasterizationStateCreateInfo* pRasterizationState, const VkPipelineMultisampleStateCreateInfo* pMultisampleState, const VkPipelineDepthStencilStateCreateInfo* pDepthStencilState, const VkPipelineColorBlendStateCreateInfo* pColorBlendState, const VkPipelineDynamicStateCreateInfo* pDynamicState, VkPipelineCreateFlags flags, const void* pNext){
    VkGraphicsPipelineCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    info.layout = layout;
    info.stageCount = stageCount;
    info.subpass = subpass;
    info.renderPass = renderPass;
    info.basePipelineIndex = basePipelineIndex;
    info.basePipelineHandle = basePipelineHandle;
    info.pColorBlendState = pColorBlendState;
    info.pDepthStencilState = pDepthStencilState;
    info.pDynamicState = pDynamicState;
    info.pInputAssemblyState = pInputAssemblyState;
    info.pMultisampleState = pMultisampleState;
    info.pRasterizationState = pRasterizationState;
    info.pTessellationState = pTessellationState;
    info.pVertexInputState = pVertexInputState;
    info.pViewportState = pViewportState;
    info.pStages = pStages;
    return info; 
}

VkFramebufferCreateInfo getVkFramebufferCreateInfo(VkRenderPass renderPass, uint32_t attachmentCount, const VkImageView* pAttachments, uint32_t width, uint32_t height, uint32_t layers, VkFramebufferCreateFlags flags, const void* pNext){
    VkFramebufferCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    info.renderPass = renderPass;
    info.attachmentCount = attachmentCount;
    info.pAttachments = pAttachments;
    info.width = width;
    info.height = height;
    info.layers = layers;
    info.flags = flags;
    info.pNext = pNext;
    return info;
}

VkComputePipelineCreateInfo getVkComputePipelineCreateInfo(VkPipelineLayout layout, VkPipelineShaderStageCreateInfo stage, VkPipeline basePipelineHandle, int32_t basePipelineIndex, VkPipelineCreateFlags flags, const void* pNext){
    VkComputePipelineCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    info.layout = layout;
    info.stage = stage;
    info.basePipelineIndex = basePipelineIndex;
    info.basePipelineHandle = basePipelineHandle;
    info.flags = flags;
    info.pNext = pNext;
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

std::vector<VkImage> getVkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapChain){
    uint32_t count;
    VK_CHECK(vkGetSwapchainImagesKHR(device, swapChain, &count, nullptr));
    std::vector<VkImage> swapChainImages(count);
    VK_CHECK(vkGetSwapchainImagesKHR(device, swapChain, &count, swapChainImages.data()));
    return swapChainImages;
}


}

}