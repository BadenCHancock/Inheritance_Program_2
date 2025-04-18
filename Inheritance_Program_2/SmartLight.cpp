#include "SmartLight.h"

#include <iostream>

SmartLight::SmartLight(std::string brandName, int powerConsumption, int brightness, std::string color)
{
    this->brandName = brandName;
    this->isOn = false;
    this->powerConsumption = powerConsumption;
    this->brightness = brightness;
    this->color = color;
}

SmartLight::SmartLight(std::string brandName, int powerConsumption, int brightness)
{
    this->brandName = brandName;
    this->isOn = false;
    this->powerConsumption = powerConsumption;
    this->brightness = brightness;
    this->color = "warm";
}

SmartLight::SmartLight(std::string brandName, int powerConsumption)
{
    this->brandName = brandName;
    this->powerConsumption = powerConsumption;
    this->brightness = 100;
    this->color = "warm";
    this->isOn = false;
}
void SmartLight::displayDetails() 
{
    std::cout << "Smart Light [" << brandName << "]" << std::endl;
    std::cout << "Status: " << (isOn ? "On" : "Off") << std::endl;
    std::cout << "Power Consumption: " << powerConsumption << " watts" << std::endl;
    std::cout << "Brightness: " << brightness << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void SmartLight::adjustSettings() {
    std::cout << "\n--- Adjusting Smart Light Settings ---\n";

    int newBrightness;
    std::string newColor;

    std::cout << "Enter new brightness (0-100): ";
    std::cin >> newBrightness;
    std::cin.ignore();

    if (newBrightness >= 0 && newBrightness <= 100) {
        brightness = newBrightness;
    } else {
        std::cout << "Invalid brightness. Keeping previous value.\n";
    }

    std::cout << "Enter new color (e.g., warm white, cool white, blue): ";
    std::getline(std::cin, newColor);
    color = newColor;

    std::cout << "Smart Light settings updated.\n";
}

