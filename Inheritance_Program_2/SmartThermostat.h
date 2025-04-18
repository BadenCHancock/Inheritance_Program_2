#pragma once
#include <string>

#include "Appliance.h"

class SmartThermostat: public Appliance
{
public:
    std::string getType()override{return "Smart Thermostat";}
    void displayDetails() override;
    void adjustSettings() override;

    SmartThermostat(std::string brandName, int powerConsumption, int targetTemp, int currentTemp, std::string newMode);
    SmartThermostat(std::string brandName, int powerConsumption, int targetTemp, int currentTemp);
    SmartThermostat(std::string brandName, int powerConsumption);

private:
    int targetTemperature;
    int curentTemperature;
    std::string mode;
};
