#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <iostream>
#include <string>

using namespace std;

class Classroom
{
private:
    string roomId;
    int capacity;
    string roomType;

public:

    Classroom();
    Classroom(
        string roomId,
        int capacity,
        string roomType
    );

    void setRoomId(string roomId);
    void setCapacity(int capacity);
    void setRoomType(string roomType);

    string getRoomId();
    int getCapacity();
    string getRoomType();

    void display();
};

#endif