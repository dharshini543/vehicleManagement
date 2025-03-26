
#ifndef RENTAL_CAR_DETAILS_H
#define RENTAL_CAR_DETAILS_H

#include "Rental_Vehicle_Details.h"

class RentalCarDetails:public RentalVehicleDetails
{

public:
    RentalCarDetails();
    RentalCarDetails(string carName, string carModel, string carNumber, float carCost, string carStatus);
    ~RentalCarDetails();

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

#endif // RENTAL_CAR_DETAILS_H
