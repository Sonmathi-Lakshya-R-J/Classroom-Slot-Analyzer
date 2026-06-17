#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "classroom.h"
#include "booking.h"
#include "login.h"
#include "timetable.h"
#include "analyzer.h"

using namespace std;

int main()
{
    Login login;
    Timetable timetable;
    Analyzer analyzer;

    bool loggedIn = false;
    string currentRole = "";
    string currentUser = "";

    int choice;

    do
    {
        cout << "\n===================================";
        cout << "\n CLASSROOM SLOT ANALYZER SYSTEM";
        cout << "\n===================================\n";

        // NOT LOGGED IN
        if(!loggedIn)
        {
            cout << "\n1. Login";
            cout << "\n2. Exit";
        }

        // ADMIN MENU
        else if(currentRole == "ADMIN")
        {
            cout << "\nLogged In As: " << currentUser << " (ADMIN)";

            cout << "\n1. Logout";
            cout << "\n2. Upload Timetable";
            cout << "\n3. View Timetable";
            cout << "\n4. Manage Booking Requests";
            cout << "\n5. View Conflict Log";
            cout << "\n6. Exit";
        }

        // FACULTY MENU
        else if(currentRole == "FACULTY")
        {
            cout << "\nLogged In As: " << currentUser << " (FACULTY)";
            cout << "\n\n1. Logout";
            cout << "\n2. View Schedule";
            cout << "\n3. Find Free Slots";
            cout << "\n4. Book Classroom";
            cout << "\n5. View My Requests";
            cout << "\n6. Exit";
        }

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        // =========================
        // NOT LOGGED IN OPTIONS
        // =========================

        if(!loggedIn)
        {
            switch(choice)
            {
                case 1:
                {
                    string username;
                    string password;

                    cout << "\nUsername: ";
                    cin >> username;

                    cout << "Password: ";
                    cin >> password;

                    if(login.authenticate(username,password))
                    {
                        loggedIn = true;

                        currentUser = username;

                        currentRole = login.getRole();

                        cout << "\nLogin Successful!";
                        cout << "\nUser: " << currentUser;
                        cout << "\nRole: " << currentRole << endl;
                    }
                    else
                    {
                        cout << "\nInvalid Credentials!" << endl;
                    }

                    break;
                }

                case 2:
                {
                    cout << "\nExiting System...\n";
                    exit(0);
                    break;
                }

                default:
                {
                    cout << "\nPlease Login First!\n";
                }
            }
        }

        // =========================
        // ADMIN MENU
        // =========================

        else if(currentRole == "ADMIN")
        {
            switch(choice)
            {
                case 1:
                {
                    loggedIn = false;
                    currentRole = "";
                    currentUser = "";

                    cout << "\nLogged Out Successfully!\n";
                    break;
                }

                case 2:
                {
                    string filePath;

                    cout << "\nEnter CSV File Path: ";
                    cin >> filePath;

                    if(timetable.loadCSV(filePath))
                    {
                        cout << "\nTimetable Loaded Successfully!\n";
                    }
                    else
                    {
                        cout << "\nFailed To Load Timetable!\n";
                    }

                    break;
                }

                case 3:
                {
                    if(timetable.loadCSV("../data/timetable.csv"))
                    {
                        int sectionChoice;

                        cout << "\nSelect Section\n";

                        cout << "\n1. CSE-A";
                        cout << "\n2. CSE-B";
                        cout << "\n3. CSE-C";
                        cout << "\n4. CSE-D";
                        cout << "\n5. Back";

                        cout << "\n\nChoice: ";
                        cin >> sectionChoice;

                        switch(sectionChoice)
                        {
                            case 1:
                                timetable.displaySectionSchedule("CSE-A");
                                break;

                            case 2:
                                timetable.displaySectionSchedule("CSE-B");
                                break;

                            case 3:
                                timetable.displaySectionSchedule("CSE-C");
                                break;

                            case 4:
                                timetable.displaySectionSchedule("CSE-D");
                                break;

                            case 5:
                                break;

                            default:
                                cout << "\nInvalid Choice!\n";
                        }
                    }

                    break;
                }

                case 4:
                {
                    Booking booking;

                    booking.viewAllRequests();

                    int requestChoice;

                    cout << "\n1. Modify Request";
                    cout << "\n2. Back";

                    cout << "\n\nChoice: ";
                    cin >> requestChoice;

                    if(requestChoice == 1)
                    {
                        string requestId;

                        cout << "\nEnter Request ID: ";
                        cin >> requestId;

                        cout << "\nCurrent Request Selected: "
                            << requestId
                            << endl;

                        int action;

                        cout << "\n1. Approve";
                        cout << "\n2. Reject";
                        cout << "\n3. Back";

                        cout << "\n\nChoice: ";
                        cin >> action;

                        if(action == 1)
                        {
                            if(
                                booking.approveRequest(
                                    requestId
                                )
                            )
                            {
                                cout
                                << "\nRequest Approved Successfully!\n";
                            }
                            else
                            {
                                cout
                                << "\nRequest Not Found!\n";
                            }
                        }

                        else if(action == 2)
                        {
                            string reason;

                            cin.ignore();

                            cout << "\nReason: ";

                            getline(
                                cin,
                                reason
                            );

                            if(
                                booking.rejectRequest(
                                    requestId,
                                    reason
                                )
                            )
                            {
                                cout
                                << "\nRequest Rejected Successfully!\n";
                            }
                            else
                            {
                                cout
                                << "\nRequest Not Found!\n";
                            }
                        }

                        else if(action == 3)
                        {
                            cout
                            << "\nReturning...\n";
                        }

                        else
                        {
                            cout
                            << "\nInvalid Choice!\n";
                        }
                    }

                    else if(requestChoice == 2)
                    {
                        cout
                        << "\nReturning...\n";
                    }

                    else
                    {
                        cout
                        << "\nInvalid Choice!\n";
                    }

                    break;
                }

                case 5:
                {
                    Analyzer analyzer;
                    analyzer.viewConflictLog();
                    break;
                }
                case 6:
                {
                    cout << "\nExiting System...\n";
                    break;
                }

                default:
                {
                    cout << "\nInvalid Choice!\n";
                }
            }
        }

        // =========================
        // FACULTY MENU
        // =========================

        else if(currentRole == "FACULTY")
        {
            switch(choice)
            {
                case 1:
                {
                    loggedIn = false;
                    currentRole = "";
                    currentUser = "";
                    
                    cout << "\nLogged Out Successfully!\n";
                    break;
                }

                case 2:
                {
                    if(timetable.loadCSV("../data/timetable.csv"))
                    {
                        timetable.displayFacultyGrid(currentUser);
                    }

                    break;
                }

                case 3:
                {
                    string roomId;

                    cout << "\nEnter Room ID: ";
                    cin >> roomId;

                    vector<string> startTimes;
                    vector<string> endTimes;

                    ifstream file("../data/timetable.csv");

                    string line;

                    while(getline(file, line))
                    {
                        stringstream ss(line);

                        string day;
                        string start;
                        string end;
                        string room;

                        getline(ss, day, ',');
                        getline(ss, start, ',');
                        getline(ss, end, ',');
                        getline(ss, room, ',');

                        if(room == roomId)
                        {
                            startTimes.push_back(start);
                            endTimes.push_back(end);
                        }
                    }

                    file.close();

                    if(startTimes.empty())
                    {
                        cout << "\nNo schedule found for "
                            << roomId << endl;
                    }
                    else
                    {
                        analyzer.findFreeSlots(
                            startTimes,
                            endTimes
                        );
                    }

                    break;
                }

                case 4:
                {
                    int bookingType;

                    cout << "\nBooking Type";
                    cout << "\n1. One-Day Booking";
                    cout << "\n2. Permanent Weekly Booking";

                    cout << "\n\nEnter Choice: ";
                    cin >> bookingType;

                    if(bookingType == 1)
                    {
                        string roomId;
                        string date;
                        string startTime;
                        string endTime;

                        cout << "\nRoom ID: ";
                        cin >> roomId;

                        cout << "Date: ";
                        cin >> date;

                        cout << "Start Time (HH:MM): ";
                        cin >> startTime;

                        cout << "End Time (HH:MM): ";
                        cin >> endTime;

                        cout << "\nChecking Availability...\n";

                        Booking booking;
                        Analyzer analyzer;

                        bool conflict =
                            analyzer.checkConflict(
                                roomId,
                                date,
                                startTime,
                                endTime
                            );

                        if(conflict)
                        {
                            cout << "\nConflict Detected!\n";

                            int requiredCapacity;

                            cout << "\nRequired Capacity: ";
                            cin >> requiredCapacity;

                            vector<string> rooms =
                                analyzer.suggestAlternativeRooms(
                                    roomId,
                                    requiredCapacity
                                );

                            cout << "\nSuggested Rooms:\n";

                            for(string room : rooms)
                            {
                                cout << room << endl;
                            }
                        }
                        else
                        {
                            booking.setBookingId(
                                booking.generateBookingId()
                            );

                            booking.setFacultyId(currentUser);

                            booking.setRoomId(roomId);

                            booking.setBookingType("ONE_DAY");

                            booking.setDate(date);

                            booking.setStartTime(startTime);
                            booking.setEndTime(endTime);

                            booking.setStatus("APPROVED");

                            booking.saveBooking();

                            cout << "\nBooking Confirmed!\n";
                        }
                    }
                    else if(bookingType == 2)
                    {
                        string roomId;
                        string day;
                        string startTime;
                        string endTime;
                        string startDate;
                        string endDate;

                        cout << "\nRoom ID: ";
                        cin >> roomId;

                        cout << "Day: ";
                        cin >> day;

                        cout << "Start Time (HH:MM): ";
                        cin >> startTime;

                        cout << "End Time (HH:MM): ";
                        cin >> endTime;

                        cout << "Start Date: ";
                        cin >> startDate;

                        cout << "End Date: ";
                        cin >> endDate;

                        Booking request;

                        request.setBookingId(
                            request.generateRequestId()
                        );

                        request.setFacultyId(currentUser);

                        request.setRoomId(roomId);

                        request.setBookingType("PERMANENT");

                        request.setDayOfWeek(day);

                        request.setStartTime(startTime);
                        request.setEndTime(endTime);

                        request.setStartDate(startDate);
                        request.setEndDate(endDate);

                        string reason;

                        cin.ignore();

                        cout << "\nPurpose: ";
                        getline(cin, reason);

                        request.setReason(reason);

                        request.setStatus("PENDING");

                        request.savePermanentRequest();

                        cout << "\nRequest Submitted!";
                        cout << "\nStatus: PENDING\n";
                    }

                    break;
                }

                case 5:
                {
                    Booking booking;

                    booking.viewRequests(
                        currentUser
                    );

                    break;
                }

                case 6:
                {
                    cout << "\nExiting System...\n";
                    break;
                }

                default:
                {
                    cout << "\nInvalid Choice!\n";
                }
            }
        }

    }
    while(choice != 6);

    return 0;
}