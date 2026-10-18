#pragma once
#include "vkContext.h"

namespace renderer{

    class shader{
        public:
            shader(VkContext context,const char* path, VkShaderStageFlagBits stage);
            ~shader();
        private:
            VkContext ctx;
            VkShaderModule shaderModule;
            VkShaderStageFlagBits stage;
    };
}