#ifndef IQUERY_ENGINE_HPP
#define IQUERY_ENGINE_HPP

#include <string>

#include "common.hpp"

class IQueryEngine
{
public:
    IQueryEngine() = default;
    ~IQueryEngine() = default;

    virtual bool init() = 0;
    virtual std::string getWeather() = 0;
    virtual std::string getWeatherCity(City city) = 0;
    virtual std::string getFact() = 0;
};

#endif