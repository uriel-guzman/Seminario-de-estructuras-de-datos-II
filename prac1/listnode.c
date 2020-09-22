#include "listnode.h"
#include <stdlib.h>
#include <string.h>

bool listAdd(Node** head, Subj subj) {
  if (!*head) {
    *head = (Node*)malloc(sizeof(Node));
    (*head)->subj = subj;
  } else {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->subj = subj;
    temp->next = *head;
    *head = temp;
  }
  return *head;
}

bool listDelete(Node** head, char NRC[]) {
  if (strcmp((*head)->subj.NRC, NRC) == 0) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return true;
  }
  
  for (Node* it = *head; it && it->next; it = it->next) 
    if (strcmp(it->next->subj.NRC, NRC) == 0) {
      Node* temp = it->next;
      it->next = it->next->next; 
      free(temp);
      return true;
    }

  return false;
}
