#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Analyzer
{
public:

    bool isConflict(
        string start1,
        string end1,
        string start2,
        string end2
    );
    int timeToMinutes(string time);
    void findFreeSlots(vector<string> startTimes, vector<string> endTimes);

    // string suggestBestRoom(
    //     vector<string> roomIds,
    //     vector<int> capacities,
    //     int requiredCapacity
    // );


    bool logConflict(
        string roomId,
        string date,
        string existingStart,
        string existingEnd,
        string requestedStart,
        string requestedEnd,
        string facultyId
    );

    bool checkConflict(
    string roomId,
    string date,
    string startTime,
    string endTime
    );

    vector<string> suggestAlternativeRooms(string requestedRoom, int requiredCapacity);
    
    void viewConflictLog();



};

#endif