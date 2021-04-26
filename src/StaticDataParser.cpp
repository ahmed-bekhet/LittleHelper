#include <iostream>
#include <string>

#include "StaticDataParser.hpp"

StaticDataParser::StaticDataParser(std::shared_ptr<IQueryEngine> queryEngine) :
IDataParser(queryEngine),
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
        std::cerr << "Failed to Initialize Query Engine..." << std::endl;

        return false;
    }

    return true;
}

void StaticDataParser::run()
{
    std::string userData;
    std::shared_ptr<Intent> userIntent;
    while(1)
    {
        std::cout << "Please Enter Your Query:" << std::endl;
        std::getline(std::cin, userData);

        if(!userData.empty())
        {
            std::cout << "[DEBUG] Inserted Query : " << userData << std::endl;

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
            std::cout << "Intent: Get Weather" << std::endl;
            std::cout << m_queryEngine->getWeather() << std::endl;
        }
        break;
        case Intent::IntentType::WEATHER_CITY:
        {
            std::shared_ptr<WeatherCityIntent> weatherCityIntent = std::dynamic_pointer_cast<WeatherCityIntent>(intent);

            if(weatherCityIntent)
            {
                std::cout << "Intent: Get Weather City" << std::endl;
                std::cout << m_queryEngine->getWeatherCity(weatherCityIntent->getCity()) << std::endl;
            }
            else
            {
                std::cerr << "[ERROR] Failed to extract City info from Intent Object" << std::endl;
            }

        }
        break;
        case Intent::IntentType::FACT:
        {
            std::cout << m_queryEngine->getFact() << std::endl;
        }
        break;
        case Intent::IntentType::UNKNOWN:
        default:
        {
            std::cerr << "[ERROR] unrecognized Intent" << std::endl;
        }
        break;
    }
}