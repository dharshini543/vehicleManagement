
#ifndef RENTAL_BIKE_DETAILS_H
#define RENTAL_BIKE_DETAILS_H

#include "Rental_Vehicle_Details.h"

class RentalBikeDetails:public RentalVehicleDetails
{
public:
    RentalBikeDetails();
    RentalBikeDetails(string bikeName, string bikeModel, string bikeNumber, float bikeCost, string bikeStatus);
    ~RentalBikeDetails();

    string getVehicleName();
    void setVehicleName(string vehicleName);

    string getVehicleStatus();
    void setVehicleStatus(string vehicleStatus);

    float getVehicleCost();
    void setVehicleCost(float vehicleCost);

    string getVehicleNumber();
    void setVehicleNumber(string vehicleNumber);

    string getVehicleModel();
    void setVehicleModel(string vehicleModel);
};

#endif // RENTAL_BIKE_DETAILS_H
