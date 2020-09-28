#include "subject.h"
#include <string.h>
#include <stdlib.h>

void readSubject(Subj *subj) {
  printf("Name: ");
  fgets(subj->name, 100, stdin);
  subj->name[strlen(subj->name) - 1] = '\0';

  printf("Professor name: ");
  fgets(subj->professorName, 100, stdin);
  subj->professorName[strlen(subj->professorName) - 1] = '\0';

  printf("ID: ");
  scanf("%s", subj->ID);  
  
  printf("NRC: ");
  scanf("%s", subj->NRC);  

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
    subj->availableDays[i] = op == 'y';
  }
  
  printf("Start time [hhmm]: ");
  scanf("%s", subj->startTime);
  
  printf("End time [hhmm]: ");
  scanf("%s", subj->endTime);
  
  printf("Section: ");
  scanf("%s", subj->section);
  getchar();
}
