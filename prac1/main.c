#include <stdio.h>
#include "listnode.h"
#include <string.h>

void showSubject(Subj);
bool addSubject(Node**);
bool modifySubject(Node**);
bool showAllSubjects(Node*);
bool showAllSubjectsOrdered(Node*);
bool findSubject(Node*);
bool tempDelSubject(Node**, Node**);
bool recoverSubject(Node**, Node**);
bool permDelSubject(Node**);

int main() {
  char op;
  Node* subjects = NULL;
  Node* deletedSubjects = NULL;

  do {
    printf("1) Add subject\n");
    printf("2) Modify subject\n");
    printf("3) Show all subjects\n");
    printf("4) Show all subjects in order\n");
    printf("5) Show subject\n");
    printf("6) Temporarily delete subject\n");
    printf("7) Recover subject\n");
    printf("8) Permanently delete subject\n");
    printf("0) Exit\n");
    printf("Choose an option: ");
    scanf(" %c", &op);
    getchar();

    switch (op) {
      case '1':
        addSubject(&subjects);
        break;
      case '2':
        modifySubject(&subjects);
        break;
      case '3':
        showAllSubjects(subjects);
        break;
      case '4':
        showAllSubjectsOrdered(subjects);
        break;
      case '5':
        findSubject(subjects);
        break;
      case '6':
        tempDelSubject(&subjects, &deletedSubjects);
        break;
      case '7':
        recoverSubject(&subjects, &deletedSubjects);
        break;
      case '8':
        permDelSubject(&subjects);
        break;
    }
  } while (op != '0');
}

void showSubject(Subj subj) {
  printf("\n");  
  printf("\tName: %s\n", subj.name);
  printf("\tID: %s\n", subj.ID);
  printf("\tNRC: %s\n", subj.NRC);
  printf("\tProfessor name: %s\n", subj.professorName);
  printf("\tAvailable days: \n");

  char days[7][50] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
  };

  for (int i = 0; i < 7; ++i) 
    if (subj.availableDays[i]) 
      printf("\t\t%s\n", days[i]);

  printf("\tStart time: %s\n", subj.startTime);
  printf("\tEnd time: %s\n", subj.endTime);
  printf("\tSection: %s\n", subj.section);
  printf("\n");  
}

bool addSubject(Node** subjects) {
  Subj subj;
  readSubject(&subj);
  printf("%s\n", subj.name);
  return listAdd(subjects, subj);
}

bool modifySubject(Node** subjects) {
  Node* it;
  char NRC[50];
  
  printf("NRC: ");
  scanf("%s", NRC);

  for (it = *subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      char op;
      do {
        printf("1) Name\n");
        printf("2) ID\n");
        printf("3) Professor name\n");
        printf("4) Available days\n");
        printf("5) Start time\n");
        printf("6) End time\n");
        printf("7) Section\n");
        printf("0) Exit\n");
        printf("Attribute to modify: ");
        scanf(" %c", &op);
        getchar();
        
        switch (op) {
          case '1': {
            char name[50];
            printf("New name: ");
            fgets(name, 100, stdin);
            name[strlen(name) - 1] = '\0';
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

bool showAllSubjects(Node* subjects) {
  for (Node* it = subjects; it; it = it->next)
    showSubject(it->subj);

  return subjects;
}

bool showAllSubjectsOrdered(Node* subjects) {
  Node* copy = NULL;

  for (Node* it = subjects; it; it = it->next)
    listAdd(&copy, it->subj);

  for (Node* it = copy; it; it = it->next) {
    Node* mn = it;
    for (Node* it2 = it->next; it2; it2 = it2->next) 
      if (strcmp(it2->subj.name, mn->subj.name) < 0) 
        mn = it2;

    Subj temp = it->subj;
    it->subj = mn->subj;
    mn->subj = temp;
  }

  showAllSubjects(copy);

  return copy;
}

bool findSubject(Node* subjects) {
  Node* it;
  char NRC[50];
  
  printf("NRC: ");
  scanf("%s", NRC);

  for (it = subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      showSubject(it->subj);
      return true;
    }
  return false;
}

bool tempDelSubject(Node** subjects, Node** deletedSubjects) {
  char NRC[50];

  printf("NRC: ");
  scanf("%s", NRC);

  for (Node* it = *subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) 
      return listAdd(deletedSubjects, it->subj) && listDelete(subjects, NRC);

  return false;
}

bool recoverSubject(Node** subjects, Node** deletedSubjects) {
  char NRC[50];

  printf("NRC: ");
  scanf("%s", NRC);

  for (Node* it = *deletedSubjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) 
      return listAdd(subjects, it->subj) && listDelete(deletedSubjects, NRC);

  return false;
}

bool permDelSubject(Node** subjects) {
  char NRC[50];

  printf("NRC: ");
  scanf("%s", NRC);

  for (Node* it = *subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) 
      return listDelete(subjects, NRC);

  return false;
}

