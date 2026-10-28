#pragma once
#include "vkContext.h"
#include <vector>
#include <GLFW/glfw3.h>
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

	bool verifySwapSurfaceFormat(VkSurfaceFormatKHR format);
	
	bool verifySwapPresentMode(VkPresentModeKHR availablePresentModes);
	VkExtent2D chooseSwapExtent(GLFWwindow* window);
};

SwapChainSupportDetails querySwapChainSupport(VkContext ctx);



}