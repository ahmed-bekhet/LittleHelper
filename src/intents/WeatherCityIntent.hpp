#ifndef WEATHER_CITY_INTENT_HPP
#define WEATHER_CITY_INTENT_HPP

#include "common.hpp"
#include "Intent.hpp"

class WeatherCityIntent : public Intent
{
public:
    WeatherCityIntent(City city) : Intent(Intent::IntentType::WEATHER_CITY), m_city(city){}
    ~WeatherCityIntent() = default;

    City getCity()
    {
        return m_city;
    }

private:
    City m_city;
};

#endif