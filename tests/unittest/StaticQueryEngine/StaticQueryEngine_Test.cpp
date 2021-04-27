#include "gtest/gtest.h"
#include "StaticQueryEngine.hpp"

TEST(InitTest, Positive)
{
    StaticQueryEngine staticQueryEngine;
    EXPECT_EQ (true, staticQueryEngine.init());
}

TEST(GetWeatherTest, Positive)
{
    StaticQueryEngine staticQueryEngine;
    EXPECT_EQ ("The Weather today is 18°C", staticQueryEngine.getWeather());
}

TEST(GetWeatherCityTest, Positive)
{
    StaticQueryEngine staticQueryEngine;
    EXPECT_EQ ("The Weather in Dhaka 18°C", staticQueryEngine.getWeatherCity(City::Dhaka));
}

TEST(GetFactTest, Positive)
{
    StaticQueryEngine staticQueryEngine;
    EXPECT_EQ ("Hummingbirds can fly backward and forward!", staticQueryEngine.getFact());
}

int main(int argc,char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}