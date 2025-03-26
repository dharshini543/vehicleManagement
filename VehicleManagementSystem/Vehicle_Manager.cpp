
#include "Vehicle_Manager.h"
#include "Bike_FileOperation.h"
#include "Car_FileOperation.h"
#include "Cash.h"
#include "Customer_FileOperation.h"
#include "Rental_Customer_details.h"
#include "UPI.h"
#include <cstring>
#include <string>
#include<iostream>
#include <chrono>

using namespace std;
void someFunction()
{
    // Example function that you want to measure the execution time of
    for (int i = 0; i < 1000000; ++i) {
        // Just a dummy loop
        int x = i * i;
    }
}
Vehicle_Manager::Vehicle_Manager()
{
    int userCount = 0;
    cout<<"Vehicle Manager Constructor"<<endl;
    m_bikeFO = new Bike_FO;
    m_carFO = new Car_FileOperation;
    m_cusFO = new Customer_FileOperation;
    m_userFO = new User_FileOperation;
    m_loginManager = new Login_Management;
   /* m_bikeFO->writeData(m_bikeList);
    m_carFO->writeData(m_carList);
    m_cusFO->writeData(m_customerList);
    m_userList = m_loginManager->getUserList();
    m_userFO->writeData(m_userList);*/
    m_customerList = m_cusFO->readData();
    m_carList = m_carFO->readData();
    m_bikeList = m_bikeFO->readData();
    m_userList = m_userFO->readData();
    for(auto user:m_userList)
    {
        ++userCount;
    }
    m_loginManager->setUserCount(userCount);
    m_loginManager->setUserList(m_userList);

}

Vehicle_Manager::~Vehicle_Manager()
{
    cout<<"Vehicle Manager Destructor"<<endl;
    delete m_bikeFO;
    delete m_carFO;
    delete m_cusFO;
    delete m_userFO;
    delete m_loginManager;

    for(auto* bike : m_bikeList)
    {
        delete bike;
    }

    for(auto* car : m_carList)
    {
        delete car;
    }

    for(auto* customer : m_customerList)
    {
        delete customer;
    }
}

int Vehicle_Manager::main_menu()
{
    int choice,option,input;
    User* currentUser;

    if(m_loginManager->getUserCount() == 0 )
    {
        currentUser = m_loginManager->addAdmin();
        cout<<"Admin "<<currentUser->getUserName()<<" added successfully"<<endl;
    }

    while(true)
    {
        cout<<"Enter"<<endl<<"1. SignUp to create account"<<endl<<"2. Login"<<endl<<"3. Exit"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            if(m_loginManager->getUserCount() > 0)
            {
                currentUser = m_loginManager->signUp();
                cout<<"Welcome to Rental vehicle management system"<<endl;
            }
        }
        else if(choice == 2)
        {
            if(m_loginManager->getUserCount() > 0)
            {
                currentUser = m_loginManager->login();
                cout<<"Welcome to Rental vehicle management system"<<endl;
            }
        }
        else
        {
            return 0;
        }
        if(currentUser != NULL)
        {
            if(currentUser->getUserRole() == "ADMIN")
            {
                int True = 1;
                while(True)
                {
                    cout<<"Enter"<<endl<<"1. Add ADMIN"<<endl<<"2. Delete ADMIN"<<endl<<"3. Add Vehicle"<<endl<<"4. Delete Vehicle"<<endl<<"5. Search Vehicle"<<endl<<"6. Display Vehicles"<<endl<<"7. Book Vehicle"<<endl;
                    cout<<"8. Return Vehicle"<<endl<<"9. Update Vehicle Price"<<endl<<"10. View Customers Record"<<endl<<"11. LOGOUT"<<endl<<endl;
                    cin>>choice;
                    switch(choice)
                    {
                    case ADD_ADMIN:
                    {
                        currentUser = m_loginManager->addAdmin();
                        cout<<"Admin "<<currentUser->getUserName()<<" added successfully"<<endl;
                    }
                    break;
                    case DELETE_ADMIN:
                    {
                        string userName;
                        cout<<"Enter username to delete ADMIN"<<endl;
                        cin>>userName;
                        for(auto* admin:m_userList)
                        {
                            if(admin->getUserName() == userName)
                            {
                                admin->setUserRole("Deleted");
                                cout<<"Admin "<<admin->getUserName()<<" deleted successfully"<<endl;
                            }
                        }
                    }
                    break;
                    case ADMIN_ADD_VEHICLE:
                    {
                        cout<<"Enter"<<endl<<"1. Add Bike"<<endl<<"2. Add Car"<<endl<<"Any Other number to exit"<<endl<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Add_Bike:
                        {
                            this->addBike();
                        }
                        break;
                        case Add_Car:
                        {
                            this->addCar();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case ADMIN_DELETE_VEHICLE:{
                        cout<<"Enter"<<endl<<"1. Delete Bike"<<endl<<"2. Delete Car"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Delete_Bike:
                        {
                            auto start = std::chrono::high_resolution_clock::now();

                            // Call the function or block of code you want to measure
                            someFunction();
                            this->deleteBike();
                            // Record the end time after the code execution
                            auto end = std::chrono::high_resolution_clock::now();

                            // Calculate the duration (difference between end and start)
                            std::chrono::duration<double> duration = end - start;

                            // Output the execution time in seconds
                            std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
                        }
                        break;
                        case Delete_Car:
                        {
                            this->deleteCar();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case ADMIN_SEARCH_VEHICLE:{
                        cout<<"Enter"<<endl<<"1. Search Bike"<<endl<<"2. Search Car"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Search_Bike:
                        {
                            auto start = std::chrono::high_resolution_clock::now();

                            // Call the function or block of code you want to measure
                            someFunction();
                            this->searchBike();
                            // Record the end time after the code execution
                            auto end = std::chrono::high_resolution_clock::now();

                            // Calculate the duration (difference between end and start)
                            std::chrono::duration<double> duration = end - start;

                            // Output the execution time in seconds
                            std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
                        }
                        break;
                        case Search_Car:
                        {
                            this->searchCar();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case ADMIN_DISPLAY_VEHICLES:
                    {
                        int True = 1;
                        cout<<"Enter"<<endl<<"1.Display Bike Details"<<endl<<"2. Display Car details"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case DISPLAY_BIKE:
                        {
                            while(True)
                            {
                                cout<<"Enter"<<endl<<"1.Display Bike Details"<<endl<<"2. Sort By price"<<endl<<"3. Sort BY Name"<<endl<<"4. Sort by Status"<<endl<<"Any Other number to exit"<<endl;
                                cin>>input;
                                switch(input)
                                {
                                case Display_Bike:
                                {
                                    this->displayBikeList();
                                }
                                break;
                                case Sort_By_Price:
                                {
                                    auto start = std::chrono::high_resolution_clock::now();

                                    // Call the function or block of code you want to measure
                                    someFunction();
                                    this->sortByBikePrice();
                                    this->displayBikeList();
                                    // Record the end time after the code execution
                                    auto end = std::chrono::high_resolution_clock::now();

                                    // Calculate the duration (difference between end and start)
                                    std::chrono::duration<double> duration = end - start;

                                    // Output the execution time in seconds
                                    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
                                }
                                break;
                                case Sort_By_Name:
                                {
                                    this->sortByBikeName();
                                    this->displayBikeList();

                                }
                                break;
                                case Sort_By_Status:
                                {
                                    this->sortByBikeStatus();
                                    this->displayBikeList();

                                }
                                break;
                                default:
                                    cout<<"Invalid input"<<endl;
                                    True = 0;
                                }
                            }
                        }
                        break;
                        case DISPLAY_CAR:
                        {
                            while(True)
                            {
                                cout<<"Enter"<<endl<<"1.Display Car Details"<<endl<<"2. Sort By price"<<endl<<"3. Sort BY Name"<<endl<<"4. Sort by Status"<<endl<<"Any Other number to exit"<<endl;
                                cin>>input;
                                switch(input)
                                {
                                case DisplayCar:
                                {
                                    this->displayCarList();
                                }
                                break;
                                case SortByPrice:
                                {
                                    this->sortByCarPrice();
                                    this->displayCarList();
                                }
                                break;
                                case SortByName:
                                {
                                    this->sortByCarName();
                                    this->displayCarList();
                                }
                                break;
                                case SortByStatus:
                                {
                                    this->sortByCarStatus();
                                    this->displayCarList();
                                }
                                break;
                                default:
                                    cout<<"Invalid input"<<endl;
                                    True = 0;
                                }
                            }

                        }

                        }

                    }
                    break;
                    case ADMIN_BOOK_VEHICLE:
                    {
                        cout<<"Enter"<<endl<<"1. Book Bike"<<endl<<"2. Book Car"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Book_Bike:
                        {
                            this->bookBike();
                        }
                        break;
                        case Book_Car:
                        {
                            this->bookCar();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case ADMIN_RETURN_VEHICLE:
                    {
                        cout<<"Enter"<<endl<<"1. Return Bike"<<endl<<"2. Return Car"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Return_Bike:
                        {
                            this->returnBike();
                            this->displayCustomerList();
                        }
                        break;
                        case Return_Car:
                        {
                            this->returnCar();
                            this->displayCustomerList();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case ADMIN_UPDATE_VEHICLE_PRICE:
                    {
                        cout<<"Enter"<<endl<<"1. Update Bike Price"<<endl<<"2. Update Car Price"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Update_Bike_price:
                        {
                            this->updateBikeCost();
                        }
                        break;
                        case Update_Car_price:
                        {
                            this->updateCarCost();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case ADMIN_CUSTOMER_RECORD:
                    {
                        this->displayCustomerList();
                    }
                    break;
                    case ADMIN_LOGOUT:
                    {
                        this->writeDataToFile();
                        cout<<"Logging out......"<<endl;
                        True = 0;
                    }
                    break;
                    default:
                        cout<<"Invalid input"<<endl;

                    }
                }
            }
            else if(currentUser->getUserRole() == "CUSTOMER")
            {
                int True = 1;
                while(True)
                {
                    cout<<"Enter"<<endl<<"1. Book Vehicle"<<endl<<"2. Search Vehicle"<<endl<<"3. Display Vehicle"<<endl<<"4. Logout"<<endl;
                    cin>>choice;
                    switch(choice)
                    {
                    case CUSTOMER_BOOK_VEHICLE:
                    {
                        cout<<"Enter"<<endl<<"1. Book Bike"<<endl<<"2. Book Car"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Book_Bike:
                        {
                            this->bookBike();
                        }
                        break;
                        case Book_Car:
                        {
                            this->bookCar();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case CUSTOMER_SEARCH_VEHICLE:{
                        cout<<"Enter"<<endl<<"1. Search Bike"<<endl<<"2. Search Car"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case Search_Bike:
                        {
                            this->searchBike();
                        }
                        break;
                        case Search_Car:
                        {
                            this->searchCar();
                        }
                        break;
                        default:
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                    case CUSTOMER_DISPLAY_VEHICLES:
                    {
                        int True = 1;
                        cout<<"Enter"<<endl<<"1.Display Bike Details"<<endl<<"2. Display Car details"<<endl<<"Any Other number to exit"<<endl;
                        cin>>option;
                        switch(option)
                        {
                        case DISPLAY_BIKE:
                        {
                            while(True)
                            {
                                cout<<"Enter"<<endl<<"1.Display Bike Details"<<endl<<"2. Sort By price"<<endl<<"3. Sort BY Name"<<endl<<"4. Sort by Status"<<endl<<"Any Other number to exit"<<endl;
                                cin>>input;
                                switch(input)
                                {
                                case Display_Bike:
                                {
                                    this->displayBikeList();
                                }
                                break;
                                case Sort_By_Price:
                                {
                                    this->sortByBikePrice();
                                    this->displayBikeList();
                                }
                                break;
                                case Sort_By_Name:
                                {
                                    this->sortByBikeName();
                                    this->displayBikeList();

                                }
                                break;
                                case Sort_By_Status:
                                {
                                    this->sortByBikeStatus();
                                    this->displayBikeList();

                                }
                                break;
                                default:
                                    cout<<"Invalid input"<<endl;
                                    True = 0;
                                }
                            }
                        }
                        break;
                        case DISPLAY_CAR:
                        {
                            while(True)
                            {
                                cout<<"Enter"<<endl<<"1.Display Car Details"<<endl<<"2. Sort By price"<<endl<<"3. Sort BY Name"<<endl<<"4. Sort by Status"<<endl<<"Any Other number to exit"<<endl;
                                cin>>input;
                                switch(input)
                                {
                                case DisplayCar:
                                {
                                    this->displayCarList();
                                }
                                break;
                                case SortByPrice:
                                {
                                    this->sortByCarPrice();
                                    this->displayCarList();

                                }
                                break;
                                case SortByName:
                                {
                                    this->sortByCarName();
                                    this->displayCarList();

                                }
                                break;
                                case SortByStatus:
                                {
                                    this->sortByCarStatus();
                                    this->displayCarList();

                                }
                                break;
                                default:
                                    cout<<"Invalid input"<<endl;
                                    True = 0;
                                }
                            }

                        }

                        }

                    }
                    break;
                    case CUSTOMER_LOGOUT:{
                        this->writeDataToFile();
                        cout<<"Logging out......"<<endl;
                        True = 0;

                    }
                    break;
                    default:
                        cout<<"Invalid input"<<endl;
                    }

                }
            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }
    }
    return 0;
}

void Vehicle_Manager::addBike()
{
    string bikeName,bikeStatus,bikeNumber,bikeModel;
    float bikeCost;

    while(true)
    {
        cout<<"Enter Bike Name"<<endl;
        cin>>bikeName;
        if(bikeName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Bike Number"<<endl;
        cin>>bikeNumber;
        if(bikeNumber.length() > 10)
        {
            cout<<"Please enter maximum 10 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter  Bike model"<<endl;
        cin>>bikeModel;
        if(bikeModel.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter  Bike status"<<endl;
        cin>>bikeStatus;
        if(bikeStatus.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    cout<<"Enter Bike cost per day"<<endl;
    cin>>bikeCost;
    m_bikeList.push_back(new RentalBikeDetails(bikeName,bikeModel,bikeNumber,bikeCost, bikeStatus));

}

void Vehicle_Manager::addCar()
{
    string carName,carStatus,carNumber,carModel;
    float carCost;

    while(true)
    {
        cout<<"Enter Car Name"<<endl;
        cin>>carName;
        if(carName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Car Model"<<endl;
        cin>>carModel;
        if(carModel.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Car Number"<<endl;
        cin>>carNumber;
        if(carNumber.length() > 10)
        {
            cout<<"Please enter maximum 10 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter  Car status"<<endl;
        cin>>carStatus;
        if(carStatus.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    cout<<"Enter Car cost per day"<<endl;
    cin>>carCost;
    m_carList.push_back(new RentalCarDetails(carName,carModel,carNumber, carCost, carStatus));
}
void Vehicle_Manager::addCustomer(string vehicleName,string vehicleModel,string vehicleStatus,float vehicleCost,string vehicleNumber)
{
    string cusName, paymentMode, vehicleType, cusVehicleStatus, upiID, cashID = "NULL", paymentStatus;
    int bookingID, choice;
    int rentalDuration, cashTransactionID = 0;
    static int UPItransactionID = 1000;
    float amountPaid, balanceAmount = 0;

    cusVehicleStatus = vehicleStatus;

    while(true)
    {
        cout<<"Enter Customer Name"<<endl;
        cin>>cusName;
        if(cusName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    cout<<"Enter BookingID"<<endl;
    cin>>bookingID;
    while(true)
    {
        cout<<"Enter Vehicle Type"<<endl;
        cin>>vehicleType;
        if(vehicleType.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    cout<<"Enter Rental duration"<<endl;
    cin>>rentalDuration;
    if(rentalDuration > 5)
    {
        cout<<"Maximum rental duration is 5 days"<<endl;
    }
    cout<<"Enter Payment mode"<<endl;
    cout<<"Enter"<<endl<<"1. Cash"<<endl<<"2. UPI"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        paymentMode = "Cash";
        cout<<"Pay "<<vehicleCost * rentalDuration<<" ruppees"<<endl;
        cout<<"Enter Amount"<<endl;
        cin>>amountPaid;
        cout<<"Amount of rupees "<<amountPaid<<" recieved through "<<paymentMode<<endl;
        paymentStatus = "Success";
        cout<<"payment "<<paymentStatus;
        if(amountPaid < vehicleCost*rentalDuration)
        {
            paymentStatus = "Pending";
            balanceAmount = (vehicleCost * rentalDuration) - amountPaid;
            cout<<"Balance Amount : "<<balanceAmount<<endl;
        }

    }
    else if (choice == 2)
    {
        paymentMode = "UPI";
        cout<<"Enter UPI ID"<<endl;
        cin>>upiID;
        cout<<"Pay "<<vehicleCost*rentalDuration<<" ruppees"<<endl;
        cout<<"Enter Amount"<<endl;
        cin>>amountPaid;
        if(amountPaid == vehicleCost*rentalDuration)
        {
            cout<<"Amount of rupees "<<amountPaid<<" recieved through"<<paymentMode<<endl;
            paymentStatus = "Success";
            cout<<"payment "<<paymentStatus<<endl;
            cout<<"Transaction successfull"<<endl;
            cout<<"Transaction ID :"<<++UPItransactionID<<endl;
        }
        else
        {
            paymentStatus = "Pending";
            cout<<"payment "<<paymentStatus<<endl;
        }
        if(amountPaid < vehicleCost*rentalDuration)
        {
            balanceAmount =(vehicleCost*rentalDuration) - amountPaid;
            cout<<"Balance Amount : "<<balanceAmount<<endl;
        }

    }
    else
    {
        cout<<"Invalid input"<<endl;
    }

    if(vehicleType == "Bike")
    {
        RentalBikeDetails* bike = new RentalBikeDetails(vehicleName,vehicleModel, vehicleNumber, vehicleCost, vehicleStatus);
        if("UPI" == paymentMode)
        {
            UPI* upi = new UPI(upiID,UPItransactionID,paymentStatus);
            m_customerList.push_back(new Rental_Customer_details(cusName, bookingID, bike,upi,cusVehicleStatus,vehicleType,rentalDuration,paymentMode,amountPaid,balanceAmount));
        }
        else if("Cash" == paymentMode)
        {
            Cash* cash = new Cash(cashID,cashTransactionID,paymentStatus);
            m_customerList.push_back(new Rental_Customer_details(cusName, bookingID, bike,cash, cusVehicleStatus, vehicleType, rentalDuration, paymentMode,amountPaid,balanceAmount));
        }
    }
    else if(vehicleType == "Car")
    {
        RentalCarDetails* car = new RentalCarDetails(vehicleName,vehicleModel,vehicleNumber,vehicleCost,vehicleStatus);
        if("UPI" == paymentMode)
        {
            UPI* upi = new UPI(upiID,UPItransactionID,paymentStatus);
            m_customerList.push_back(new Rental_Customer_details(cusName, bookingID, car,upi,cusVehicleStatus,vehicleType,rentalDuration,paymentMode,amountPaid,balanceAmount));
        }
        else if("Cash" == paymentMode)
        {
            Cash* cash = new Cash(cashID,cashTransactionID,paymentStatus);
            m_customerList.push_back(new Rental_Customer_details(cusName, bookingID, car,cash, cusVehicleStatus, vehicleType, rentalDuration, paymentMode,amountPaid,balanceAmount));
        }
    }
}
void Vehicle_Manager::deleteBike()
{
    string bikeName,bikeNumber;
    int bikeFound = 0;
    while(true)
    {
        cout<<"Enter Bike Name"<<endl;
        cin>>bikeName;
        if(bikeName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Bike Number"<<endl;
        cin>>bikeNumber;
        if(bikeNumber.length() > 10)
        {
            cout<<"Please enter maximum 10 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    for(auto* bike:m_bikeList)
    {
        if((bikeNumber == bike->getVehicleNumber()) && (bikeName == bike->getVehicleName()) )
        {
            if("Available" == bike->getVehicleStatus() || "Booked" == bike->getVehicleStatus())
            {
                bike->setVehicleStatus("Deleted");
                cout<<bikeName<<" with "<<bikeNumber<<" deleted "<<endl;
            }
            bikeFound++;
        }
    }
    if(bikeFound == 0)
    {
        cout<<bikeName<<" with "<<bikeNumber<<" not found"<<endl;
    }
}

void Vehicle_Manager::deleteCar()
{
    string carName,carNumber;
    int carFound = 0;
    while(true)
    {
        cout<<"Enter Car Name"<<endl;
        cin>>carName;
        if(carName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Car Number"<<endl;
        cin>>carNumber;
        if(carNumber.length() > 10)
        {
            cout<<"Please enter maximum 10 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    for(auto* car:m_carList)
    {
        if((carNumber == car->getVehicleNumber()) && (carName == car->getVehicleName()) )
        {
            if("Available" == car->getVehicleStatus()|| "Booked" == car->getVehicleStatus())
            {
                car->setVehicleStatus("Deleted");
                cout<<carName<<" with "<<carNumber<<" deleted "<<endl;
            }
            carFound++;
        }
    }
    if(carFound == 0)
    {
        cout<<carName<<" with "<<carNumber<<" not found"<<endl;
    }
}

void Vehicle_Manager::searchBike()
{
    string bikeName,bikeNumber;
    int bikeFound = 0;
    while(true)
    {
        cout<<"Enter Bike Name"<<endl;
        cin>>bikeName;
        if(bikeName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Bike Number"<<endl;
        cin>>bikeNumber;
        if(bikeNumber.length() > 10)
        {
            cout<<"Please enter maximum 10 Characters"<<endl;
        }
        else
        {
            break;
        }
    }

    for(auto* bike:m_bikeList)
    {
        if(bikeName == bike->getVehicleName() && bikeNumber == bike->getVehicleNumber())
        {
            cout<<"bikeName";
            cout.width(20);
            cout<<"bikeModel";
            cout.width(20);
            cout<<"bikeNumber";
            cout.width(20);
            cout<<"BikeCost";
            cout.width(20);
            cout<<"BikeStatus"<<endl;
            cout<<bike->getVehicleName();
            cout.width(20);
            cout<<bike->getVehicleModel();
            cout.width(20);
            cout<<bike->getVehicleNumber();
            cout.width(21);
            cout<<bike->getVehicleCost();
            cout.width(24);
            cout<<bike->getVehicleStatus()<<endl;
            bikeFound++;
        }
    }
    if(bikeFound == 0)
    {
        cout<<bikeName<<" with "<<bikeNumber<<" not found"<<endl;
    }
}

void Vehicle_Manager::searchCar()
{
    string carName,carNumber;
    int carFound = 0;
    while(true)
    {
        cout<<"Enter Bike Name"<<endl;
        cin>>carName;
        if(carName.length() > 15)
        {
            cout<<"Please enter maximum 15 Characters"<<endl;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        cout<<"Enter Bike Number"<<endl;
        cin>>carNumber;
        if(carNumber.length() > 10)
        {
            cout<<"Please enter maximum 10 Characters"<<endl;
        }
        else
        {
            break;
        }
    }

    for(auto* car:m_carList)
    {
        if(carName == car->getVehicleName() && carNumber == car->getVehicleNumber())
        {
            cout<<"carName";
            cout.width(20);
            cout<<"carModel";
            cout.width(20);
            cout<<"carNumber";
            cout.width(20);
            cout<<"CarCost";
            cout.width(20);
            cout<<"CarStatus"<<endl;
            cout<<car->getVehicleName();
            cout.width(20);
            cout<<car->getVehicleModel();
            cout.width(20);
            cout<<car->getVehicleNumber();
            cout.width(21);
            cout<<car->getVehicleCost();
            cout.width(24);
            cout<<car->getVehicleStatus()<<endl;
            carFound++;
        }
    }
    if(carFound == 0)
    {
        cout<<carName<<" with "<<carNumber<<" not found"<<endl;
    }
}

void Vehicle_Manager::sortByCarPrice()
{
    for(auto* i:m_carList)
    {
        for(auto* j:m_carList)
        {
            if(j->getVehicleCost() > i->getVehicleCost())
            {
                iter_swap(i,j);
            }
        }
    }
}

void Vehicle_Manager::sortByCarName()
{
    for(auto* i:m_carList)
    {
        for(auto* j:m_carList)
        {
            if(j->getVehicleName() > i->getVehicleName())
            {
                iter_swap(i,j);
            }
        }
    }
}

void Vehicle_Manager::sortByCarStatus()
{
    for(auto* i:m_carList)
    {
        for(auto* j:m_carList)
        {
            if(j->getVehicleStatus() > i->getVehicleStatus())
            {
                iter_swap(i,j);
            }
        }
    }
}

/*void Vehicle_Manager::sortByBikePrice()
{
    for(auto* i:m_bikeList)
    {
        for(auto* j:m_bikeList)
        {
            if(j->getVehicleCost() > i->getVehicleCost())
            {
                iter_swap(i,j);
            }
        }
    }
}*/
void Vehicle_Manager::sortByBikePrice()
{
    m_bikeList.sort([](RentalBikeDetails* a, RentalBikeDetails* b) {
        return a->getVehicleCost() > b->getVehicleCost();
    });
}


void Vehicle_Manager::sortByBikeName()
{
    for(auto* i:m_bikeList)
    {
        for(auto* j:m_bikeList)
        {
            if(j->getVehicleName() > i->getVehicleName())
            {
                iter_swap(i,j);
            }
        }
    }
}

void Vehicle_Manager::sortByBikeStatus()
{
    for(auto* i:m_bikeList)
    {
        for(auto* j:m_bikeList)
        {
            if(j->getVehicleStatus() > i->getVehicleStatus())
            {
                iter_swap(i,j);
            }
        }
    }
}



void Vehicle_Manager::writeDataToFile()
{
    m_bikeFO->writeData(m_bikeList);
    m_carFO->writeData(m_carList);
    m_cusFO->writeData(m_customerList);
    m_userList = m_loginManager->getUserList();
    m_userFO->writeData(m_userList);
}

void Vehicle_Manager::bookBike()
{
    string bikeName, bikeNumber;
    int bikeFound = 0;
    cout<<"Enter name of bike to book"<<endl;
    cin>>bikeName;
    cin.ignore();
    cout<<"Enter Bike number"<<endl;
    cin>>bikeNumber;

    for(auto* bike:m_bikeList)
    {
        if((bikeNumber == bike->getVehicleNumber()) && (bikeName == bike->getVehicleName()) )
        {
            if("Available" == bike->getVehicleStatus())
            {
                bike->setVehicleStatus("Booked");
                cout<<bikeName<<" bike is Booked"<<endl;
                this->addCustomer(bike->getVehicleName(),bike->getVehicleModel(),bike->getVehicleStatus(),bike->getVehicleCost(),bike->getVehicleNumber());
            }
            else if("Booked" == bike->getVehicleStatus())
            {
                cout<<bikeName<<" bike is already Booked"<<endl;
            }
            bikeFound++;
        }
    }
    if(bikeFound == 0)
    {
        cout<<bikeName<<" with "<<bikeNumber<<" not found"<<endl;
    }
}

void Vehicle_Manager::bookCar()
{
    string carName,carNumber;
    int carFound = 0;
    cout<<"Enter name of car to book"<<endl;
    cin>>carName;
    cout<<"Enter Car number"<<endl;
    cin>>carNumber;
    for(auto* car:m_carList)
    {
        if(car->getVehicleName() == carName && car->getVehicleNumber() == carNumber)
        {
            if(car->getVehicleStatus() == "Available")
            {
                car->setVehicleStatus("Booked");
                cout<<carName<<" Car is Booked"<<endl;
                this->addCustomer(car->getVehicleName(),car->getVehicleModel(),car->getVehicleStatus(),car->getVehicleCost(),car->getVehicleNumber());
            }
            else if("Booked" == car->getVehicleStatus())
            {
                cout<<carName<<" car is already Booked"<<endl;
            }
            carFound++;
        }
    }
    if(carFound == 0)
    {
        cout<<carName<<" with "<<carNumber<<" not found"<<endl;
    }
}

void Vehicle_Manager::returnBike()
{
    string bikeName,bikeNumber;
    int success = 0;
    cout<<"Enter name of Bike to return"<<endl;
    cin>>bikeName;
    cout<<"Enter Bike number"<<endl;
    cin>>bikeNumber;
    for(auto* bike:m_bikeList)
    {
        if(bike->getVehicleName() == bikeName && bike->getVehicleNumber() == bikeNumber)
        {
            if(bike->getVehicleStatus() == "Booked")
            {
                for(auto* customer:m_customerList)
                {
                    if(bikeNumber == customer->getVehicleNumber() &&  "Booked" == customer->getVehicleStatus())
                    {
                        if(customer->getBalanceAmount() == 0)
                        {
                            cout<<bikeName<<" Bike is returned"<<endl;
                            customer->setVehicleStatus("Returned");
                        }
                        else
                        {
                            cout<<"Please pay balance Amount of "<<customer->getBalanceAmount()<<" rupees"<<endl;
                            success = this->payment(customer->getBalanceAmount());
                            if(success)
                            {
                                customer->setAmountPaid(customer->getAmountPaid()+customer->getBalanceAmount());
                                customer->setBalanceAmount(0);
                                cout<<bikeName<<" Bike is returned"<<endl;
                                customer->setVehicleStatus("Returned");
                                customer->setPaymentStatus("Success");
                            }

                        }
                    }

                }
                bike->setVehicleStatus("Available");
            }
        }
    }
}

void Vehicle_Manager::returnCar()
{
    string carName,carNumber;
    int success = 0;
    cout<<"Enter name of car to return"<<endl;
    cin>>carName;
    cout<<"Enter Car number"<<endl;
    cin>>carNumber;
    for(auto car:m_carList)
    {
        if(car->getVehicleName() == carName && car->getVehicleNumber() == carNumber)
        {
            if(car->getVehicleStatus() == "Booked")
            {
                for(auto* customer:m_customerList)
                {
                    if(carNumber == customer->getVehicleNumber() &&  "Booked" == customer->getVehicleStatus())
                    {
                        if(customer->getBalanceAmount() == 0)
                        {
                            cout<<carName<<" Car is returned"<<endl;
                            customer->setVehicleStatus("Returned");
                        }
                        else
                        {
                            cout<<"Please pay balance Amount of "<<customer->getBalanceAmount()<<" rupees"<<endl;
                            success = this->payment(customer->getBalanceAmount());
                            if(success)
                            {
                                customer->setAmountPaid(customer->getAmountPaid()+customer->getBalanceAmount());
                                customer->setBalanceAmount(0);
                                cout<<carName<<" Car is returned"<<endl;
                                customer->setVehicleStatus("Returned");
                                customer->setPaymentStatus("Success");
                            }

                        }
                    }

                }
                car->setVehicleStatus("Available");
            }

        }
    }
}

void Vehicle_Manager::displayBikeList()
{
    cout<<"bikeName";
    cout.width(20);
    cout<<"bikeModel";
    cout.width(20);
    cout<<"bikeNumber";
    cout.width(20);
    cout<<"BikeCost";
    cout.width(20);
    cout<<"BikeStatus"<<endl;

    for(auto* bike:m_bikeList)
    {
        if("Available" == bike->getVehicleStatus() || "Booked" == bike->getVehicleStatus())
        {
            cout<<bike->getVehicleName();
            cout.width(20);
            cout<<bike->getVehicleModel();
            cout.width(21);
            cout<<bike->getVehicleNumber();
            cout.width(21);
            cout<<bike->getVehicleCost();
            cout.width(24);
            cout<<bike->getVehicleStatus()<<endl;
        }
    }
}

void Vehicle_Manager::displayCarList()
{
    cout<<"carName";
    cout.width(30);
    cout<<"carModel";
    cout.width(30);
    cout<<"carNumber";
    cout.width(30);
    cout<<"CarCost";
    cout.width(30);
    cout<<"CarStatus"<<endl;

    for(auto* car:m_carList)
    {
        if("Available" == car->getVehicleStatus() || "Booked" == car->getVehicleStatus())
        {
            cout<<car->getVehicleName();
            cout.width(30);
            cout<<car->getVehicleModel();
            cout.width(30);
            cout<<car->getVehicleNumber();
            cout.width(30);
            cout<<car->getVehicleCost();
            cout.width(30);
            cout<<car->getVehicleStatus()<<endl;
        }
    }
}

void Vehicle_Manager::displayCustomerList()
{
    cout<<"CustomerName ";
    cout.width(10);
    cout<<"BookingID ";
    cout.width(10);
    cout<<"VehicleName ";
    cout.width(10);
    cout<<"VehicleModel ";
    cout.width(10);
    cout<<"VehicleNum ";
    cout.width(10);
    cout<<"RentalDuration ";
    cout.width(10);
    cout<<"PaymentMode ";
    cout.width(10);
    cout<<"paymentID ";
    cout.width(10);
    cout<<"TransactionID ";
    cout.width(10);
    cout<<"VehicleStatus ";
    cout.width(10);
    cout<<"AmountPaid ";
    cout.width(10);
    cout<<"DueAmount ";
    cout.width(10);
    cout<<"PaymentStatus"<<endl;

    for(auto* i:m_customerList)
    {
        cout<<i->getCusName();
        cout.width(12);
        cout<<i->getBookingID();
        cout.width(12);
        cout<<i->getVehicleName();
        cout.width(12);
        cout<<i->getVehicleModel();
        cout.width(12);
        cout<<i->getVehicleNumber();
        cout.width(12);
        cout<<i->getRentalDuration();
        cout.width(12);
        cout<<i->getPaymentType();
        cout.width(16);
        cout<<i->getID();
        cout.width(12);
        cout<<i->getTransactionID();
        cout.width(12);
        cout<<i->getVehicleStatus();
        cout.width(12);
        cout<<i->getAmountPaid();
        cout.width(12);
        cout<<i->getBalanceAmount();
        cout.width(12);
        cout<<i->getpaymentStatus()<<endl;
    }
}

void Vehicle_Manager::updateBikeCost()
{
    float bikeNewAmount;
    string bikeNumber, bikeName;
    cout<<"Enter vehicle name to update price"<<endl;
    cin>>bikeName;
    cout<<"Enter vehicle number to update price"<<endl;
    cin>>bikeNumber;
    cout<<"Enter updated bike cost"<<endl;
    cin>>bikeNewAmount;
    for(auto* bike:m_bikeList)
    {
        if(bike->getVehicleNumber() == bikeNumber)
        {
            bike->setVehicleCost(bikeNewAmount);
            cout<<bikeName<<" with vehicle number "<<bikeNumber<<" updated"<<endl;
        }
    }
}

void Vehicle_Manager::updateCarCost()
{
    float CarnewAmount;
    string carNumber, carName;
    cout<<"Enter vehicle name to update price"<<endl;
    cin>>carName;
    cout<<"Enter vehicle number to update price"<<endl;
    cin>>carNumber;
    cout<<"Enter updated bike cost"<<endl;
    cin>>CarnewAmount;
    for(auto* car:m_carList)
    {
        if(car->getVehicleName() == carName && car->getVehicleNumber() == carNumber)
        {
            car->setVehicleCost(CarnewAmount);
            cout<<carName<<" with vehicle number "<<carNumber<<" updated"<<endl;
        }
    }
}

int Vehicle_Manager::payment(float balanceAmount)
{
    int choice,success = 0;
    string paymentMode;
    float amountPaid;
    cout<<"Enter Payment mode"<<endl;
    cout<<"Enter"<<endl<<"1. Cash"<<endl<<"2. UPI"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        paymentMode = "Cash";
        cout<<"Pay "<<balanceAmount<<" rupees"<<endl;
        cout<<"Enter Amount"<<endl;
        cin>>amountPaid;
        if(amountPaid == balanceAmount)
        {
            cout<<"Amount of rupees "<<amountPaid<<" recieved through "<<paymentMode<<endl;
            success = 1;
        }

    }
    else if (choice == 2)
    {
        string upiID;
        int transactionID = 2000;
        paymentMode = "UPI";
        cout<<"Enter UPI ID"<<endl;
        cin>>upiID;
        cout<<"Pay "<<balanceAmount<<" ruppees"<<endl;
        cout<<"Enter Amount"<<endl;
        cin>>amountPaid;
        if(amountPaid  == balanceAmount)
        {
            cout<<"Amount of rupees "<<amountPaid<<" recieved through"<<paymentMode<<endl;
            cout<<"Transaction successfull"<<endl;
            cout<<"Transaction ID :"<<++transactionID<<endl;
            success = 1;
        }
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    return success;

}
