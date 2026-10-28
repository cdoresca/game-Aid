#pragma once
#include "json.h"
#include "vkContext.h"
#include "window.h"

namespace renderer{

    void createInstance(const core::json& j,VkContext& ctx);
    void createSurface(VkContext ctx,window window_);
    std::vector<VkPhysicalDevice> choosePhysicalDevice(const core::json& j, VkContext& ctx);
    void createDevice(const core::json& j, VkContext& ctx);
}