#pragma once
#include "vulkan/vulkan.h"
#include <vector>

namespace renderer{

namespace vkFct{

VkApplicationInfo getVkApplicationInfo(const char* applicationName, uint32_t applicationVersion, const char* pEngineName, uint32_t engineVersion,uint32_t apiVersion, const void* pNext = nullptr);

VkValidationFeaturesEXT getVkValidationFeaturesEXT(uint32_t enabledValidationFeatureCount = 0,const VkValidationFeatureEnableEXT* pEnabledValidationFeatures = nullptr, uint32_t disabledValidationFeatureCount = 0, const VkValidationFeatureDisableEXT* pDisabledValidationFeatures = nullptr, const void* pNext = nullptr);

VkInstanceCreateInfo getVkInstanceCreateInfo(const VkApplicationInfo* pApplicationInfo, uint32_t enabledLayerCount, const char* const* ppEnabledLayerNames,uint32_t enabledExtensionCount, const char* const* ppEnabledExtensionNames, VkInstanceCreateFlags flags = 0,const void* pNext = nullptr);

VkDeviceQueueCreateInfo getVkDeviceQueueCreateInfo(uint32_t queueFamilyIndex, uint32_t queueCount,  const float* pQueuePriorities, VkDeviceQueueCreateFlags flags = 0, const void* pNext = nullptr);

VkDeviceCreateInfo getVkDeviceCreateInfo(uint32_t queueCreateInfoCount, const VkDeviceQueueCreateInfo* pQueueCreateInfos,uint32_t enabledLayerCount = 0, const char* const* ppEnabledLayerNames = nullptr, uint32_t enabledExtensionCount = 0, const char* const* ppEnabledExtensionNames = nullptr, const VkPhysicalDeviceFeatures* pEnabledFeatures = nullptr, VkDeviceCreateFlags flags = 0, const void* pNext = nullptr);

VkDebugUtilsMessengerCreateInfoEXT getVkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessageSeverityFlagsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback, void* pUserData = nullptr, VkDebugUtilsMessengerCreateFlagsEXT flags = 0, const void* pNext = nullptr);

VkAttachmentDescription getVkAttachmentDescription(VkFormat format, VkSampleCountFlagBits samples = VK_SAMPLE_COUNT_1_BIT, VkAttachmentLoadOp loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR, VkAttachmentStoreOp storeOp = VK_ATTACHMENT_STORE_OP_STORE, VkAttachmentLoadOp stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE, VkAttachmentStoreOp stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE, VkImageLayout initialLayout = VK_IMAGE_LAYOUT_UNDEFINED, VkImageLayout finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, VkAttachmentDescriptionFlags flags = 0);

VkAttachmentReference getVkAttachmentReference(uint32_t attachment, VkImageLayout layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);

VkSubpassDescription getVkSubpassDescription(VkPipelineBindPoint pipelineBindPoint, uint32_t inputAttachmentCount = 0, const VkAttachmentReference* pInputAttachments = nullptr, uint32_t colorAttachmentCount = 0, const VkAttachmentReference* pColorAttachments = nullptr, const VkAttachmentReference* pResolveAttachments = nullptr, const VkAttachmentReference* pDepthStencilAttachment = nullptr, uint32_t preserveAttachmentCount = 0, const uint32_t* pPreserveAttachments = nullptr, VkSubpassDescriptionFlags flags = 0);

VkRenderPassCreateInfo getVkRenderPassCreateInfo(uint32_t attachmentCount, const VkAttachmentDescription* pAttachments, uint32_t subpassCount, const VkSubpassDescription* pSubpasses, uint32_t dependencyCount, const VkSubpassDependency* pDependencies, VkRenderPassCreateFlags flags = 0, const void* pNext = nullptr);

std::vector<VkExtensionProperties> getVkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName = nullptr);

std::vector<VkPhysicalDevice> getVkEnumeratePhysicalDevices(VkInstance instance);

}

}