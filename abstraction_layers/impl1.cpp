#include <iostream>

#include "interface.h"

Hello::Hello()
{
    std::cout << "Class init for english implementation" << std::endl;
}

void Hello::sayHello()
{   
    std::cout << "Hello" << std::endl;
}