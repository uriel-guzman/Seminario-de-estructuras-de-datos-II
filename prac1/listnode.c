#include "listnode.h"
#include <stdlib.h>
#include <string.h>

void listAdd(Node* head, Subj subj) {
  if (!head) {
    head = malloc(sizeof(Node*));
    head->subj = subj;
  } else {
    Node* temp = malloc(sizeof(Node*));
    temp->subj = subj;
    temp->next = head;
    head = temp;
  }
  if (head) {
    printf("head not null\n");
  }
}

void listDelete(Node* head, char NRC[]) {
  Node* it = head;

  if (!it->next) 
    head = NULL;
  
  for (; it && it->next; it = it->next) {
    if (strcmp(it->next->subj.NRC, NRC) == 0) {
      it->next = it->next->next; 
      break;
    }
  }
}
