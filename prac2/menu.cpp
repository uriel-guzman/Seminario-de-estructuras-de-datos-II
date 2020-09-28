#include "menu.h"
#include "algorithm"

void Menu::showSubject(Subj subj) {
  cout << '\n';

  cout << '\t' << "Name: " << subj.getName() << '\n';

  cout << '\t' << "ID: " << subj.getID() << '\n';

  cout << '\t' << "NRC: " << subj.getNRC() << '\n';

  cout << '\t' << "Professor name: " << subj.getProfessorName() << '\n';

  if (subj.getAvailableDays() == 0)
    cout << "\t" << "No available days\n";
  else {
    cout << "\tAvailable days: \n";

    string days[7] = {
      "Monday",
      "Tuesday",
      "Wednesday",
      "Thursday",
      "Friday",
      "Saturday",
      "Sunday"
    };

    for (int i = 0; i < 7; ++i) 
      if (subj.getAvailableDays() & (1 << i)) 
        cout << "\t\t" << days[i] << '\n';
  }

  cout << '\t' << "Start time: " << subj.getStartTime() << '\n';

  cout << '\t' << "End time: " << subj.getEndTime() << '\n';

  cout << '\t' << "Section: " << subj.getSection() << '\n';

  cout << '\n';
}

void Menu::addSubject(vector<Subj>& subjects) {
  Subj subj;
  subj.readSubject();
  subjects.push_back(subj);
}

void Menu::modifySubject(vector<Subj>& subjects) {
  string NRC;
  
  cout << "NRC: ";
  cin >> NRC;
  bool found = false;

  for (Subj &subj : subjects)
    if (subj.getNRC() == NRC) {
      found = true;
      char op;
      do {
        cout << "1) Name\n";
        cout << "2) ID\n";
        cout << "3) Professor name\n";
        cout << "4) Available days\n";
        cout << "5) Start time\n";
        cout << "6) End time\n";
        cout << "7) Section\n";
        cout << "0) Exit\n";
        cout << "Attribute to modify: ";
        cin >> op;
        
        switch (op) {
          case '1': {
            string name;
            cout << "New name: ";
            cin.ignore();
            getline(cin, name);
            subj.setName(name);
            break;
            }
          case '2': {
            string ID;
            cout << "New ID: ";
            cin >> ID;
            subj.setID(ID);
            break;
          }
          case '3': {
            string professorName;
            cout << "New professor name: ";
            cin.ignore();
            getline(cin, professorName);
            subj.setProfessorName(professorName);
            break;
          }
          case '4': {
            string days[7] = {
              "Monday",
              "Tuesday",
              "Wednesday",
              "Thursday",
              "Friday",
              "Saturday",
              "Sunday"
            };

            cout << "Select available days [y/n]\n";
            
            subj.resetAvailableDays();

            for (int i = 0; i < 7; ++i) {
              cout << days[i] << "? ";
              char op;
              cin >> op;
              if (op == 'y')
                subj.setAvailableDays(i);
            }
            break;
          }
          case '5': {
            string startTime;
            cout << "New start time [hhmm]: ";
            cin >> startTime;
            subj.setStartTime(startTime);
            break;
          }
          case '6': {
            string endTime;
            cout << "New end time [hhmm]: ";
            cin >> endTime;
            subj.setEndTime(endTime);
            break;
          }
          case '7': {
            string section;
            cout << "New section: ";
            cin >> section;
            subj.setSection(section);
            break;
          }
        }
      } while (op != '0');
    } 

  if (!found)
    cout << "No subject was found\n";
}

void Menu::showAllSubjects(const vector<Subj>& subjects) {
  if (subjects.empty()) {
    cout << "There are no subjects to show\n";
    return;
  }

  for (Subj subj : subjects)
    showSubject(subj);
}

void Menu::showAllSubjectsOrdered(const vector<Subj>& subjects) {
  if (subjects.empty()) {
    cout << "There are no subjects to show\n";
    return;
  }

  vector<Subj> copy = subjects;

  sort(copy.begin(), copy.end(), [&](Subj &a, Subj &b) {
      return a.getName() < b.getName();      
  });

  showAllSubjects(copy);
}

void Menu::findSubject(const vector<Subj>& subjects) {
  if (subjects.empty()) {
    cout << "There are no subjects to find\n";
    return;
  }

  string NRC;

  cout << "NRC: ";
  cin >> NRC;

  for (Subj subj : subjects) 
    if (subj.getNRC() == NRC) {
      showSubject(subj);
      return;
    }

  cout << "No subject was found\n";
}

void Menu::tempDelSubject(vector<Subj>& subjects, vector<Subj>& deletedSubjects) {
  if (subjects.empty()) {
    cout << "There are no subjects to delete\n";
    return;
  }
  
  string NRC;
  cout << "NRC: ";
  cin >> NRC;

  for (int i = 0; i < subjects.size(); ++i)
    if (subjects[i].getNRC() == NRC) {
      deletedSubjects.push_back(subjects[i]);
      subjects.erase(subjects.begin() + i);
      return;
    }

  cout << "No subject was found\n";
}

void Menu::recoverSubject(vector<Subj>& subjects, vector<Subj>& deletedSubjects) {
  if (deletedSubjects.empty()) {
    cout << "There are no subjects to recover\n";
    return;
  }
    
  string NRC;
  cout << "NRC: ";
  cin >> NRC;

  for (int i = 0; i < deletedSubjects.size(); ++i)
    if (deletedSubjects[i].getNRC() == NRC) {
      subjects.push_back(deletedSubjects[i]);
      deletedSubjects.erase(deletedSubjects.begin() + i);
      return;
    }

  cout << "No subject was found\n";
}

void Menu::permDelSubject(vector<Subj>& subjects) {
  if (subjects.empty()) {
    cout << "There are no subjects to delete\n";
    return;
  }

  string NRC;
  cout << "NRC: ";
  cin >> NRC;

  for (int i = 0; i < subjects.size(); ++i)
    if (subjects[i].getNRC() == NRC) {
      subjects.erase(subjects.begin() + i);
      return;
    }

  cout << "No subject was found\n";
}

