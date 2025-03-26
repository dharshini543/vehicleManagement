
#include "Rental_Vehicle_Details.h"
#include <iostream>

RentalVehicleDetails::RentalVehicleDetails()
{
    cout<<"Vehicle Constructor"<<endl;
}

RentalVehicleDetails::~RentalVehicleDetails()
{
    cout<<"Vehicle Destructor"<<endl;
}

string RentalVehicleDetails::getVehicleName()
{
    return m_vehicleName;
}

string RentalVehicleDetails::getVehicleStatus()
{
    return m_vehicleStatus;
}

float RentalVehicleDetails::getVehicleCost()
{
    return m_vehicleCost;
}

string RentalVehicleDetails::getVehicleNumber()
{
    return m_vehicleNumber;
}

string RentalVehicleDetails::getVehicleModel()
{
    return m_vehicleModel;
}

void RentalVehicleDetails::setVehicleModel(string vehicleModel)
{
    m_vehicleModel = vehicleModel;
}

void RentalVehicleDetails::setVehicleNumber(string vehicleNumber)
{
    m_vehicleNumber = vehicleNumber;
}

void RentalVehicleDetails::setVehicleName(string vehicleName)
{
    m_vehicleName = vehicleName;
}

void RentalVehicleDetails::setVehicleStatus(string vehicleStatus)
{
    m_vehicleStatus = vehicleStatus;
}

void RentalVehicleDetails::setVehicleCost(float vehicleCost)
{
    m_vehicleCost = vehicleCost;
}
