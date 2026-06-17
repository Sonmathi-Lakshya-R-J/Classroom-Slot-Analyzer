#include "booking.h"
#include <vector>
#include <fstream>
#include <sstream>

Booking::Booking(){
    bookingId = "";
    facultyId = "";
    roomId = "";
    bookingType = "";
    date = "";
    dayOfWeek = "";
    startDate = "";
    endDate = "";
    startTime = "";
    endTime = "";
    reason = "";
    status = "";
}

Booking::Booking(
    string bookingId,
    string facultyId,
    string roomId,
    string bookingType,
    string date,
    string dayOfWeek,
    string startDate,
    string endDate,
    string startTime,
    string endTime,
    string reason,
    string status)
{
    this->bookingId = bookingId;
    this->facultyId = facultyId;
    this->roomId = roomId;

    this->bookingType = bookingType;

    this->date = date;
    this->dayOfWeek = dayOfWeek;

    this->startDate = startDate;
    this->endDate = endDate;

    this->startTime = startTime;
    this->endTime = endTime;

    this->reason = reason;

    this->status = status;
}

void Booking::setBookingId(string bookingId){ this->bookingId = bookingId;}

void Booking::setFacultyId(string facultyId){this->facultyId = facultyId;}

void Booking::setRoomId(string roomId){this->roomId = roomId;}

void Booking::setDate(string date){this->date = date;}

void Booking::setStartTime(string startTime){this->startTime = startTime;}

void Booking::setEndTime(string endTime){this->endTime = endTime;}

void Booking::setStatus(string status){this->status = status;}

string Booking::getBookingId(){return bookingId;}

string Booking::getFacultyId(){return facultyId;}

string Booking::getRoomId(){return roomId;}

string Booking::getStatus(){return status;}

void Booking::setBookingType(string bookingType){this->bookingType = bookingType;}

void Booking::setDayOfWeek(string dayOfWeek){this->dayOfWeek = dayOfWeek;}

void Booking::setStartDate(string startDate){this->startDate = startDate;}

void Booking::setEndDate(string endDate){this->endDate = endDate;}

void Booking::setReason(string reason){this->reason = reason;}

bool Booking::saveBooking(){
    ofstream file("../data/bookings.txt", ios::app);

    if(!file){
        cout << "\nUnable to open bookings file.\n";
        return false;
    }

    file
    << bookingId << ","
    << facultyId << ","
    << roomId << ","
    << date << ","
    << startTime << ","
    << endTime << ","
    << status
    << endl;

    file.close();

    return true;
}



bool Booking::savePermanentRequest(){
    ofstream file("../data/permanent_requests.txt",ios::app);

    if(!file){
        cout << "\nUnable to open requests file.\n";
        return false;
    }

    file
    << bookingId << ","
    << facultyId << ","
    << roomId << ","
    << dayOfWeek << ","
    << startTime << ","
    << endTime << ","
    << startDate << ","
    << endDate << ","
    << reason << ","
    << status
    << endl;

    file.close();

    return true;
}

void Booking::viewRequests(string facultyId){
    ifstream file("../data/permanent_requests.txt");

    if(!file){
        cout << "\nUnable to open requests file.\n";
        return;
    }

    string line;

    cout << "\n========== MY REQUESTS ==========\n";

    while(getline(file, line)){
        stringstream ss(line);

        string requestId;
        string storedFaculty;
        string roomId;
        string day;
        string startTime;
        string endTime;
        string startDate;
        string endDate;
        string reason;
        string status;

        getline(ss, requestId, ',');
        getline(ss, storedFaculty, ',');
        getline(ss, roomId, ',');
        getline(ss, day, ',');
        getline(ss, startTime, ',');
        getline(ss, endTime, ',');
        getline(ss, startDate, ',');
        getline(ss, endDate, ',');
        getline(ss, reason, ',');
        getline(ss, status, ',');

        if(storedFaculty == facultyId){
            cout << "\nRequest ID : "
                 << requestId;

            cout << "\nRoom       : "
                 << roomId;

            cout << "\nDay        : "
                 << day;

            cout << "\nTime       : "
                 << startTime
                 << " - "
                 << endTime;

            cout << "\nStatus     : "
                 << status;

            cout << "\n---------------------------\n";
        }
    }

    file.close();
}


void Booking::viewAllRequests(){
    ifstream file("../data/permanent_requests.txt");

    if(!file){
        cout << "\nUnable to open requests file.\n";
        return;
    }
    string line;
    cout << "\n========== ALL REQUESTS ==========\n";
    while(getline(file, line)){
        stringstream ss(line);
        string requestId;
        string facultyId;
        string roomId;
        string day;
        string startTime;
        string endTime;
        string startDate;
        string endDate;
        string reason;
        string status;

        getline(ss, requestId, ',');
        getline(ss, facultyId, ',');
        getline(ss, roomId, ',');
        getline(ss, day, ',');
        getline(ss, startTime, ',');
        getline(ss, endTime, ',');
        getline(ss, startDate, ',');
        getline(ss, endDate, ',');
        getline(ss, reason, ',');
        getline(ss, status, ',');

        cout << "\nRequest ID : "
             << requestId;

        cout << "\nFaculty    : "
             << facultyId;

        cout << "\nRoom       : "
             << roomId;

        cout << "\nDay        : "
             << day;

        cout << "\nTime       : "
             << startTime
             << " - "
             << endTime;

        cout << "\nReason     : "
             << reason;

        cout << "\nStatus     : "
             << status;

        cout << "\n---------------------------\n";
    }
    file.close();
}


bool Booking::approveRequest(string requestId){
    ifstream file("../data/permanent_requests.txt");

    if(!file){
        cout << "\nUnable to open requests file.\n";
        return false;
    }

    vector<string> records;

    string line;
    bool found = false;

    while(getline(file, line)){
        stringstream ss(line);
        string id;
        getline(ss, id, ',');

        if(id == requestId)
        {
            vector<string> fields;

            string field;

            stringstream temp(line);

            while(getline(temp, field, ','))
            {
                fields.push_back(field);
            }

            if(fields.size() >= 10)
            {
                fields[9] = "APPROVED";
            }

            string updatedLine = "";

            for(size_t i = 0; i < fields.size(); i++)
            {
                updatedLine += fields[i];

                if(i != fields.size() - 1)
                {
                    updatedLine += ",";
                }
            }

            records.push_back(updatedLine);

            found = true;
        }
        else
        {
            records.push_back(line);
        }
    }

    file.close();

    ofstream outFile("../data/permanent_requests.txt");

    for(string record : records){
        outFile << record << endl;
    }

    outFile.close();

    return found;
}


bool Booking::rejectRequest(string requestId,string reason){
    ifstream file("../data/permanent_requests.txt");

    if(!file){
        cout << "\nUnable to open requests file.\n";
        return false;
    }

    vector<string> records;

    string line;
    bool found = false;

    while(getline(file, line)){
        stringstream ss(line);
        string id;
        getline(ss, id, ',');
        if(id == requestId){
            vector<string> fields;
            string field;
            stringstream temp(line);
            while(getline(temp, field, ',')){
                fields.push_back(field);
            }

            if(fields.size() >= 10){
                fields[9] = "REJECTED";
            }
            string updatedLine;
            for(size_t i = 0; i < fields.size(); i++){
                updatedLine += fields[i];

                if(i != fields.size() - 1){
                    updatedLine += ",";
                }
            }
            records.push_back(updatedLine);
            found = true;
        }
        else{
            records.push_back(line);
        }
    }

    file.close();

    ofstream outFile("../data/permanent_requests.txt");

    for(string record : records){
        outFile << record << endl;
    }

    outFile.close();

    return found;
}

string Booking::generateBookingId(){
    ifstream file("../data/bookings.txt");
    int count = 0;
    string line;
    while(getline(file, line)){
        count++;
    }
    file.close();
    count++;
    string id = "B";
    if(count < 10)
        id += "00";
    else if(count < 100)
        id += "0";

    id += to_string(count);
    return id;
}

string Booking::generateRequestId(){
    ifstream file("../data/permanent_requests.txt");
    int count = 0;
    string line;

    while(getline(file, line)){
        count++;
    }

    file.close();

    count++;

    string id = "P";

    if(count < 10)
        id += "00";
    else if(count < 100)
        id += "0";

    id += to_string(count);

    return id;
}