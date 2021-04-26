#ifndef STATIC_DATA_PARSER_HPP
#define STATIC_DATA_PARSER_HPP

#include <map>

#include "IDataParser.hpp"
#include "intents/FactIntent.hpp"
#include "intents/WeatherIntent.hpp"
#include "intents/WeatherCityIntent.hpp"

class StaticDataParser : public IDataParser
{
public:
    StaticDataParser(std::shared_ptr<IQueryEngine> queryEngine);
    ~StaticDataParser() = default;

    bool init() override;
    void run() override;

private:
    void startReceivingData();
    std::shared_ptr<Intent> parseData(std::string data) const;
    void handleIntent(std::shared_ptr<Intent> intent) const;

    const std::map<std::string, Intent::IntentType> m_staticQueries;
};

#endif