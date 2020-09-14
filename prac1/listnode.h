#ifndef LISTNODE_H
#define LISTNODE_H

#include <stdio.h>
#include "subject.h"

typedef struct ListNode {
  Subj subj;
  struct ListNode* next;
} Node;

void listAdd(Node*, Subj);
void listDelete(Node*, char NRC[]);

#endif /* LISTNODE_H */
