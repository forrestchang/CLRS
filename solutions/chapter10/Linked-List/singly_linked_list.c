#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *next;
} Node;

Node* search(Node *list, int key) {
  if (list->next == NULL) {
    return list;
  }

  Node *node = list->next;
  while(node->next != NULL && node->key != key) {
    node = node->next;
  }

  return node;
}

void insert(Node *list, int value) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->key = value;

  if (list->next == NULL) {
    node->next = NULL;
  } else {
    node->next = list->next;
  }

  list->next = node;
  free(node);
}

void delete(Node *list, Node *keyNode) {
  if (list->next == NULL) {
    
  }
}

int main(void) {

  return 0;
}
