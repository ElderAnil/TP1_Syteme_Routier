#ifndef Vehicle_H
#define Vehicle_H
#include <string>

class Vehicle
{

private:
    std::string id;
    std::string type;
    
    std::string destination;

public:
    Vehicle();
    Vehicle(std::string, std::string, std::string);
    void IncreaseWaitTime();
    void Display() const;

    int waitTime;

};


#endif