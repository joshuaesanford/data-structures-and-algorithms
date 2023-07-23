#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{ int data;
  struct Node* next;
} Node;

Node* create_node(int data)
{ Node* new_node = (Node*) malloc(sizeof(Node));
  if (!new_node)
  { printf("\nHeap Overflow");
    exit(0);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_end(Node** head, int data)
{ if (head == NULL)
  { printf("\nError: Cannot insert node. Head pointer is NULL.");
    return;
  }
  Node* new_node = create_node(data);
  if (*head == NULL)
  { *head = new_node;
    return;
  }
  Node* last = *head;
  while (last->next != NULL)
  { last = last->next;
  }
  last->next = new_node;
}

void delete_node(Node **head, int key)
{ if (head == NULL || *head == NULL)
  { printf("\nError: Cannot delete node. List is empty or head pointer is NULL.");
    return;
  }
  Node* temp = *head, *prev;
  if (temp->data == key)
  { *head = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key)
  { prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
  { printf("\nError: Cannot delete node. Node not found.");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

void display_list(Node *node)
{ while (node != NULL)
  { printf(" %d ", node->data);
    node = node->next;
  }
}

Node* search(Node* head, int key)
{ Node* current = head;
  while (current != NULL)
  { if (current->data == key)
    { return current;
    }
    current = current->next;
  }
  return NULL;
}

void update(Node* node, int data)
{ if (node != NULL)
  { node->data = data;
  }
  else
  { printf("\nError: Cannot update node. Node is NULL.");
  }
}

int main()
{ Node* head = NULL;
  insertEnd(&head, 1);
  insertEnd(&head, 2);
  insertEnd(&head, 3);
  insertEnd(&head, 4);
  insertEnd(&head, 5);
  printf("Linked List: ");
  displayList(head);
  deleteNode(&head, 6);
  printf("\nLinked List after deletion of 6: ");
  displayList(head);
  Node* item = search(head, 2);
  if (item != NULL)
  { printf("\nItem found: %d", item->data);
    printf("\nUpdating item to 10");
    update(item, 10);
  }
  else
  { printf("\nItem not found");
  }
  printf("\nLinked List after updating 2 to 10: ");
  displayList(head);
  return 0;
}
