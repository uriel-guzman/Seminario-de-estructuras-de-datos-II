#include <stdio.h>
#include "subject.h"

typedef struct ListNode {
  Subj subj;
  struct ListNode* next;
  struct ListNode* tail;
} Node;

void listAdd(Node*, Subj);
void listDelete(Node*, char NRC[]);
