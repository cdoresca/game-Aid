#pragma once
#include "vulkan/vulkan.h"

namespace renderer{

    struct Pipeline{
        VkPipelineLayout layout;
        VkPipeline pipeline;
    };
}