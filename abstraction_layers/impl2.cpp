#include <iostream>

#include "interface.h"

Hello::Hello()
{
    std::cout << "Class init for spanish implementation" << std::endl;
}

void Hello::sayHello()
{   
    std::cout << "Hola" << std::endl;
}