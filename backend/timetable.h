#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Timetable
{
private:

    vector<string> day;
    vector<string> startTime;
    vector<string> endTime;
    vector<string> room;
    vector<string> faculty;
    vector<string> subject;
    vector<string> section;

public:

    bool loadCSV(string fileName);
    void displaySectionSchedule(string sectionName);
    void displayFacultyGrid(string facultyName);
  

    vector<string> getDay();
    vector<string> getStartTime();
    vector<string> getEndTime();
    vector<string> getRoom();
    
};

#endif