#pragma once
#include "vkContext.h"
#include <vector>

namespace renderer{
/**
 * @brief 
 * Le struct SwapChainSupportDetails garde les propriétés du swap chain.
 * 
 */
struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentsModes;
};

SwapChainSupportDetails querySwapChainSupport(VkContext ctx);

/*
VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormat);

VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);
*/
}