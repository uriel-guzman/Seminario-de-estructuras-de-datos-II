#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdbool.h>
#include <stdio.h>

typedef struct Subject {
  char name[50];
  char ID[50];
  char NRC[50];
  char professorName[50];
  bool availableDays[50];
  char startTime[50];
  char endTime[50];
  char section[50];
} Subj;

void readSubject(Subj *s); 

#endif /* SUBJECT_H */
