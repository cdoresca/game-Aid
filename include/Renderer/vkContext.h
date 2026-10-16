#pragma once
#include "vulkan/vulkan.h"


namespace renderer{ 

struct VkContext
{
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkQueue computeQueue;

    VkDebugUtilsMessengerEXT debugMessenger;
};


void destroyVkContext(VkContext ctx);

}