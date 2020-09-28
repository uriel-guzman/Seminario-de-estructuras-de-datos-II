#include "menu.h"

void Menu::showSubject(Subj subj) {
  cout << '\n';
  cout << '\t' << subj.getName() << '\n';
  cout << '\t' << subj.getID() << '\n';
  cout << '\t' << subj.getNRC() << '\n';
  cout << '\t' << subj.getProfessorName() << '\n';
  cout << "\tAvailable days\n";

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

  cout << '\t' << subj.getStartTime() << '\n';
  cout << '\t' << subj.getEndTime() << '\n';
  cout << '\t' << subj.getSection() << '\n';
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

  for (Subj &subj : subjects)
    if (subj.getNRC() == NRC)) {
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
            cin >> name;
            strcpy(it->subj.name, name);
            break;
            }
          case '2': {
            char ID[50];
            printf("New ID: ");
            scanf("%s", ID);
            strcpy(it->subj.ID, ID);
            break;
          }
          case '3': {
            char professorName[50];
            printf("New professor name: ");
            fgets(professorName, 100, stdin);
            professorName[strlen(professorName) - 1] = '\0';
            strcpy(it->subj.professorName, professorName);
            break;
          }
          case '4': {
            char days[7][50] = {
              "Monday",
              "Tuesday",
              "Wednesday",
              "Thursday",
              "Friday",
              "Saturday",
              "Sunday"
            };

            printf("Select available days [y/n]\n");
            
            for (int i = 0; i < 7; ++i) {
              printf("%s? ", days[i]);
              char op;
              scanf(" %c", &op);
              getchar();
              it->subj.availableDays[i] = op == 'y';
            }
            break;
          }
          case '5': {
            char startTime[50];
            printf("New start time [hhmm]: ");
            scanf("%s", startTime);
            strcpy(it->subj.startTime, startTime);
            break;
          }
          case '6': {
            char endTime[50];
            printf("New end time [hhmm]: ");
            scanf("%s", endTime);
            strcpy(it->subj.endTime, endTime);
            break;
          }
          case '7': {
            char section[50];
            printf("New section: ");
            scanf("%s", section);
            strcpy(it->subj.section, section);
            break;
          }
        }
      } while (op != '0');
      return true;
    }
  return false;

}

bool Menu::showAllSubjects(const vector<Subj>&) {

}

bool Menu::showAllSubjectsOrdered(const vector<Subj>&) {

}

bool Menu::findSubject(const vector<Subj>&) {

}

bool Menu::tempDelSubject(vector<Subj>&, vector<Subj>&) {

}

bool Menu::recoverSubject(vector<Subj>&, vector<Subj>&) {

}

bool Menu::permDelSubject(vector<Subj>&) {

}

