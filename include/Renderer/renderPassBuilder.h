#pragma once
#include "vkContext.h"
#include "../IBuilder.h"
#include <vector>
namespace renderer{

class renderPassBuilder: public IBuilder<VkRenderPass>{

    public:
        renderPassBuilder(VkContext ctx);
        renderPassBuilder(VkContext ctx, std::vector<VkAttachmentDescription> description, std::vector<VkAttachmentReference> reference, std::vector<VkSubpassDescription> subpass);

        void reset() override;
        void build() override;

        VkRenderPass get() override;

    private:
        VkContext ctx;
        VkRenderPass renderPass;

        std::vector<VkAttachmentDescription> description;
        std::vector<VkAttachmentReference> reference;
        std::vector<VkSubpassDescription> subpass;
};

}