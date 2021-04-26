#include <iostream>

#include "IntentManager.hpp"

IntentManager IntentManager::m_intentManager;

IntentManager::IntentManager() :
m_staticQueryEngine(std::make_shared<StaticQueryEngine>()),
m_staticDataParser(std::make_unique<StaticDataParser>(m_staticQueryEngine))
{}

IntentManager::~IntentManager()
{}

bool IntentManager::init()
{
    if(!m_staticDataParser->init())
    {
        std::cerr << "Failed to initialize Data Parser..." << std::endl;

        return false;
    }

    return true;
}

void IntentManager::run()
{
    m_staticDataParser->run();
}