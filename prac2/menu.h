#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "subject.h"
using namespace std;

class Menu {
  public:
    void showSubject(Subj);
    void addSubject(vector<Subj> &);
    void modifySubject(vector<Subj> &);
    void showAllSubjects(const vector<Subj> &);
    void showAllSubjectsOrdered(const vector<Subj> &);
    void findSubject(const vector<Subj> &);
    void tempDelSubject(vector<Subj> &, vector<Subj> &);
    void recoverSubject(vector<Subj> &, vector<Subj> &);
    void permDelSubject(vector<Subj> &);
};

#endif /* MENU_h */
