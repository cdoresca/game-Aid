#include <gtest/gtest.h>
#include "vkJson.h"
#include "json.h"
#include "vkInit.h"

namespace Test{
    class VkJsonTest : public ::testing::Test{
        protected:
        core::json j;
        renderer::VkContext ctx;

        void SetUp() override{
            j  = core::getJson("");
            EXPECT_EQ(j,nullptr);
        }

        void TearDown() override{ renderer::destroyVkContext(ctx);}
    };

    TEST_F(VkJsonTest, instance){
        renderer::createInstance(j, ctx);
        EXPECT_NE(ctx.instance, nullptr);
    }
}