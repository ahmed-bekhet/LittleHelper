#include <thread>
#include <functional>
#include <unistd.h>
#include "gtest/gtest.h"

#include "StaticDataParser.hpp"
#include "stubs.hpp"

TEST(InitTest, Positive)
{
    std::stringstream fake_input;
    std::ostringstream fake_output;
    std::ostringstream fake_error;

    StaticDataParser staticDataParser(std::make_shared<StaticQueryEngine>(), fake_input, fake_output, fake_error);

    g_StaticQueryEngine_init_return = true;

    EXPECT_EQ (true, staticDataParser.init());
}

TEST(InitTest, Negative)
{
    std::stringstream fake_input;
    std::ostringstream fake_output;
    std::ostringstream fake_error;

    StaticDataParser staticDataParser(std::make_shared<StaticQueryEngine>(), fake_input, fake_output, fake_error);

    g_StaticQueryEngine_init_return = false;

    EXPECT_EQ (false, staticDataParser.init());
}


TEST(RunTest, WeatherIntent)
{
    std::stringstream fake_input;
    std::ostringstream fake_output;
    std::ostringstream fake_error;
    bool result = false;
    std::string resultString = "";

    StaticDataParser staticDataParser(std::make_shared<StaticQueryEngine>(), fake_input, fake_output, fake_error);

    std::thread parserThread = std::thread(std::bind(&StaticDataParser::run, &staticDataParser));

    g_StaticQueryEngine_getWeather_return = "Weather is good";

    fake_input << "What is the weather like today?" << std::endl;

    sleep(1);

    resultString = fake_output.str();
    result = (resultString.find("Intent: Get Weather") != std::string::npos);
    EXPECT_EQ(true, result);

    result = (resultString.find(g_StaticQueryEngine_getWeather_return) != std::string::npos);
    EXPECT_EQ(true, result);

    staticDataParser.stop();

    sleep(1);

    if(parserThread.joinable())
    {
        parserThread.join();
    }
}

TEST(RunTest, WeatherCityIntent)
{
    std::stringstream fake_input;
    std::ostringstream fake_output;
    std::ostringstream fake_error;
    bool result = false;
    std::string resultString = "";


    StaticDataParser staticDataParser(std::make_shared<StaticQueryEngine>(), fake_input, fake_output, fake_error);

    std::thread parserThread = std::thread(std::bind(&StaticDataParser::run, &staticDataParser));

    g_StaticQueryEngine_getWeatherCity_return = "Weather in Paris is good";

    fake_input << "What is the weather like in Paris today?" << std::endl;

    sleep(1);

    resultString = fake_output.str();

    result = (resultString.find("Intent: Get Weather City") != std::string::npos);
    EXPECT_EQ(true, result);

    result = (resultString.find(g_StaticQueryEngine_getWeatherCity_return) != std::string::npos);
    EXPECT_EQ(true, result);

    staticDataParser.stop();

    sleep(1);

    if(parserThread.joinable())
    {
        parserThread.join();
    }
}

TEST(RunTest, FactIntent)
{
    std::stringstream fake_input;
    std::ostringstream fake_output;
    std::ostringstream fake_error;
    bool result = false;
    std::string resultString = "";

    StaticDataParser staticDataParser(std::make_shared<StaticQueryEngine>(), fake_input, fake_output, fake_error);

    std::thread parserThread = std::thread(std::bind(&StaticDataParser::run, &staticDataParser));

    g_StaticQueryEngine_getFact_return = "Nothing interesting over here";

    fake_input << "Tell me an interesting fact." << std::endl;

    sleep(1);

    resultString = fake_output.str();

    result = (resultString.find("Intent: Get Fact") != std::string::npos);
    EXPECT_EQ(true, result);

    result = (resultString.find(g_StaticQueryEngine_getFact_return) != std::string::npos);
    EXPECT_EQ(true, result);

    staticDataParser.stop();

    sleep(1);

    if(parserThread.joinable())
    {
        parserThread.join();
    }
}

TEST(RunTest, UnknownIntent)
{
    std::stringstream fake_input;
    std::ostringstream fake_output;
    std::ostringstream fake_error;
    bool result = false;
    std::string resultString = "";

    StaticDataParser staticDataParser(std::make_shared<StaticQueryEngine>(), fake_input, fake_output, fake_error);

    std::thread parserThread = std::thread(std::bind(&StaticDataParser::run, &staticDataParser));

    fake_input << "How are you doing?" << std::endl;

    sleep(1);

    resultString = fake_error.str();

    result = (resultString.find("[ERROR] unrecognized Intent") != std::string::npos);
    EXPECT_EQ(true, result);

    staticDataParser.stop();

    sleep(1);

    if(parserThread.joinable())
    {
        parserThread.join();
    }
}


int main(int argc,char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}