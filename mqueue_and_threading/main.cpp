#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

void refresh_forecast(std::map<std::string, int> weather_map)
{
    while(1)
    {
        for (auto& city : weather_map)
        {
            city.second++;
            std::cout << city.first << " - " << city.second << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void say_hello()
{
    while(1)
    {
        std::cout << "Hello" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::map<std::string, int> weather_map = {
        {"NYC", 20},
        {"LA", 60},
        {"SF", 54}
    };

    std::thread background_weather_check(refresh_forecast, weather_map);
    std::thread hello_thread(say_hello);
    background_weather_check.join();
    hello_thread.join();

    return 0;
}