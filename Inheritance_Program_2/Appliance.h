#pragma once
#include <string>

class Appliance
{
//no need for private variables, all of them will be inherited
protected:
    std::string brandName;
    bool isOn;
    int powerConsumption;
    
public:

    //power functions
    bool getIsOn(){return isOn;}
    void turnOn(){isOn = true;}
    void turnOff(){isOn = false;}

    //all neccessary getters and setters
    std::string getBrandName(){return brandName;}
    int getPowerConsumption(){return powerConsumption;}
    void setPowerConsumption(int newPowerCons){powerConsumption = newPowerCons;}

    //all of the functions that need to be implemented in the children
    virtual void displayDetails() = 0;
    virtual void adjustSettings() = 0;
    virtual std::string getType() = 0;
};
