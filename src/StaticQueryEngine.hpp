#ifndef STATIC_QUERY_ENGINE_HPP
#define STATIC_QUERY_ENGINE_HPP

#include "IQueryEngine.hpp"

class StaticQueryEngine : public IQueryEngine
{
public:
    StaticQueryEngine() = default;
    ~StaticQueryEngine() = default;

    bool init() override;
    std::string getWeather() override;
    std::string getWeatherCity(City city) override;
    std::string getFact() override;
};

#endif