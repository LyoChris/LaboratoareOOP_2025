#pragma once

#include <cstring>


class Car {
protected:
    char* name;
    float fuel_capacity, fuel_consumption, avg_speed[3];

public:
    virtual ~Car() {};

    virtual float Get_Speed(int weather) const = 0;
    virtual float Get_Fuel_Consumption() const = 0;
    virtual float Get_Fuel_Capacity() const= 0;
    virtual char* Get_Name() const = 0;

};