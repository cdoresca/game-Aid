#pragma once

#include "vkContext.h"
#include <optional>
#include <vector>

/**
 * @brief 
 * Le struct QueueFamiliesIndices garde les indices des queues
 */
namespace renderer{

	struct QueueFamiliesIndices {
		std::optional<uint32_t> graphicFamily;
		std::optional<uint32_t> presentFamily;
		std::optional<uint32_t> computeFamily;
		std::optional<uint32_t> transfertFamily;
		uint32_t count;
		
		bool isComplete();
	};



	std::vector<QueueFamiliesIndices> findQueueFamilies(VkContext ctx);
}