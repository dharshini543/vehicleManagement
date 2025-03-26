
#include "Customer_FileOperation.h"
#include "Rental_Bike_Details.h"
#include "Rental_Car_Details.h"
#include "Cash.h"
#include "UPI.h"
#include <iostream>
#include<fstream>

Customer_FileOperation::Customer_FileOperation()
{
    cout << "Customer_Fileoperation Constructor" << endl;
}

Customer_FileOperation::~Customer_FileOperation()
{
    cout << "Customer_Fileoperation Destructor" << endl;
}

void Customer_FileOperation::writeData(list<Rental_Customer_details *> customerList)
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

list<Rental_Customer_details *> Customer_FileOperation::readData()
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
