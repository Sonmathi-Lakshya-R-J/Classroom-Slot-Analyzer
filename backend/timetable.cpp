#include "timetable.h"
#include<iomanip>
#include<map>


bool Timetable::loadCSV(string fileName)
{
    day.clear();
    startTime.clear();
    endTime.clear();
    room.clear();
    faculty.clear();
    subject.clear();
    section.clear();

    ifstream file(fileName);

    if(!file)
    {
        cout << "Unable to open CSV file." << endl;
        return false;
    }

    string line;

    getline(file, line);

    while(getline(file, line))
    {
        stringstream ss(line);

        string d;
        string st;
        string et;
        string r;
        string f;
        string s;
        string sec;

        getline(ss, sec, ',');
        getline(ss, d, ',');
        getline(ss, st, ',');
        getline(ss, et, ',');
        getline(ss, r, ',');
        getline(ss, f, ',');
        getline(ss, s, ',');

        day.push_back(d);
        startTime.push_back(st);
        endTime.push_back(et);
        room.push_back(r);
        faculty.push_back(f);
        subject.push_back(s);
        section.push_back(sec);
    }

    file.close();

    return true;
}




vector<string> Timetable::getDay()
{
    return day;
}

vector<string> Timetable::getStartTime()
{
    return startTime;
}

vector<string> Timetable::getEndTime()
{
    return endTime;
}

vector<string> Timetable::getRoom()
{
    return room;
}




void Timetable::displayFacultyGrid(
    string facultyName)
{
    vector<string> days =
    {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday"
    };

    vector<string> slots =
    {
        "08:00",
        "09:00",
        "10:00",
        "11:00",
        "12:00",
        "13:00",
        "14:00",
        "15:00"
    };

    map<pair<string,string>, string> timetableMap;

    for(int i = 0; i < faculty.size(); i++)
    {
        if(faculty[i] == facultyName)
        {
            timetableMap[
                {day[i], startTime[i]}
            ] =
            subject[i] +
            "(" +
            room[i] +
            ")";
        }
    }

    cout << "\n=========================================================================================================================\n";

    cout << "FACULTY : "
         << facultyName
         << endl;

    cout << "=========================================================================================================================\n";

    cout << left
         << setw(12)
         << "DAY";

    for(string slot : slots)
    {
        cout
        << setw(15)
        << slot;
    }

    cout << endl;

    cout << "=========================================================================================================================\n";

    for(string d : days)
    {
        cout
        << left
        << setw(12)
        << d;

        for(string slot : slots)
        {
            string value = "";

            if(
                timetableMap.find(
                    {d, slot}
                )
                != timetableMap.end()
            )
            {
                value =
                    timetableMap[
                        {d, slot}
                    ];
            }

            cout
            << setw(15)
            << value;
        }

        cout << endl;
    }

    cout << "=========================================================================================================================\n";
}


void Timetable::displaySectionSchedule(
    string sectionName)
{
    vector<string> days =
    {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday"
    };

    vector<string> slots =
    {
        "08:00",
        "09:00",
        "10:00",
        "11:00",
        "12:00",
        "13:00",
        "14:00",
        "15:00"
    };

    map<pair<string,string>, string> timetableMap;

    for(int i = 0; i < section.size(); i++)
    {
        if(section[i] == sectionName)
        {
            timetableMap[
                {day[i], startTime[i]}
            ] =
            subject[i] +
            "(" +
            room[i] +
            ")";
        }
    }

    cout << "\n==============================================================================================================================\n";

    cout << "SECTION : "
         << sectionName
         << endl;

    cout << "==============================================================================================================================\n";

    cout << left
         << setw(12)
         << "DAY";

    for(string slot : slots)
    {
        cout
        << setw(15)
        << slot;
    }

    cout << endl;

    cout << "==============================================================================================================================\n";

    for(string d : days)
    {
        cout
        << left
        << setw(12)
        << d;

        for(string slot : slots)
        {
            string value = "";

            if(
                timetableMap.find(
                    {d, slot}
                )
                != timetableMap.end()
            )
            {
                value =
                    timetableMap[
                        {d, slot}
                    ];
            }

            cout
            << setw(15)
            << value;
        }

        cout << endl;
    }

    cout << "==============================================================================================================================\n";
}

