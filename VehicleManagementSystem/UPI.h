#ifndef UPI_H
#define UPI_H

#include "PaymentMode.h"

class UPI:public PaymentMode
{
public:
    UPI(string upiID, int transactionID, string paymentStatus);
    ~UPI();

    string getID();
    void setID(string ID);

    int getTransactionID();
    void setTransactionID(int transactionID);

    string getPaymentStatus();
    void setPaymentStatus(string paymentStatus);
};

#endif // UPI_H
