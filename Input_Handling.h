#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H
#include <iostream>

using namespace std;

class Invalid_Input
{
    private:
    Invalid_Input();
    public:
    Invalid_Input(string in_ptr) : msg_ptr (in_ptr) {}
    const string msg_ptr;
    
    
};

#endif