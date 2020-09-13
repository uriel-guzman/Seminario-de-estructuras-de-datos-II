#include "linknode.h"
#include <stdlib.h>
#include <string.h>

void listAdd(Node* head, Subj subj) {
  if (!head) {
    head = head->tail = malloc(sizeof(Node*));
    head->tail->subj = subj;
  } else {
    head->tail->next = malloc(sizeof(Node*));
    head->tail->subj = subj;
    head->tail = head->tail->next;
  }
}

void listDelete(Node* head, char NRC[]) {
  Node* it = head;

  if (!it->next) 
    head = head->tail = NULL;
  
  for (; it && it->next; it = it->next) {
    if (strcmp(it->next->subj.NRC, NRC) == 0) {
      if (!it->next->next) 
        head->tail = it;
      it->next = it->next->next; 
      break;
    }
  }
}
