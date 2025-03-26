
#include "Cash.h"
#include <iostream>

Cash::Cash(string cashID, int transactionID, string paymentStatus)
{
    cout<<"Cash Constructor"<<endl;
    m_paymentID = cashID;
    m_transactionID = transactionID;
    m_paymentStatus = paymentStatus;
}

Cash::~Cash()
{
    cout<<"Cash Destructor"<<endl;
}
void Cash::setID(string ID)
{
    m_paymentID = ID;
}

void Cash::setTransactionID(int transactionID)
{
    m_transactionID = transactionID;
}

string Cash::getID()
{
    return m_paymentID;
}

int Cash::getTransactionID()
{
    return m_transactionID;
}
string Cash::getPaymentStatus()
{
    return m_paymentStatus;
}

void Cash::setPaymentStatus(string paymentStatus)
{
    m_paymentStatus = paymentStatus;
}
