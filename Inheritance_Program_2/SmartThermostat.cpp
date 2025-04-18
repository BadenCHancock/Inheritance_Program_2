#include "SmartThermostat.h"

#include <iostream>

void SmartThermostat::displayDetails()
{
    std::cout << "Smart Thermostat [" << brandName << "]" << std::endl;
    std::cout << "Status: " << (isOn ? "On" : "Off") << std::endl;
    std::cout << "Power Consumption: " << powerConsumption << " watts" << std::endl;
    std::cout << "Target Temperature: " << targetTemperature << std::endl;
    std::cout << "Current Temperature: " << curentTemperature << std::endl;
    std::cout << "Current Mode: " << mode << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void SmartThermostat::adjustSettings() {
    std::cout << "\n--- Adjusting Smart Thermostat Settings ---\n";

    int newTargetTemp;
    std::string newMode;

    std::cout << "Enter new target temperature (F): ";
    std::cin >> newTargetTemp;
    std::cin.ignore();

    std::cout << "Enter mode (cool, heat, auto): ";
    std::getline(std::cin, newMode);

    if (newMode == "cool" || newMode == "heat" || newMode == "auto") {
        targetTemperature = newTargetTemp;
        mode = newMode;
        std::cout << "Thermostat settings updated.\n";
    } else {
        std::cout << "Invalid mode. Keeping previous settings.\n";
    }
}


SmartThermostat::SmartThermostat(std::string brandName, int powerConsumption, int targetTemp, int currentTemp,
    std::string newMode)
{
    this->brandName = brandName;
    this->powerConsumption = powerConsumption;
    this->targetTemperature = targetTemp;
    this->curentTemperature = currentTemp;
    this->mode = newMode;
    isOn = false;
}

SmartThermostat::SmartThermostat(std::string brandName, int powerConsumption, int targetTemp, int currentTemp)
{
    this->brandName = brandName;
    this->powerConsumption = powerConsumption;
    this->targetTemperature = targetTemp;
    this->curentTemperature = currentTemp;
    this->mode = "auto";
    isOn = false;
}

SmartThermostat::SmartThermostat(std::string brandName, int powerConsumption)
{
    this->brandName = brandName;
    this->powerConsumption = powerConsumption;
    this->targetTemperature = 68;
    curentTemperature = 68;
    mode = "auto";
    isOn = false;
}
