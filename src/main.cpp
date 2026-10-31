#include "vkJson.h"
#include "json.h"
#include "vkInit.h"

int main(){

    core::json j  = core::getJson("vulkanContextConfig.json");
    renderer::VkContext ctx;
    renderer::createInstance(j, ctx);
    
    return 0;
}
