
#ifndef RENTAL_VEHICLE_DETAILS_H
#define RENTAL_VEHICLE_DETAILS_H
#include <string>
using namespace std;

class RentalVehicleDetails
{
public:
    RentalVehicleDetails();
    virtual ~RentalVehicleDetails();

    virtual string getVehicleName();
    virtual void setVehicleName(string vehicleName);

    virtual string getVehicleStatus();
    virtual void setVehicleStatus(string vehicleStatus);

    virtual float getVehicleCost();
    virtual void setVehicleCost(float vehicleCost);

    virtual string getVehicleNumber();
    virtual void setVehicleNumber(string vehicleNumber);

    virtual string getVehicleModel();
    virtual void setVehicleModel(string vehicleModel);

protected:
    string m_vehicleNumber;
    string m_vehicleName;
    string m_vehicleStatus;
    string m_vehicleModel;
    float m_vehicleCost;
};


#endif // RENTAL_VEHICLE_DETAILS_H
