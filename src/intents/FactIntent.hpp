#ifndef FACT_INTENT_HPP
#define FACT_INTENT_HPP

#include "Intent.hpp"

class FactIntent : public Intent
{
public:
    FactIntent() : Intent(Intent::IntentType::FACT){}
    ~FactIntent() = default;
};

#endif