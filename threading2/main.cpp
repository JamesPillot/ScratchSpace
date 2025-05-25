#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
#include <mutex>

std::mutex carMutex;

void driveCar(std::string driverName)
{
    std::lock_guard<std::mutex> carlock(carMutex);
    std::cout << driverName << " is driving" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); 
    std::cout << driverName << " is done driving" << std::endl;
}

int main()
{
    std::thread t1(driveCar, "James");
    std::thread t2(driveCar, "Jim");

    t1.join();
    t2.join();
    return 0;
}