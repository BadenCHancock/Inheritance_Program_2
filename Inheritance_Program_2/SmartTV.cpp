#include "SmartTV.h"

#include <iostream>
#include <ostream>

void SmartTV::displayDetails() 
{
    std::cout << "Smart TV [" << brandName << "]" << std::endl;
    std::cout << "Status: " << (isOn ? "On" : "Off") << std::endl;
    std::cout << "Power Consumption: " << powerConsumption << " watts" << std::endl;
    std::cout << "Volume: " << volume << std::endl;
    std::cout << "Resolution: " << resolution << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void SmartTV::adjustSettings() {
    int newVolume;
    std::string newResolution;

    std::cout << "Enter new volume (0-30): ";
    std::cin >> newVolume;
    std::cin.ignore();

    std::cout << "Enter new resolution (e.g., 1080p, 4K): ";
    std::getline(std::cin, newResolution);

    if (newVolume >= 0 && newVolume <= 30) {
        volume = newVolume;
    } else {
        std::cout << "Invalid volume. Keeping previous value.\n";
    }

    resolution = newResolution;
    std::cout << "Smart TV settings updated.\n";
}

SmartTV::SmartTV(std::string brandName, int powerConsumption, std::string resolution)
{
    this->brandName = brandName;
    this->powerConsumption = powerConsumption;
    this->resolution = resolution;
    volume = 0;
    isOn = false;
}

SmartTV::SmartTV(std::string brandName, int powerConsumption)
{
    this->brandName = brandName;
    this->powerConsumption = powerConsumption;
    volume = 0;
    isOn = false;
    resolution = "4K";
    //defaults res to 4K
}
