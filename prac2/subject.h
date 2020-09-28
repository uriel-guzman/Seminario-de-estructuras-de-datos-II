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

    void setName(const string &);
    void setID(const string &);
    void setNRC(const string &);
    void setProfessorName(const string &);
    void setAvailableDays(int);
    void setStartTime(const string &);
    void setEndTime(const string &);
    void setSection(const string &);

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
