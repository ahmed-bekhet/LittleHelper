#ifndef STUBS_HPP
#define STUBS_HPP

#include "StaticQueryEngine.hpp"

bool g_StaticQueryEngine_init_return = false;
std::string g_StaticQueryEngine_getFact_return = "";
std::string g_StaticQueryEngine_getWeather_return = "";
std::string g_StaticQueryEngine_getWeatherCity_return = "";

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

#endif