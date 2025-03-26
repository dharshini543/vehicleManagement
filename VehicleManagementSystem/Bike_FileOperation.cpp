
#include "Bike_FileOperation.h"
#include <iostream>
#include<fstream>

Bike_FO::Bike_FO()
{
    cout<<"Bike File operations Constructor"<<endl;
}

Bike_FO::~Bike_FO()
{
    cout<<"Bike File operations Destructor"<<endl;
}

void Bike_FO::writeData(list<RentalBikeDetails*> bikeList)
{
    ofstream file("bike.csv");
    if (!file)
    {
        cout << "Error opening Bike  file for writing!" << endl;
        return ;
    }
    file<<"Name          "<<"Model       "<<"Number           "<<"Cost          "<<"Status"<<endl;
    for(auto* i:bikeList)
    {
        file<<i->getVehicleName()<<","<<i->getVehicleModel()<<","<<i->getVehicleNumber()<<","<<i->getVehicleCost()<<","<<i->getVehicleStatus()<<endl;
    }
    cout<<"Data written to Bike file"<<endl;
    file.close();
}

list<RentalBikeDetails*> Bike_FO::readData()
{
    list<RentalBikeDetails*> bikeList;
    ifstream file("bike.csv");
    if (!file)
    {
        cout << "Error opening Bike file for reading!" << endl;
        return bikeList;
    }

    string line, bikeName, bikeStatus, bikeNumber, bikeModel;
    float bikeCost;

    getline(file, line);
    while (getline(file, bikeName, ',') && getline(file, bikeModel, ',') && getline(file, bikeNumber,',') && file >> bikeCost && file.ignore() && getline(file, bikeStatus))
    {
        bikeList.push_back(new RentalBikeDetails(bikeName, bikeModel, bikeNumber, bikeCost, bikeStatus));
    }

    file.close();
    cout<<"Data read from Bike file"<<endl;

    return bikeList;
}
