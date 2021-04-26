#ifndef IDATA_PARSER_HPP
#define IDATA_PARSER_HPP

#include <memory>
#include "IQueryEngine.hpp"

class IDataParser
{
public:
    IDataParser(std::shared_ptr<IQueryEngine> queryEngine) : m_queryEngine(queryEngine){}
    ~IDataParser() = default;

    virtual bool init() = 0;
    virtual void run() = 0;

protected:
    std::shared_ptr<IQueryEngine> m_queryEngine;
};

#endif