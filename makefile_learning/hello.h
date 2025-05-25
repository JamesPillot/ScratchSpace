#ifndef HELLO_H
#define HELLO_H
#include <string>
#include <iostream>

class Hello
{
public:
    Hello();
    void greet_person(std::string name);
    void wave();
    int new_func();
private:
    int _y = 4;
};
#endif //HELLO_H