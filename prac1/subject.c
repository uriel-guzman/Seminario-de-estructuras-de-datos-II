#include "subject.h"

void readSubject(Subj *s) {
  printf("Name: ");
  scanf("%[^\n]s", s->name);  
  
  printf("ID: ");
  scanf("%s", s->ID);  
  
  printf("NRC: ");
  scanf("%s", s->NRC);  

  printf("Professor name: ");
  scanf("%[^\n]s", s->professorName);  

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
    s->availableDays[i] = op == 'y';
  }
  
  printf("Start time [hh:mm]: ");
  scanf("%s", s->startTime);
  
  printf("End time [hh:mm]: ");
  scanf("%s", s->endTime);
  
  printf("Section: ");
  scanf("%s", s->section);
}
