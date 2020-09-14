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
    scanf("%c", &op);
    getchar();

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
  printf("Name: %s\n", subj.name);
  printf("ID: %s\n", subj.ID);
  printf("NRC: %s\n", subj.NRC);
  printf("Professor name: %s\n", subj.professorName);
  printf("Available days: ");

  char days[7][10] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
  };

  int i;

  for (i = 0; i < 7; ++i) 
    if (subj.availableDays[i]) 
      printf("\t%s\n", days[i]);

  printf("Start time: %s", subj.startTime);
  printf("End time: %s", subj.endTime);
  printf("Section: %s", subj.section);
  printf("\n");  
}

void menuAddSubject(Node* subjects) {
  Subj* subj;
  readSubject(subj);
  listAdd(subjects, *subj);
}

void menuModifySubject(Node* subjects) {
  Node* it;
  char NRC[10];
  
  printf("NRC: ");
  scanf("%s", NRC);

  for (it = subjects; it; it = it->next)
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
        printf("Attribute to modify: \n");
        scanf("%c", &op);
        
        switch (op) {
          case '1': {
            char name[30];
            printf("New name: ");
            scanf("%[^\n]s", name);
            strcpy(it->subj.name, name);
            break;
            }
          case '2': {
            char ID[10];
            printf("New ID: ");
            scanf("%s", ID);
            strcpy(it->subj.ID, ID);
            break;
          }
          case '3': {
            char professorName[30];
            printf("New professor name: ");
            scanf("%[^\n]s", professorName);
            strcpy(it->subj.professorName, professorName);
            break;
          }
          case '4': {
            char days[7][10] = {
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
              scanf("%c", &op);
              it->subj.availableDays[i] = op == 'y';
            }
            break;
          }
          case '5': {
            char startTime[10];
            printf("New start time [hhmm]: ");
            scanf("%s", startTime);
            strcpy(it->subj.startTime, startTime);
            break;
          }
          case '6': {
            char endTime[10];
            printf("New end time [hhmm]: ");
            scanf("%s", endTime);
            strcpy(it->subj.endTime, endTime);
            break;
          }
          case '7': {
            char section[10];
            printf("New section");
            scanf("%s", section);
            strcpy(it->subj.section, section);
            break;
          }
        }
      } while (op != '0');
      break;
    }
}

void menuShowAllSubjects(Node* subjects) {
  printf("menushowallsubjects\n");
  Node* it;

  if (subjects) {
    printf("head not null\n");
  } else {
    printf("head is null\n");
  }
  for (it = subjects; it; it = it->next)
    menuShowSubject(it->subj);
}

void menuShowAllSubjectsOrdered(Node* subjects) {
  Node* copy = NULL;

  Node* it;
  Node* it2;

  for (it = subjects; it; it = it->next)
    listAdd(copy, it->subj);

  for (it = subjects; it; it = it->next) {
    Node* mn = it;
    for (it2 = subjects; it2->next != it; it2 = it2->next) {
      if (strcmp(mn->subj.name, it2->subj.name) < 0) 
        mn = it2;
    }

    char b[30] = {0};
    char t[30] = {0};

    strcpy(b, mn->subj.name);
    strcpy(t, it->subj.name);
    strcpy(it->subj.name, b);
    strcpy(mn->subj.name, t);
  }

  menuShowAllSubjects(copy);
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
  Node* it;
  char NRC[10];

  printf("NRC: ");
  scanf("%s", NRC);

  for (it = subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      listAdd(deletedSubjects, it->subj);
      listDelete(deletedSubjects, NRC);
      break;  
    }
}

void menuRecoverSubject(Node* subjects, Node* deletedSubjects) {
  Node* it;
  char NRC[10];

  printf("NRC: ");
  scanf("%s", NRC);

  for (it = deletedSubjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      listAdd(subjects, it->subj);
      listDelete(deletedSubjects, NRC);
      break;  
    }
}

void menuPermDelSubject(Node* subjects) {
  Node* it;
  char NRC[10];

  printf("NRC: ");
  scanf("%s", NRC);

  for (it = subjects; it; it = it->next)
    if (strcmp(it->subj.NRC, NRC) == 0) {
      listDelete(subjects, NRC);
      break;  
    }
}

