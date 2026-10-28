#pragma once
#include "vulkan/vulkan.h"


namespace renderer{

namespace vkStruct{

inline VkApplicationInfo getVkApplicationInfo(const char* applicationName, uint32_t applicationVersion, const char* pEngineName, uint32_t engineVersion,uint32_t apiVersion, const void* pNext = nullptr);

inline VkValidationFeaturesEXT getVkValidationFeaturesEXT(uint32_t enabledValidationFeatureCount = 0,const VkValidationFeatureEnableEXT* pEnabledValidationFeatures = nullptr, uint32_t disabledValidationFeatureCount = 0, const VkValidationFeatureDisableEXT* pDisabledValidationFeatures = nullptr, const void* pNext = nullptr);

inline VkInstanceCreateInfo getVkInstanceCreateInfo(const VkApplicationInfo* pApplicationInfo, uint32_t enabledLayerCount, const char* const* ppEnabledLayerNames,uint32_t enabledExtensionCount, const char* const* ppEnabledExtensionNames, VkInstanceCreateFlags flags = 0,const void* pNext = nullptr);

inline VkDeviceQueueCreateInfo getVkDeviceQueueCreateInfo(uint32_t queueFamilyIndex, uint32_t queueCount,  const float* pQueuePriorities, VkDeviceQueueCreateFlags flags = 0, const void* pNext = nullptr);

inline VkDeviceCreateInfo getVkDeviceCreateInfo(uint32_t queueCreateInfoCount, const VkDeviceQueueCreateInfo* pQueueCreateInfos,uint32_t enabledLayerCount = 0, const char* const* ppEnabledLayerNames = nullptr, uint32_t enabledExtensionCount = 0, const char* const* ppEnabledExtensionNames = nullptr, const VkPhysicalDeviceFeatures* pEnabledFeatures = nullptr, VkDeviceCreateFlags flags = 0, const void* pNext = nullptr);

inline VkDebugUtilsMessengerCreateInfoEXT getVkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessageSeverityFlagsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback, void* pUserData = nullptr, VkDebugUtilsMessengerCreateFlagsEXT flags = 0, const void* pNext = nullptr);

inline VkAttachmentDescription getVkAttachmentDescription(VkFormat format, VkSampleCountFlagBits samples = VK_SAMPLE_COUNT_1_BIT, VkAttachmentLoadOp loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR, VkAttachmentStoreOp storeOp = VK_ATTACHMENT_STORE_OP_STORE, VkAttachmentLoadOp stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE, VkAttachmentStoreOp stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE, VkImageLayout initialLayout = VK_IMAGE_LAYOUT_UNDEFINED, VkImageLayout finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, VkAttachmentDescriptionFlags flags = 0);

inline VkAttachmentReference getVkAttachmentReference(uint32_t attachment, VkImageLayout layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);

inline VkSubpassDescription getVkSubpassDescription(VkPipelineBindPoint pipelineBindPoint, uint32_t inputAttachmentCount = 0, const VkAttachmentReference* pInputAttachments = nullptr, uint32_t colorAttachmentCount = 0, const VkAttachmentReference* pColorAttachments = nullptr, const VkAttachmentReference* pResolveAttachments = nullptr, const VkAttachmentReference* pDepthStencilAttachment = nullptr, uint32_t preserveAttachmentCount = 0, const uint32_t* pPreserveAttachments = nullptr, VkSubpassDescriptionFlags flags = 0);

inline VkRenderPassCreateInfo getVkRenderPassCreateInfo(uint32_t attachmentCount, const VkAttachmentDescription* pAttachments, uint32_t subpassCount, const VkSubpassDescription* pSubpasses, uint32_t dependencyCount, const VkSubpassDependency* pDependencies, VkRenderPassCreateFlags flags = 0, const void* pNext = nullptr);

inline VkSwapchainCreateInfoKHR getVkSwapchainCreateInfoKHR(VkSurfaceKHR surface, uint32_t minImageCount, VkFormat imageFormat, VkColorSpaceKHR imageColorSpace, VkExtent2D imageExtent, uint32_t imageArrayLayers, VkImageUsageFlags imageUsage, VkSharingMode imageSharingMode, uint32_t queueFamilyIndexCount, const uint32_t* pQueueFamilyIndices, VkSurfaceTransformFlagBitsKHR preTransform, VkCompositeAlphaFlagBitsKHR compositeAlpha, VkPresentModeKHR presentMode, VkBool32 clipped, VkSwapchainKHR oldSwapchain, VkSwapchainCreateFlagsKHR flags = 0, const void* pNext = nullptr);

inline VkImageViewCreateInfo getVkImageViewCreateInfo(VkImage image, VkImageViewType viewType, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange, VkImageViewCreateFlags flags = 0, const void* pNext = nullptr);

inline VkShaderModuleCreateInfo getVkShaderModuleCreateInfo(size_t codeSize, const uint32_t* pCode, VkShaderModuleCreateFlags flags = 0, const void* pNext = nullptr);

inline VkPipelineShaderStageCreateInfo getVkPipelineShaderStageCreateInfo(VkShaderStageFlagBits stage, VkShaderModule module,const char* pName, const VkSpecializationInfo* pSpecializationInfo = nullptr, VkPipelineShaderStageCreateFlags flags = 0, const void* pNext = nullptr);

inline VkPipelineVertexInputStateCreateInfo getVkPipelineVertexInputStateCreateInfo(uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription* pVertexAttributeDescriptions, VkPipelineVertexInputStateCreateFlags flags = 0, const void* pNext = nullptr);

inline VkPipelineInputAssemblyStateCreateInfo getVkPipelineInputAssemblyStateCreateInfo(VkPrimitiveTopology topology, VkBool32 primitiveRestartEnable, VkPipelineInputAssemblyStateCreateFlags flags, const void* pNext);

inline VkPipelineViewportStateCreateInfo getVkPipelineViewportStateCreateInfo(uint32_t viewportCount, const VkViewport* pViewports, uint32_t scissorCount, const VkRect2D* pScissors, VkPipelineViewportStateCreateFlags flags = 0, const void* pNext = nullptr);

inline VkPipelineRasterizationStateCreateInfo getVkPipelineRasterizationStateCreateInfo(VkBool32 depthClampEnable, VkBool32 rasterizerDiscardEnable, VkPolygonMode polygonMode, VkCullModeFlags cullMode, VkFrontFace frontFace, VkBool32 depthBiasEnable, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor, float lineWidth, VkPipelineRasterizationStateCreateFlags flags, const void* pNext);

inline VkPipelineMultisampleStateCreateInfo getVkPipelineMultisampleStateCreateInfo(VkSampleCountFlagBits rasterizationSamples, VkBool32 sampleShadingEnable, float minSampleShading, const VkSampleMask* pSampleMask, VkBool32 alphaToCoverageEnable, VkBool32 alphaToOneEnable, VkPipelineMultisampleStateCreateFlags flags, const void* pNext);

inline VkPipelineColorBlendAttachmentState getVkPipelineColorBlendAttachmentState(VkColorComponentFlags colorWriteMask, VkBool32 blendEnable, VkBlendFactor srcColorBlendFactor = VK_BLEND_FACTOR_ZERO, VkBlendFactor dstColorBlendFactor = VK_BLEND_FACTOR_ZERO, VkBlendOp colorBlendOp = VK_BLEND_OP_ADD, VkBlendFactor srcAlphaBlendFactor = VK_BLEND_FACTOR_ZERO, VkBlendFactor dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO, VkBlendOp alphaBlendOp = VK_BLEND_OP_ADD);

inline VkPipelineColorBlendStateCreateInfo getVkPipelineColorBlendStateCreateInfo(VkBool32 logicOpEnable, VkLogicOp logicOp, uint32_t attachmentCount, const VkPipelineColorBlendAttachmentState* pAttachments, float blendConstants[4], VkPipelineColorBlendStateCreateFlags flags = 0, const void* pNext = nullptr);

inline VkPipelineDynamicStateCreateInfo getVkPipelineDynamicStateCreateInfo(uint32_t dynamicStateCount, const VkDynamicState* pDynamicStates, VkPipelineDynamicStateCreateFlags flags = 0, const void* pNext = nullptr);

inline VkPipelineLayoutCreateInfo getVkPipelineLayoutCreateInfo(uint32_t setLayoutCount, const VkDescriptorSetLayout* pSetLayouts, uint32_t pushConstantRangeCount, const VkPushConstantRange* pPushConstantRanges, VkPipelineLayoutCreateFlags flags = 0, const void* pNext = nullptr);

inline VkGraphicsPipelineCreateInfo getVkGraphicsPipelineCreateInfo(VkPipelineLayout layout, VkRenderPass renderPass, uint32_t subpass, uint32_t stageCount,VkPipeline basePipelineHandle, int32_t basePipelineIndex, const VkPipelineShaderStageCreateInfo* pStages, const VkPipelineVertexInputStateCreateInfo* pVertexInputState, const VkPipelineInputAssemblyStateCreateInfo* pInputAssemblyState, const VkPipelineTessellationStateCreateInfo* pTessellationState, const VkPipelineViewportStateCreateInfo* pViewportState, const VkPipelineRasterizationStateCreateInfo* pRasterizationState, const VkPipelineMultisampleStateCreateInfo* pMultisampleState, const VkPipelineDepthStencilStateCreateInfo* pDepthStencilState, const VkPipelineColorBlendStateCreateInfo* pColorBlendState, const VkPipelineDynamicStateCreateInfo* pDynamicState, VkPipelineCreateFlags flags = 0, const void* pNext = nullptr);

inline VkComputePipelineCreateInfo getVkComputePipelineCreateInfo(VkPipelineLayout layout, VkPipelineShaderStageCreateInfo stage, VkPipeline basePipelineHandle, int32_t basePipelineIndex, VkPipelineCreateFlags flags, const void* pNext);

inline VkFramebufferCreateInfo getVkFramebufferCreateInfo(VkRenderPass renderPass, uint32_t attachmentCount, const VkImageView* pAttachments, uint32_t width, uint32_t height, uint32_t layers, VkFramebufferCreateFlags flags = 0, const void* pNext = nullptr);

}

}