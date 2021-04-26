#include <iostream>

#include "StaticDataParser.hpp"

StaticDataParser::StaticDataParser(std::shared_ptr<IQueryEngine> queryEngine) :
IDataParser(queryEngine)
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

}

