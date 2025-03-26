
#ifndef RENTAL_CUSTOMER_DETAILS_H
#define RENTAL_CUSTOMER_DETAILS_H

#include "PaymentMode.h"
#include "Rental_Vehicle_Details.h"

class Rental_Customer_details
{
public:
    Rental_Customer_details();
    Rental_Customer_details(string customerName, int bookingID, RentalVehicleDetails* vehicle, PaymentMode* payMode, string vehicleStatus, string m_vehicleType, int rentalDuration, string paymentType, float amountPaid, float balanceAmount);
    ~Rental_Customer_details();

    string getCusName();
    int getBookingID();
    string getVehicleName();
    string getVehicleNumber();
    string getVehicleType();
    float getVehicleCost();
    string getPaymentType();
    int getRentalDuration();


    string getVehicleStatus();
    void setVehicleStatus(string vehicleStatus);

    string getVehicleModel();
    void setVehicleModel(string vehicleModel);

    float getAmountPaid();
    void setAmountPaid(float amountPaid);

    float getBalanceAmount();
    void setBalanceAmount(float balanceAmount);

    string getID();
    void setID(string ID);

    int getTransactionID();
    void setTransactionID(int transactionID);

    string getpaymentStatus();
    void setPaymentStatus(string paymentStatus);


private:
    string m_customerName;
    string m_vehicleType;
    string m_vehicleStatus;
    int m_bookingID;
    float m_amountPaid;
    float m_balanceAmount;
    string m_paymentType;
    int m_rentalDuration;
    RentalVehicleDetails* m_vehicle;
    PaymentMode* m_payMode;

};

#endif // RENTAL_CUSTOMER_DETAILS_H
