#include "shader.h"
#include "vkFunction.h"
#include "file.h"
#include "vkUtils.h"


namespace renderer
{
    shader::shader(VkContext context,const char* path, VkShaderStageFlagBits stage): stage(stage){
        core::file f(path);
        std::vector<char> data = f.readAll();
        VkShaderModuleCreateInfo info  = vkFct::getVkShaderModuleCreateInfo(data.size(), reinterpret_cast<const uint32_t*>(data.data()));
        VK_CHECK(vkCreateShaderModule(ctx.device, &info, nullptr, &shaderModule));
    }

    shader::~shader(){
        vkDestroyShaderModule(ctx.device, shaderModule, nullptr);
    }
} // namespace renderer
