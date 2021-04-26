#include <sstream>

#include "StaticQueryEngine.hpp"

bool StaticQueryEngine::init()
{
    return true;
}

std::string StaticQueryEngine::getFact()
{
    return "Hummingbirds can fly backward and forward!";
}

std::string StaticQueryEngine::getWeather()
{
    return "The Weather today is 18°C";
}

std::string StaticQueryEngine::getWeatherCity(City city)
{
    std::stringstream ss;

    ss << "The Weather in " << Mapper::to_string(city) << " 18°C";

    return ss.str();
}