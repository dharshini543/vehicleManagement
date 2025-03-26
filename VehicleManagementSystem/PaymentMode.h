
#ifndef PAYMENTMODE_H
#define PAYMENTMODE_H

#include <string>
using namespace std;

class PaymentMode
{
public:
    PaymentMode();
    PaymentMode(string ID, int transactionID, string paymentStatus);
    virtual ~PaymentMode();

    virtual string getID();
    virtual void setID(string paymentID);

    virtual int getTransactionID();
    virtual void setTransactionID(int transactionID);

    virtual string getPaymentStatus();
    virtual void setPaymentStatus(string paymentStatus);

protected:
    string m_paymentID;
    int m_transactionID;
    string m_paymentStatus;
};

#endif // PAYMENTMODE_H
