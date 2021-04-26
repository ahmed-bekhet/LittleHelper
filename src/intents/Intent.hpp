#ifndef INTENT_HPP
#define INTENT_HPP

#include <cstdint>
#include <string>

class Intent
{
public:

    enum class IntentType : uint8_t
    {
        WEATHER = 0,
        WEATHER_CITY = 1,
        FACT = 2,
        UNKNOWN = 255
    };

    Intent(IntentType intentType) : m_intentType(intentType){};
    virtual ~Intent() = default;

    IntentType getIntentType()
    {
        return m_intentType;
    }

    std::string to_string()
    {
        switch(m_intentType)
        {
        case IntentType::WEATHER:
            return "Weather";
        case IntentType::WEATHER_CITY:
            return "Weather City";
        case IntentType::FACT:
            return "Fact";
        case IntentType::UNKNOWN:
        default:
            return "Unknown";
        }
    }

private:
    IntentType m_intentType;

};

#endif