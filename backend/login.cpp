#include "login.h"

bool Login::authenticate(
    string username,
    string password)
{
    ifstream file("../data/users.txt");

    if(!file)
    {
        cout << "Unable to open users file." << endl;
        return false;
    }

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string storedUser;
        string storedPass;
        string storedRole;

        getline(ss, storedUser, ',');
        getline(ss, storedPass, ',');
        getline(ss, storedRole, ',');

        if(storedUser == username &&
           storedPass == password)
        {
            currentRole = storedRole;

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

string Login::getRole()
{
    return currentRole;
}