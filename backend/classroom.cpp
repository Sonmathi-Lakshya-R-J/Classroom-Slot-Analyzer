#include "classroom.h"

Classroom::Classroom()
{
    roomId = "";
    capacity = 0;
    roomType = "";
}

Classroom::Classroom(
    string roomId,
    int capacity,
    string roomType)
{
    this->roomId = roomId;
    this->capacity = capacity;
    this->roomType = roomType;
}

void Classroom::setRoomId(string roomId)
{
    this->roomId = roomId;
}

void Classroom::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void Classroom::setRoomType(string roomType)
{
    this->roomType = roomType;
}

string Classroom::getRoomId()
{
    return roomId;
}

int Classroom::getCapacity()
{
    return capacity;
}

string Classroom::getRoomType()
{
    return roomType;
}

void Classroom::display()
{
    cout << "Room ID: "
         << roomId
         << endl;

    cout << "Capacity: "
         << capacity
         << endl;

    cout << "Type: "
         << roomType
         << endl;
}