#include "hello.h"

Hello::Hello()
{
    std::cout << "Hello world " << std::endl;
}

void Hello::greet_person(std::string name)
{
    std::cout << "Hello " << name << std::endl;
}

void Hello::wave()
{
    std::cout << "Waving" << std::endl;
}

int Hello::new_func()
{
    return _y;
}