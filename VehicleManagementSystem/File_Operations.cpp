#include "File_Operations.h"
#include<fstream>
#include <iostream>
#include "Rental_Bike_Details.h"
#include "Rental_Car_Details.h"
#include "Cash.h"
#include "UPI.h"

File_Operations::File_Operations()
{
    cout<<"File operations Constructor"<<endl;
}

File_Operations::~File_Operations()
{
    cout<<"File operations Destructor"<<endl;
}

void File_Operations::writeData(list<User *> userList)
{
    ofstream file("user.csv");
    if (!file)
    {
        cout << "Error opening User  file for writing!" << endl;
        return ;
    }
    file<<"UserName    "<<"Password    "<<"UserRole    "<<endl;
    for(auto* i:userList)
    {
        file<<i->getUserName()<<","<<i->getPassWord()<<","<<i->getUserRole()<<endl;
    }
    cout<<"Data written to User file"<<endl;
    file.close();
}

auto User_FileOperation::readData()
{
    list<User*> userList;
    ifstream file("user.csv");
    if (!file)
    {
        cout << "Error opening User file for reading!" << endl;
        return userList;
    }

    string line, userName, passWord, userRole;
    int userID;

    getline(file, line);
    while (getline(file, userName, ',') && getline(file, passWord, ',') && getline(file, userRole))
    {
        userList.push_back(new User(userName, passWord, userRole));
    }

    file.close();
    cout<<"Data read from User file"<<endl;

    return userList;
}

void File_Operations::writeData(list<Rental_Customer_details *> customerList)
{
    ofstream file("customer.csv");
    if (!file)
    {
        cout << "Error opening customer file for writing!" << endl;
        return ;
    }
    file<<"CustomerName"<<"BookingID"<<"VehicleName"<<"VehicleModel"<<"VehicleNumber"<<"RentalDuration"<<"vehicleType"<<"VehicleCost"<<"PaymentMode"<<"PaymentID"<<"TransactionID"<<"VehicleStatus"<<"AmountPaid"<<"DueAmount"<<"PaymentStatus"<<endl;
    for(auto i:customerList)
    {
        file<<i->getCusName()<<","<<i->getBookingID()<<","<<i->getVehicleName()<<","<<i->getVehicleModel()<<","<<i->getVehicleNumber()<<","<<i->getRentalDuration()<<","<<i->getVehicleType()<<","<<i->getVehicleCost()<<","<<i->getPaymentType()<<","<<i->getID()<<","<<i->getTransactionID()<<","<<i->getVehicleStatus()<<","<<i->getAmountPaid()<<","<<i->getBalanceAmount()<<","<<i->getpaymentStatus()<<endl;
    }
    cout<<"Data written to Customer file"<<endl;
    file.close();
}

auto  File_Operations::readData()
{
    list<Rental_Customer_details*> customerList;
    ifstream file("customer.csv");
    if (!file)
    {
        cout << "Error opening customer file for reading!" << endl;
        return customerList;
    }

    string line, cusName, vehicleName, vehicleNum, paymentMode, vehicleType, vehicleStatus, cusVehicleStatus, paymentID, paymentStatus, vehicleModel;
    int rentalDuration, bookingID, transactionID;
    float vehicleCost, amountPaid, balanceAmount;

    getline(file, line);
    while (getline(file, cusName, ',') && file >> bookingID  && file.ignore() && getline(file, vehicleName, ',') && getline(file, vehicleModel, ',') && getline(file, vehicleNum, ',') &&  file >> rentalDuration && file.ignore() && getline(file, vehicleType, ',') && file >> vehicleCost  && file.ignore() && getline(file, paymentMode, ',') && getline(file, paymentID, ',') && file >> transactionID  && file.ignore() && getline(file, cusVehicleStatus,',') && file >> amountPaid  && file.ignore() && file >> balanceAmount && file.ignore() && getline(file, paymentStatus))
    {
        if(vehicleType == "Bike")
        {
            RentalBikeDetails* bike = new RentalBikeDetails(vehicleName, vehicleModel, vehicleNum, vehicleCost, vehicleStatus);
            if("UPI" == paymentMode)
            {
                UPI* upi = new UPI(paymentID, transactionID, paymentStatus);
                customerList.push_back(new Rental_Customer_details(cusName, bookingID, bike, upi, cusVehicleStatus, vehicleType, rentalDuration, paymentMode, amountPaid, balanceAmount));
            }
            else if("Cash" == paymentMode)
            {
                Cash* cash = new Cash(paymentID, transactionID, paymentStatus);
                customerList.push_back(new Rental_Customer_details(cusName, bookingID, bike, cash, cusVehicleStatus, vehicleType, rentalDuration, paymentMode, amountPaid, balanceAmount));
            }
        }
        else if(vehicleType == "Car")
        {
            RentalCarDetails* car = new RentalCarDetails(vehicleName, vehicleModel, vehicleNum, vehicleCost, vehicleStatus);
            if("UPI" == paymentMode)
            {
                UPI* upi = new UPI(paymentID, transactionID, paymentStatus);
                customerList.push_back(new Rental_Customer_details(cusName, bookingID, car, upi, cusVehicleStatus, vehicleType, rentalDuration, paymentMode, amountPaid, balanceAmount));
            }
            else if("Cash" == paymentMode)
            {
                Cash* cash = new Cash(paymentID, transactionID, paymentStatus);
                customerList.push_back(new Rental_Customer_details(cusName, bookingID, car, cash, cusVehicleStatus, vehicleType, rentalDuration, paymentMode, amountPaid, balanceAmount));
            }
        }
        else
        {
            break;
        }
    }
    file.close();
    cout<<"Data read from Customer file"<<endl;

    return customerList;
}

void File_Operations::writeData(list<RentalCarDetails*> carList)
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

auto File_Operations::readData()
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

void File_Operations::writeData(list<RentalBikeDetails*> bikeList)
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

auto Bike_FO::readData()
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
