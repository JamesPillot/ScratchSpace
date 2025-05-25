#include "hello.h"

int main()
{
    Hello obj1;
    obj1.greet_person("James P.");
    obj1.wave();
    std::cout << obj1.new_func() << std::endl;
    return 0;
}