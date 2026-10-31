#include "vkQuery.h"
#include "asserts.h"
#include <GLFW/glfw3.h>

namespace renderer{

    namespace vkQuery{

        std::vector<VkExtensionProperties> queryvkEnumerateInstanceExtensionProperties( const char* pLayerName){
            uint32_t count;
            VK_CHECK(vkEnumerateInstanceExtensionProperties(pLayerName, &count, nullptr));
            std::vector<VkExtensionProperties> extensions(count);
            VK_CHECK(vkEnumerateInstanceExtensionProperties(pLayerName, &count, extensions.data()));
            return extensions;
        }


        std::vector<VkExtensionProperties> queryVkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName){
            uint32_t count;
            VK_CHECK(vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, &count, nullptr));
            std::vector<VkExtensionProperties> extensions(count);
            VK_CHECK(vkEnumerateDeviceExtensionProperties(physicalDevice,pLayerName, &count, extensions.data()));
            return extensions;
        }

        std::vector<VkPhysicalDevice> queryVkEnumeratePhysicalDevices(VkInstance instance){
            uint32_t count;
            VK_CHECK(vkEnumeratePhysicalDevices(instance, &count, nullptr));
            std::vector<VkPhysicalDevice> gpu(count);
            VK_CHECK(vkEnumeratePhysicalDevices(instance,&count,gpu.data()));
            return gpu;
        }

        std::vector<VkImage> queryVkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapChain){
            uint32_t count;
            VK_CHECK(vkGetSwapchainImagesKHR(device, swapChain, &count, nullptr));
            std::vector<VkImage> swapChainImages(count);
            VK_CHECK(vkGetSwapchainImagesKHR(device, swapChain, &count, swapChainImages.data()));
            return swapChainImages;
        }

        uint32_t findMemoryType(VkPhysicalDevice physical, uint32_t typeFilter, VkMemoryPropertyFlags properties){
            VkPhysicalDeviceMemoryProperties memProperties;
            vkGetPhysicalDeviceMemoryProperties(physical, &memProperties);

            for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
                if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
                    return i;
                }
            }

            throw std::runtime_error("failed to find suitable memory type!");
        }

        std::vector<const char*> queryExtensionInstance()
        {
            uint32_t glfwExtensionCount = 0;
            const char** glfwExtension;
            glfwExtension = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            std::vector<const char*> extensions(glfwExtension, glfwExtensionCount + glfwExtension);

            if (enableValidationLayers) {
                extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
                extensions.push_back(VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME);
            }

            return extensions;
        }

        VkSurfaceCapabilitiesKHR queryVkSurfaceCapabilitiesKHR(VkPhysicalDevice device, VkSurfaceKHR surface){
            VkSurfaceCapabilitiesKHR capabilities;
            vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &capabilities);
            return capabilities;
        }

        std::vector<VkSurfaceFormatKHR> queryVkSurfaceFormatKHR(VkPhysicalDevice device, VkSurfaceKHR surface){
            uint32_t count;
	        vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &count, nullptr);
            std::vector<VkSurfaceFormatKHR> format(count);
	        vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &count, format.data());
            return format;
        }

        std::vector<VkPresentModeKHR> queryVkPresentModeKHR(VkPhysicalDevice device, VkSurfaceKHR surface){
            uint32_t count;
            vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &count, nullptr);
            std::vector<VkPresentModeKHR> present(count);
            vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &count, present.data());
            return present;
        }

        std::vector<VkQueueFamilyProperties> queryVkPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice device){
            uint32_t cpt;
            vkGetPhysicalDeviceQueueFamilyProperties(device, &cpt, nullptr);
            std::vector<VkQueueFamilyProperties>family(cpt);
            vkGetPhysicalDeviceQueueFamilyProperties(device, &cpt, family.data());
            return family;
        }

        std::vector<const char *> queryRequieredExtensionInstance()
        {
            uint32_t glfwExtensionCount = 0;
            const char** glfwExtension;
            glfwExtension = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            std::vector<const char*> extensions(glfwExtension, glfwExtensionCount + glfwExtension);

            if (enableValidationLayers) {
                extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
                extensions.push_back(VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME);
            }

            return extensions;
        }

    }
}