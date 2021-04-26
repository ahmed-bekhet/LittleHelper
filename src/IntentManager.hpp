#ifndef INTENT_MANAGER_HPP
#define INTENT_MANAGER_HPP

#include <memory>

#include "StaticDataParser.hpp"
#include "StaticQueryEngine.hpp"

class IntentManager
{
public:
    static IntentManager& getInstance()
    {
        return m_intentManager;
    }

    bool init();

    void run();

private:
    IntentManager();
    ~IntentManager();

    static IntentManager m_intentManager;
    std::shared_ptr<StaticQueryEngine> m_staticQueryEngine;
    std::unique_ptr<StaticDataParser> m_staticDataParser;
};

#endif