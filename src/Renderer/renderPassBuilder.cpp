#include "renderPassBuilder.h"
#include "vkFunction.h"
#include "swapChainSupportDetail.h"
#include "vkUtils.h"

namespace renderer
{

    renderPassBuilder::renderPassBuilder(VkContext ctx) : ctx(ctx)
    {
        SwapChainSupportDetails swapChainSupport = querySwapChainSupport(ctx.physicalDevice, ctx.surface);

        VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
        description = { vkFct::getVkAttachmentDescription(surfaceFormat.format) };
        reference = {vkFct::getVkAttachmentReference(0)};
        subpass = {vkFct::getVkSubpassDescription(VK_PIPELINE_BIND_POINT_GRAPHICS, reference.size(),reference.data())};

    }
    renderPassBuilder::renderPassBuilder(VkContext ctx, std::vector<VkAttachmentDescription> description, std::vector<VkAttachmentReference> reference, std::vector<VkSubpassDescription> subpass) : description(description), reference(reference), subpass(subpass) {}

    void renderPassBuilder::reset(){
        vkDestroyRenderPass(ctx.device, renderPass, nullptr);
    }

    void renderPassBuilder::build(){
        VkRenderPassCreateInfo renderPassInfo = vkFct::getVkRenderPassCreateInfo(description.size(),description.data(),subpass.size(),subpass.data(),0,nullptr);
        VK_CHECK(vkCreateRenderPass(ctx.device, &renderPassInfo, nullptr, &renderPass));
    }

    VkRenderPass renderPassBuilder::get(){
        return renderPass;
    }
}
