
#include "Car_FileOperation.h"
#include <iostream>
#include<fstream>

Car_FileOperation::Car_FileOperation()
{
    cout<<"Car File Operation Constructor"<<endl;
}

Car_FileOperation::~Car_FileOperation()
{
    cout<<"Car File Operation Destructor"<<endl;
}

void Car_FileOperation::writeData(list<RentalCarDetails*> carList)
{
    ofstream file("car.csv");
    if (!file)
    {
        cout << "Error opening car  file for writing!" << endl;
        return ;
    }
    file<<"Name          "<<"Model      "<<"Number           "<<"Cost          "<<"Status"<<endl;
    for(auto* i:carList)
    {
        file<<i->getVehicleName()<<","<<i->getVehicleModel()<<","<<i->getVehicleNumber()<<","<<i->getVehicleCost()<<","<<i->getVehicleStatus()<<endl;
    }
    cout<<"Data written to Car CSV file"<<endl;
    file.close();
}

list<RentalCarDetails*> Car_FileOperation::readData()
{
    list<RentalCarDetails*> carList;
    ifstream file("car.csv");
    if (!file)
    {
        cout << "Error opening Car file for reading!" << endl;
        return carList;
    }

    string line, carName, carStatus, carNumber, carModel;
    float carCost;

    getline(file, line);
    while (getline(file, carName, ',') && getline(file, carModel,',') && getline(file, carNumber,',') && file >> carCost && file.ignore() && getline(file, carStatus))
    {
        carList.push_back(new RentalCarDetails(carName, carModel, carNumber, carCost, carStatus));
    }

    file.close();
    cout<<"Data read from Car file"<<endl;

    return carList;
}
