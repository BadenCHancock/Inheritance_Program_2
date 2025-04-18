
#include <algorithm>
#include <iostream>
#include <vector>

#include "Appliance.h"
#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SmartTV.h"



void printDevices(const std::vector<Appliance*> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list.at(i)->getBrandName() + " " << list.at(i)->getType() << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::vector<Appliance*> applianceList;
    std::string command;
    while (command != "exit")
    {

        if (applianceList.size() == 0)
        {
            std::cout << "add a device" << std::endl;
        }
        else
        {
            std::cout << "select a device" << std::endl;
            printDevices(applianceList);
        }
        std::cin >> command;
        std::cin.ignore();
        
        if (applianceList.size() == 0 || command == "add")
        {
           std::cout << "Please enter what type of device you would like" << std::endl;
            std::cin >> command;
            std::cin.ignore();
            if (command == "tv"|| command == "light" || command == "thermostat")
            {
                if (command == "tv")
                {
                    std::string brand;
                    int powerConsump;
                    std::string resolution;

                    std::cout << "What is your device's brand: ";
                    std::getline(std::cin, brand);

                    std::cout << "What is your device's power consumption (in watts): ";
                    std::cin >> powerConsump;
                    std::cin.ignore();  

                    std::cout << "What is your TV's resolution (e.g., 1080p, 4K): ";
                    std::cin >> resolution;
                    std::cin.ignore();

                    applianceList.push_back(new SmartTV(brand, powerConsump, resolution));
                    std::cout << "Smart TV added successfully!\n";
                }
                else if (command == "light") {
                    std::string brand;
                    std::string color;
                    int powerConsump;
                    int brightness;

                    std::cout << "What is your device's brand: ";
                    std::getline(std::cin, brand);

                    std::cout << "What is your device's power consumption (in watts): ";
                    std::cin >> powerConsump;
                    std::cin.ignore();  

                    std::cout << "Brightness (0-100): ";
                    std::cin >> brightness;
                    std::cin.ignore();

                    std::cout << "What is your light's color (eg. cool white, warm white, blue): ";
                    std::getline(std::cin, color);

                    applianceList.push_back(new SmartLight(brand, powerConsump, brightness, color));
                    std::cout << "Smart Light added!\n";
                }

                else if (command == "thermostat") {
                    std::string brand;
                    std::string mode;
                    int power;
                    int currentTemp;
                    int targetTemp;

                    std::cout << "What is your device's brand: ";
                    std::getline(std::cin, brand);

                    std::cout << "What is your device's power consumption (in watts): ";
                    std::cin >> power;
                    std::cin.ignore();  

                    std::cout << "Current Temperature (F): ";
                    std::cin >> currentTemp;
                    std::cin.ignore();

                    std::cout << "Target Temperature (F): ";
                    std::cin >> targetTemp;
                    std::cin.ignore();

                    std::cout << "Mode (cool, heat, auto): ";
                    std::cin >> mode;
                    std::cin.ignore();

                    applianceList.push_back(new SmartThermostat(brand, power, currentTemp, targetTemp, mode));
                    std::cout << "Smart Thermostat added!\n";
                }

                else {
                    std::cout << "Unknown device type.\n";
                }
            }
        }
        
        
        else if (command == "help")
        {
            std::cout << "enter the number in the list of which the device you want to select starting at 0" << std::endl;
        }
        else
        {
            try
            {
                int index = std::stoi(command);
                if (index >= 0 && index < applianceList.size())
                {
                    applianceList.at(index)->displayDetails();
                    std::cout << "type adjust to adjust the settings?" << std::endl;
                    std::cout << "type switch to turn device on/off" << std::endl;
                    std::cin >> command;
                    std::cin.ignore();
                    if (command == "adjust")
                    {
                        applianceList[index]->adjustSettings();   
                    }
                    else if (command == "switch")
                    {
                        if (applianceList.at(index)->getIsOn())
                        {
                            applianceList.at(index)->turnOff();
                            std::cout << applianceList.at(index)->getBrandName() + " " + applianceList.at(index)->getType() + " is turned off" << std::endl;
                        }
                        else
                        {
                            applianceList.at(index)->turnOn();
                            std::cout << applianceList.at(index)->getBrandName() + " " + applianceList.at(index)->getType() + " is turned on" << std::endl;
                        }
                    }
                }
                else
                {
                    std::cout << "wrong command." << std::endl;
                }
            
            }
            catch (const std::invalid_argument& e)
            {
            
            }
        }
        std::cout << "----------------------" << std::endl;
    }
    return 0;
}

