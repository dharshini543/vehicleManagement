
#ifndef BIKE_FILEOPERATION_H
#define BIKE_FILEOPERATION_H

#include "Rental_Bike_Details.h"
#include <list>

class Bike_FO
{
public:
    Bike_FO();
    ~Bike_FO();

    void writeData(list<RentalBikeDetails*> bikeList);
    list<RentalBikeDetails *> readData();
};

#endif // BIKE_FILEOPERATION_H
