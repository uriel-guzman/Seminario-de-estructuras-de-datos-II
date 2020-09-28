#include "menu.h"

int main() {
  char op;
  vector<Subj> subjects;
  vector<Subj> deletedSubjects;
  Menu menu;

  do {
    cout << "1) Add subject\n";
    cout << "2) Modify subject\n";
    cout << "3) Show all subjects\n";
    cout << "4) Show all subjects in order\n";
    cout << "5) Show subject\n";
    cout << "6) Temporarily delete subject\n";
    cout << "7) Recover subject\n";
    cout << "8) Permanently delete subject\n";
    cout << "0) Exit\n";
    cout << "Choose an option: ";
    cin >> op;

    switch (op) {
      case '1':
        menu.addSubject(subjects);
        break;
      case '2':
        menu.modifySubject(subjects);
        break;
      case '3':
        menu.showAllSubjects(subjects);
        break;
      case '4':
        menu.showAllSubjectsOrdered(subjects);
        break;
      case '5':
        menu.findSubject(subjects);
        break;
      case '6':
        menu.tempDelSubject(subjects, deletedSubjects);
        break;
      case '7':
        menu.recoverSubject(subjects, deletedSubjects);
        break;
      case '8':
        menu.permDelSubject(subjects);
        break;
    }
  } while (op != '0');
}

