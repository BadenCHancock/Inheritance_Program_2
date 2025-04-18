#pragma once
#include <string>

#include "Appliance.h"

class SmartTV : public Appliance
{
public:
    std::string getType()override {return "Smart TV";}
    void displayDetails() override;
    void adjustSettings() override;

    //volume will always be 0 at default
    SmartTV(std::string brandName, int powerConsumption, std::string resolution);
    SmartTV(std::string brandName, int powerConsumption);
private:
    int volume;
    std::string resolution;
    
};
