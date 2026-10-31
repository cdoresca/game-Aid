#pragma once
#include "vulkan/vulkan.h"
#include <vector>

namespace renderer{

    namespace vkQuery{

        std::vector<VkExtensionProperties> queryvkEnumerateInstanceExtensionProperties( const char* pLayerName = nullptr);
        
        std::vector<VkExtensionProperties> queryVkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName = nullptr);

        std::vector<VkPhysicalDevice> queryVkEnumeratePhysicalDevices(VkInstance instance);

        std::vector<VkImage> queryVkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapChain);

        uint32_t findMemoryType(VkPhysicalDevice physical, uint32_t typeFilter, VkMemoryPropertyFlags properties);
         
        std::vector<const char*> queryExtensionInstance();

        VkSurfaceCapabilitiesKHR queryVkSurfaceCapabilitiesKHR(VkPhysicalDevice device, VkSurfaceKHR surface);
        
        std::vector<VkSurfaceFormatKHR> queryVkSurfaceFormatKHR(VkPhysicalDevice device, VkSurfaceKHR surface);

        std::vector<VkPresentModeKHR> queryVkPresentModeKHR(VkPhysicalDevice device, VkSurfaceKHR surface);

        std::vector<VkQueueFamilyProperties> queryVkPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice device);

        std::vector<const char *> queryRequieredExtensionInstance();
    }   

}