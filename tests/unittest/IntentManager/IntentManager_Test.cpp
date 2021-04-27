#include "gtest/gtest.h"
#include "IntentManager.hpp"
#include "stubs.hpp"

TEST(InitTest, Positive)
{
    g_StaticDataParser_init_return = true;

    EXPECT_EQ (true, IntentManager::getInstance().init());
}

TEST(InitTest, Negative)
{
    g_StaticDataParser_init_return = false;

    EXPECT_EQ (false, IntentManager::getInstance().init());
}


TEST(RunTest, Positive)
{
    EXPECT_NO_THROW (IntentManager::getInstance().run());
}

int main(int argc,char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}