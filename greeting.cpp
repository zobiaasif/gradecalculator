#include "Greeting.h"
#include <iostream>
#include <ctime>

// Function to display a time-based greeting
void displayGreeting() {
    std::time_t current_time = std::time(nullptr);
    std::tm* local_time = std::localtime(&current_time);
    int hour = local_time->tm_hour;

    if (hour < 12) {
        std::cout << "Good Morning!\n\n";
    } else if (hour < 18) {
        std::cout << "Good Afternoon!\n\n";
    } else {
        std::cout << "Good Evening!\n\n";
    }
}