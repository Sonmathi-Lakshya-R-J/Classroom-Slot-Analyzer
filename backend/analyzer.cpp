#include "analyzer.h"
#include <vector>
#include <fstream>
#include <sstream>

bool Analyzer::isConflict(
    string start1,
    string end1,
    string start2,
    string end2)
{
    int s1 = timeToMinutes(start1);
    int e1 = timeToMinutes(end1);

    int s2 = timeToMinutes(start2);
    int e2 = timeToMinutes(end2);

    if(s1 < e2 && s2 < e1)
    {
        return true;
    }

    return false;
}

void Analyzer::findFreeSlots(vector<string> startTimes, vector<string> endTimes)
{
    cout << "\nFree Slots:\n";

    for(int i = 0; i < startTimes.size()-1; i++)
    {
        int currentEnd =
            timeToMinutes(endTimes[i]);

        int nextStart =
            timeToMinutes(startTimes[i+1]);

        if(nextStart > currentEnd)
        {
            cout
            << endTimes[i]
            << " - "
            << startTimes[i+1]
            << endl;
        }
    }
}



int Analyzer::timeToMinutes(string time)
{ 
    int hours =
        stoi(time.substr(0,2));

    int minutes =
        stoi(time.substr(3,2));

    return hours * 60 + minutes;
}


bool Analyzer::checkConflict(
    string roomId,
    string date,
    string startTime,
    string endTime)
{
    ifstream file("../data/bookings.txt");

    if(!file)
    {
        return false;
    }

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string bookingId;
        string facultyId;
        string storedRoom;
        string storedDate;
        string storedStart;
        string storedEnd;
        string status;

        getline(ss, bookingId, ',');
        getline(ss, facultyId, ',');
        getline(ss, storedRoom, ',');
        getline(ss, storedDate, ',');
        getline(ss, storedStart, ',');
        getline(ss, storedEnd, ',');
        getline(ss, status, ',');

        if(storedRoom == roomId &&
           storedDate == date)
        {
            int reqStart =
                timeToMinutes(startTime);

            int reqEnd =
                timeToMinutes(endTime);

            int exStart =
                timeToMinutes(storedStart);

            int exEnd =
                timeToMinutes(storedEnd);

            if(reqStart < exEnd &&
               reqEnd > exStart)
            {
                file.close();

                logConflict(
                    roomId,
                    date,
                    storedStart,
                    storedEnd,
                    startTime,
                    endTime,
                    facultyId
                );

                return true;
            }
        }
    }

    file.close();

    return false;
}



vector<string> Analyzer::suggestAlternativeRooms(string requestedRoom, int requiredCapacity){

    vector<string> suggestions;

    ifstream file("../data/classrooms.txt");

    if(!file)
    {
        return suggestions;
    }

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string roomId;
        string capacityStr;
        string roomType;

        getline(ss, roomId, ',');
        getline(ss, capacityStr, ',');
        getline(ss, roomType, ',');

        int capacity =
            stoi(capacityStr);

        if(roomId != requestedRoom &&
           capacity >= requiredCapacity)
        {
            suggestions.push_back(
                roomId
            );
        }
    }

    file.close();
    return suggestions;
}


void Analyzer::viewConflictLog(){
    ifstream file("../data/conflict_log.txt");

    if(!file){
        cout << "\nNo conflicts found.\n";
        return;
    }

    string line;

    cout << "\n========== CONFLICT LOG ==========\n";

    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}


bool Analyzer::logConflict(
    string roomId,
    string date,
    string existingStart,
    string existingEnd,
    string requestedStart,
    string requestedEnd,
    string facultyId)
{
    ofstream file("../data/conflict_log.txt",ios::app);

    if(!file){
        return false;
    }

    file
    << roomId << ","
    << date << ","
    << existingStart << ","
    << existingEnd << ","
    << requestedStart << ","
    << requestedEnd << ","
    << facultyId
    << endl;

    file.close();

    return true;
}