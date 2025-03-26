#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H
using namespace std;
#include<list>
#include"Rental_bike_details.h"
#include"Rental_Car_details.h"
#include"Rental_Customer_details.h"
#include"User.h"

class File_Operations
{
public:
    File_Operations();
    void writeData(list<RentalBikeDetails*> bikeList);
    void writeData(list<RentalCarDetails*> carList);
    auto readData();
    void writeData(list<Rental_Customer_details*> customerList);
    void writeData(list<User*> userList);
};

#endif // FILE_OPERATIONS_H
