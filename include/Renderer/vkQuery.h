#pragma once
#include "vulkan/vulkan.h"
#include <vector>

namespace renderer{

    namespace vkQuery{

        inline std::vector<VkExtensionProperties> queryvkEnumerateInstanceExtensionProperties( const char* pLayerName = nullptr);
        
        inline std::vector<VkExtensionProperties> queryVkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName = nullptr);

        inline std::vector<VkPhysicalDevice> queryVkEnumeratePhysicalDevices(VkInstance instance);

        inline std::vector<VkImage> queryVkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapChain);

        inline uint32_t findMemoryType(VkPhysicalDevice physical, uint32_t typeFilter, VkMemoryPropertyFlags properties);
         
        inline std::vector<const char*> queryExtensionInstance();

        inline VkSurfaceCapabilitiesKHR queryVkSurfaceCapabilitiesKHR(VkPhysicalDevice device, VkSurfaceKHR surface);
        
        inline std::vector<VkSurfaceFormatKHR> queryVkSurfaceFormatKHR(VkPhysicalDevice device, VkSurfaceKHR surface);

        inline std::vector<VkPresentModeKHR> queryVkPresentModeKHR(VkPhysicalDevice device, VkSurfaceKHR surface);

        std::vector<VkQueueFamilyProperties> queryVkPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice device);
    }   

}