#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Login
{
private:
    string currentRole;

public:
    bool authenticate(
        string username,
        string password
    );

    string getRole();
};

#endif