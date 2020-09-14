#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdbool.h>
#include <stdio.h>

typedef struct Subject {
  char name[30];
  char ID[10];
  char NRC[10];
  char professorName[30];
  bool availableDays[7];
  char startTime[10];
  char endTime[10];
  char section[10];
} Subj;

void readSubject(Subj *s); 

#endif /* SUBJECT_h */
