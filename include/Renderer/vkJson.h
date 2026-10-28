#pragma once 
#include "json.h"
#include "vulkan/vulkan.h"


void from_json(const core::json& j, VkApplicationInfo& info);
void from_json(const core::json& j, VkInstanceCreateInfo& info);
void from_json(const core::json& j, VkDeviceCreateInfo& info);
void from_json(const core::json& j, VkValidationFeaturesEXT& info);
void from_json(const core::json& j, VkDebugUtilsMessengerCreateInfoEXT& info);
void from_json(const core::json& j, VkSwapchainCreateInfoKHR& info);
