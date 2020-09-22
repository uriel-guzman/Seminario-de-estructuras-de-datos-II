#ifndef LISTNODE_H
#define LISTNODE_H

#include <stdio.h>
#include "subject.h"

typedef struct ListNode {
  Subj subj;
  struct ListNode* next;
} Node;

bool listAdd(Node**, Subj);
bool listDelete(Node**, char NRC[]);

#endif /* LISTNODE_H */
