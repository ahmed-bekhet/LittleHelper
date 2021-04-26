#ifndef STATIC_DATA_PARSER_HPP
#define STATIC_DATA_PARSER_HPP

#include "IDataParser.hpp"

class StaticDataParser : public IDataParser
{
public:
    StaticDataParser(std::shared_ptr<IQueryEngine> queryEngine);
    ~StaticDataParser() = default;

    bool init() override;
    void run() override;

private:
};

#endif