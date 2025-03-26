cmake_minimum_required(VERSION 3.16)

project(VehicleManagementSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VehicleManagementSystem main.cpp
    Rental_Vehicle_details.h Rental_Vehicle_details.cpp
    Rental_bike_details.h Rental_bike_details.cpp
    Rental_Car_details.h Rental_Car_details.cpp
    Rental_Customer_details.h Rental_Customer_details.cpp
    PaymentMode.h PaymentMode.cpp
    Cash.h Cash.cpp
    UPI.h UPI.cpp

    Login_Management.h Login_Management.cpp
    User.h User.cpp
    Vehicle_Manager.h Vehicle_Manager.cpp
    Car_FileOperation.h Car_FileOperation.cpp
    Bike_FileOperation.h Bike_FileOperation.cpp
    Customer_FileOperation.h Customer_FileOperation.cpp
    User_FileOperation.h User_FileOperation.cpp)

include(GNUInstallDirs)
install(TARGETS VehicleManagementSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
