#ifndef Vehicle_H
#define Vehicle_H
#include <string>

class Vehicle
{

private:
    std::string id;
    std::string type;
    int waitTime;
    std::string destination;

public:
    void InitVehicle(std::string, std::string, int, std::string);
    void IncreaseWaitTime(int);
    void Display() const;

};


#endif