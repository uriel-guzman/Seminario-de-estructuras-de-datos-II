#include "subject.h"
#include "string.h"

void readSubject(Subj *subj) {
  printf("Name: ");
  scanf("%[^\n]s", subj->name);  
  
  printf("ID: ");
  scanf("%s", subj->ID);  
  
  printf("NRC: ");
  scanf("%s", subj->NRC);  

  printf("Professor name: ");
  scanf("%[^\n]s", subj->professorName);  

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
    subj->availableDays[i] = op == 'y';
  }
  
  printf("Start time [hhmm]: ");
  scanf("%s", subj->startTime);
  
  printf("End time [hhmm]: ");
  scanf("%s", subj->endTime);
  
  printf("Section: ");
  scanf("%s", subj->section);
}

int comp(char* a, char* b) {
   return (strcmp(a, b));
}
