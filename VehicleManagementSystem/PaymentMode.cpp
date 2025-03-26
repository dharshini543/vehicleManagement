
#include "PaymentMode.h"
#include <iostream>

PaymentMode::PaymentMode()
{
    cout<<"Paymentmode Constructor"<<endl;
}

PaymentMode::PaymentMode(string ID, int transactionID, string paymentStatus)
{
    cout<<"Paymentmode Constructor"<<endl;
    m_paymentID = ID;
    m_transactionID = transactionID;
    m_paymentStatus = paymentStatus;
}

PaymentMode::~PaymentMode()
{
    cout<<"Paymentmode Destructor"<<endl;
}

void PaymentMode::setID(string paymentID)
{
    m_paymentID = paymentID;
}

void PaymentMode::setTransactionID(int transactionID)
{
    m_transactionID = transactionID;
}

string PaymentMode::getID()
{
    return m_paymentID;
}

int PaymentMode::getTransactionID()
{
    return m_transactionID;
}

string PaymentMode::getPaymentStatus()
{
    return m_paymentStatus;
}

void PaymentMode::setPaymentStatus(string paymentStatus)
{
    m_paymentStatus = paymentStatus;
}
