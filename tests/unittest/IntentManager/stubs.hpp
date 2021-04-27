#ifndef STUBS_HPP
#define STUBS_HPP

#include "StaticQueryEngine.hpp"
#include "StaticDataParser.hpp"

bool g_StaticQueryEngine_init_return = false;
std::string g_StaticQueryEngine_getFact_return = "";
std::string g_StaticQueryEngine_getWeather_return = "";
std::string g_StaticQueryEngine_getWeatherCity_return = "";

bool g_StaticDataParser_init_return = false;


bool StaticQueryEngine::init()
{
    return g_StaticQueryEngine_init_return;
}

std::string StaticQueryEngine::getFact()
{
    return g_StaticQueryEngine_getFact_return;
}

std::string StaticQueryEngine::getWeather()
{
    return g_StaticQueryEngine_getWeather_return;
}

std::string StaticQueryEngine::getWeatherCity(City city)
{
    return g_StaticQueryEngine_getWeatherCity_return;
}

StaticDataParser::StaticDataParser(std::shared_ptr<IQueryEngine> queryEngine, std::istream& input,  std::ostream& output, std::ostream& error) :
IDataParser(queryEngine, input, output, error),
m_staticQueries{
    {"What is the weather like today?", Intent::IntentType::WEATHER},
    {"What is the weather like in Paris today?", Intent::IntentType::WEATHER_CITY},
    {"Tell me an interesting fact.", Intent::IntentType::FACT}
}
{
}

bool StaticDataParser::init()
{
    return g_StaticDataParser_init_return;
}

void StaticDataParser::run()
{
}

#endif