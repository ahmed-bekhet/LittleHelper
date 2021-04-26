#ifndef WEATHER_INTENT_HPP
#define WEATHER_INTENT_HPP

#include "Intent.hpp"

class WeatherIntent : public Intent
{
public:
    WeatherIntent() : Intent(Intent::IntentType::WEATHER){}
    ~WeatherIntent() = default;
};

#endif