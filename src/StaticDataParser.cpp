#include <iostream>
#include <string>

#include "StaticDataParser.hpp"

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
    if(!m_queryEngine->init())
    {
        m_error << "Failed to Initialize Query Engine..." << std::endl;

        return false;
    }

    return true;
}

void StaticDataParser::run()
{
    std::string userData;
    std::shared_ptr<Intent> userIntent;

    m_stopSignal.store(false);

    while(!m_stopSignal)
    {
        m_output << "Please Enter Your Query:" << std::endl;
        std::getline(m_input, userData);

        if(!userData.empty())
        {
            m_output << "[DEBUG] Inserted Query : " << userData << std::endl;

            userIntent = parseData(userData);
            userData.erase();

            handleIntent(userIntent);
        }
    }
}

std::shared_ptr<Intent> StaticDataParser::parseData(std::string data) const
{
    for(auto& [query, intent] : m_staticQueries)
    {
        if(!query.compare(data))
        {
            //user data matches the query
            switch(intent)
            {
                case Intent::IntentType::WEATHER:
                {
                    return std::make_shared<WeatherIntent>();
                }
                case Intent::IntentType::WEATHER_CITY:
                {
                    return std::make_shared<WeatherCityIntent>(City::Paris);
                }
                case Intent::IntentType::FACT:
                {
                    return std::make_shared<FactIntent>();
                }
            }
        }
    }

    return std::make_shared<Intent>(Intent::IntentType::UNKNOWN);
}

void StaticDataParser::handleIntent(std::shared_ptr<Intent> intent) const
{
    switch(intent->getIntentType())
    {
        case Intent::IntentType::WEATHER:
        {
            m_output << "Intent: Get Weather" << std::endl;
            m_output << m_queryEngine->getWeather() << std::endl;
        }
        break;
        case Intent::IntentType::WEATHER_CITY:
        {
            std::shared_ptr<WeatherCityIntent> weatherCityIntent = std::dynamic_pointer_cast<WeatherCityIntent>(intent);

            if(weatherCityIntent)
            {
                m_output << "Intent: Get Weather City" << std::endl;
                m_output << m_queryEngine->getWeatherCity(weatherCityIntent->getCity()) << std::endl;
            }
            else
            {
                m_error << "[ERROR] Failed to extract City info from Intent Object" << std::endl;
            }

        }
        break;
        case Intent::IntentType::FACT:
        {
            m_output << "Intent: Get Fact" << std::endl;
            m_output << m_queryEngine->getFact() << std::endl;
        }
        break;
        case Intent::IntentType::UNKNOWN:
        default:
        {
            m_error << "[ERROR] unrecognized Intent" << std::endl;
        }
        break;
    }
}