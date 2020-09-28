#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
using namespace std;

class Subj {
  private:
    string name;
    string ID;
    string NRC;
    string professorName;
    int availableDays;
    string startTime;
    string endTime;
    string section;
  public:
    void readSubject();

    void setName(const string &name);
    void setID(const string &ID);
    void setNRC(const string &NRC);
    void setProfessorName(const string &professorName);
    void setAvailableDays(int availableDays);
    void setStartTime(const string &startTime);
    void setEndTime(const string &endTime);
    void setSection(const string &section);

    string getName();
    string getID();
    string getNRC();
    string getProfessorName();
    int getAvailableDays();
    string getStartTime();
    string getEndTime();
    string getSection();
};

#endif /* SUBJECT_H */
