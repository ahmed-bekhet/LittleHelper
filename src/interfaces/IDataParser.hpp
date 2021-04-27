#ifndef IDATA_PARSER_HPP
#define IDATA_PARSER_HPP

#include <memory>
#include <iostream>
#include <atomic>

#include "IQueryEngine.hpp"

class IDataParser
{
public:
    IDataParser(std::shared_ptr<IQueryEngine> queryEngine, std::istream& input,  std::ostream& output, std::ostream& error) :
    m_queryEngine(queryEngine),
    m_input(input),
    m_output(output),
    m_error(error),
    m_stopSignal(false)
    {}

    ~IDataParser() = default;

    virtual bool init() = 0;
    virtual void run() = 0;
    virtual void stop()
    {
        m_stopSignal.store(true);
    }

protected:
    std::shared_ptr<IQueryEngine> m_queryEngine;
    std::istream& m_input;
    std::ostream& m_output;
    std::ostream& m_error;

    std::atomic<bool> m_stopSignal;

};

#endif