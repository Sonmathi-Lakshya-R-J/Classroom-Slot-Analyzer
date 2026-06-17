#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Booking
{
private:

    string bookingId;
    string facultyId;
    string roomId;

    string bookingType;

    string date;
    string dayOfWeek;

    string startDate;
    string endDate;

    string startTime;
    string endTime;

    string reason;

    string status;

public:

    Booking();

    Booking(
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
        string status
    );

    // Setters

    void setBookingId(string bookingId);
    void setFacultyId(string facultyId);
    void setRoomId(string roomId);
    void setBookingType(string bookingType);

    void setDate(string date);
    void setDayOfWeek(string dayOfWeek);

    void setStartDate(string startDate);
    void setEndDate(string endDate);

    void setStartTime(string startTime);
    void setEndTime(string endTime);

    void setReason(string reason);
    void setStatus(string status);

    // Getters

    string getBookingId();
    string getFacultyId();
    string getRoomId();
   // string getBookingType();

  //  string getDate();
    // string getDayOfWeek();

    // string getStartDate();
    // string getEndDate();

  //  string getStartTime();
  //  string getEndTime();

   // string getReason();
    string getStatus();

    // Display

    //void display();

    // File Operations

    bool saveBooking();
    bool savePermanentRequest();
    string generateBookingId();
    string generateRequestId();

    void viewRequests(string facultyId);
    void viewAllRequests();
    bool approveRequest(string requestId);
    bool rejectRequest(string requestId,string reason);

    
};




#endif