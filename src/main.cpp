#include <iostream>
#include "IntentManager.hpp"

int main(void)
{
    std::cout << "LittleHelper Started" << std::endl;

    IntentManager::getInstance().init();
    IntentManager::getInstance().run();

    return 0;
}