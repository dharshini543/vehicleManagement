
#ifndef CUSTOMER_FILEOPERATION_H
#define CUSTOMER_FILEOPERATION_H

#include "Rental_Customer_details.h"
#include <list>

class Customer_FileOperation
{
public:
    Customer_FileOperation();
    ~Customer_FileOperation();

    void writeData(list<Rental_Customer_details*> customerList);
    list<Rental_Customer_details *> readData();
};

#endif // CUSTOMER_FILEOPERATION_H
