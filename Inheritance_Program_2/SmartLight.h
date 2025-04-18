#pragma once
#include "Appliance.h"

class SmartLight : public Appliance
{
private:
    int brightness;
    std::string color;
    
    public:

    std::string getType()override {return "SmartLight";}
    int getBrightness();
    std::string getColor();

    //will always default to off
    SmartLight(std::string brandName, int powerConsumption, int brightness, std::string color);
    SmartLight(std::string brandName, int powerConsumption, int brightness);
    SmartLight(std::string brandName, int powerConsumption);

    void displayDetails() override;
    void adjustSettings() override;
public:
    
};
