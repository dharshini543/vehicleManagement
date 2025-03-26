#include "Vehicle_Manager.h"
using namespace std;

int main()
{
    Vehicle_Manager vehicleManager;
    return vehicleManager.main_menu();
}
/*#include <iostream>
#include <chrono>

void someFunction()
{
    // Example function that you want to measure the execution time of
    for (int i = 0; i < 1000000; ++i) {
        // Just a dummy loop
        int x = i * i;
    }
}

int main()
{
    // Record the start time before the code execution
    auto start = std::chrono::high_resolution_clock::now();

    // Call the function or block of code you want to measure
    someFunction();

    // Record the end time after the code execution
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration (difference between end and start)
    std::chrono::duration<double> duration = end - start;

    // Output the execution time in seconds
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}*/
