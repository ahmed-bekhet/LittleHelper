#ifndef COMMON_HPP
#define COMMON_HPP

#include "stdint.h"

enum class City : uint8_t
{
    Paris = 0,
    Tokyo = 1,
    Jakarta = 2,
    Manila = 3,
    Shanghai = 4,
    Karachi = 5,
    Beijing = 6,
    NewYork = 7,
    SaoPaulo = 8,
    MexicoCity = 9,
    Moscow = 10,
    Cairo = 11,
    Dhaka = 12,
    LosAngeles = 13,
    Bangkok = 14
};

class Mapper
{
public:
    Mapper() = delete;
    Mapper(const Mapper&) = delete;
    Mapper(Mapper&&) = delete;
    ~Mapper() = delete;

    static std::string to_string(City city)
    {
        switch(city)
        {
            case City::Paris:
                return "Paris";
            case City::Tokyo:
                return "Tokyo";
            case City::Jakarta:
                return "Jakarta";
            case City::Manila:
                return "Manila";
            case City::Shanghai:
                return "Shanghai";
            case City::Karachi:
                return "Karachi";
            case City::Beijing:
                return "Beijing";
            case City::NewYork:
                return "NewYork";
            case City::SaoPaulo:
                return "SaoPaulo";
            case City::MexicoCity:
                return "MexicoCity";
            case City::Moscow:
                return "Moscow";
            case City::Cairo:
                return "Cairo";
            case City::Dhaka:
                return "Dhaka";
            case City::LosAngeles:
                return "LosAngeles";
            case City::Bangkok:
                return "Bangkok";
            default:
                return "Unknown";
        }
    }
};

#endif