#include <stdio.h>
#include "listnode.h"
#include <string.h>

void menuShowSubject(Subj);
void menuAddSubject(Node*);
void menuModifySubject(Node*);
void menuShowAllSubjects(Node*);
void menuShowAllSubjectsOrdered(Node*);
void menuFindSubject(Node*);
void menuTempDelSubject(Node*, Node*);
void menuRecoverSubject(Node*, Node*);
void menuPermDelSubject(Node*);

int main() {
  char op;
  Node* subjects = NULL;
  Node* deletedSubjects = NULL;

  do {
    printf("Choose an option:\n");
    printf("1) Add subject\n");
    printf("2) Modify subject\n");
    printf("3) Show all subjects\n");
    printf("4) Show all subjects in order\n");
    printf("5) Show subject\n");
    printf("6) Temporarily delete subject\n");
    printf("7) Recover subject\n");
    printf("8) Permanently delete subject\n");
    printf("0) Exit\n");

    switch (op) {
      case '1':
        menuAddSubject(subjects);
        break;
      case '2':
        menuModifySubject(subjects);
        break;
      case '3':
        menuShowAllSubjects(subjects);
        break;
      case '4':
        menuShowAllSubjectsOrdered(subjects);
        break;
      case '5':
        menuFindSubject(subjects);
        break;
      case '6':
        menuTempDelSubject(subjects, deletedSubjects);
        break;
      case '7':
        menuRecoverSubject(subjects, deletedSubjects);
        break;
      case '8':
        menuPermDelSubject(subjects);
        break;
    }
  } while (op != '0');
}

void menuShowSubject(Subj subj) {
  printf("\n");  
  printf("Name: ");
  printf("ID: ");
  printf("NRC: ");
  printf("Professor name: ");
  printf("Select available days [y/n]\n");
  printf("Start time [hh:mm]: ");
  printf("End time [hh:mm]: ");
  printf("Section: ");
  printf("\n");  
}

void menuAddSubject(Node* subjects) {
  Subj* subj;
  readSubject(subj);
  listAdd(subjects, *subj);
}

void menuModifySubject(Node* subjects) {
  
}

void menuShowAllSubjects(Node* subjects) {
  Node* it;

  for (it = subjects; it; it = it->next)
    menuShowSubject(it->subj);
}

void menuShowAllSubjectsOrdered(Node* subjects) {
  
}

void menuFindSubject(Node* subjects) {
  Node* it;
  char NRC[10];
  
  printf("NRC: ");
  scanf("%s", NRC);

  for (it = subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      menuShowSubject(it->subj);
      break;
    }
}

void menuTempDelSubject(Node* subjects, Node* deletedSubjects) {

}

void menuRecoverSubject(Node* subjects, Node* deletedSubjects) {

}

void menuPermDelSubject(Node* subjects) {
  Node* it;
  char NRC[10];

  printf("NRC: ");
  scanf("%s", NRC);

  for (it = subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      listDelete(subjects, NRC);

    }
}

