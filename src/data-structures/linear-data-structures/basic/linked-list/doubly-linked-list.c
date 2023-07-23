#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{ int data;
  struct Node* next;
  struct Node* prev;
} Node;

Node* create_node(int data);
void insert_at_beginning(Node** start, int data);
void insert_after(Node* prev_node, int data);
void insert_at_end(Node** start, int data);
int delete_node(Node** head_ref, Node* del);
void display(Node* node);
void display_reverse(Node* node);
Node* search(Node* head, int key);
int search_pos(Node* head, int key);
int update_node(Node* node, int data);
int get_size(Node* node);

Node* create_node(int data)
{ Node* new_node = (Node*)malloc(sizeof(Node));
  if (new_node == NULL)
  { printf("Memory allocation failed\n");
    exit(0);
  }
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

void insert_at_beginning(Node** start, int data)
{ Node* new_node = create_node(data);
  new_node->next = *start;
  if (*start != NULL)
  { (*start)->prev = new_node;
  }
  *start = new_node;

}

void insert_after(Node* prev_node, int data)
{ if (prev_node == NULL)
  { printf("the given previous node cannot be NULL");
    return;
  }
  Node* new_node = create_node(data);
  new_node->next = prev_node->next;
  new_node->prev = prev_node;
  prev_node->next = new_node;
  if (new_node->next != NULL)
  { new_node->next->prev = new_node;
  }
}

void insert_at_end(Node** start, int data)
{ Node* new_node = create_node(data);
  Node* last = *start;
  if (*start == NULL)
  { *start = new_node;
    return;
  }
  while (last->next != NULL)
  { last = last->next;
  }
  last->next = new_node;
  new_node->prev = last;
}

int delete_node(Node** head_ref, Node* del)
{ if (*head_ref == NULL || del == NULL)
  { return -1;
  }
  if (*head_ref == del)
  { *head_ref = del->next;
  }
  if (del->next != NULL)
  { del->next->prev = del->prev;
  }
  if (del->prev != NULL)
  { del->prev->next = del->next;
  }
  free(del);
  del = NULL;
  return 0;
}

void display(Node* node)
{ while (node != NULL)
  { printf(" %d ", node->data);
    node = node->next;
  }
}

void display_reverse(Node* node)
{ Node* last;
  printf("\nTraversal in reverse direction \n");
  while(node != NULL)
  { last = node;
    node = node->next;
  }
  while(last != NULL)
  { printf(" %d ", last->data);
    last = last->prev;
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

int search_pos(Node* head, int key)
{ Node* current = head;
  int pos = 0;
  while (current != NULL)
  { if (current->data == key)
    { return pos;
    }
    current = current->next;
    pos++;
  }
  return -1;
}

int update_node(Node* node, int data)
{ if(node == NULL)
  { return -1;
  }
  node->data = data;
  return 0;
}

int get_size(Node* node)
{ int size = 0;
  while (node != NULL)
  { size++;
    node = node->next;
  }
  return size;
}

int main()
{ Node* head = NULL;
  insert_at_beginning(&head, 5);
  insert_at_beginning(&head, 4);
  insert_at_end(&head, 8);
  insert_at_end(&head, 9);
  insert_after(head->next, 6);

  printf("\n Doubly Linked list is: ");
  display(head);

  printf("\n Doubly Linked list in reverse is: ");
  display_reverse(head);

  Node* found = search(head, 6);
  if (found != NULL)
  { printf("\n Element found: %d", found->data);
  }
  else
  { printf("\n Element not found");
  }

  int pos = search_pos(head, 6);
  if(pos != -1)
  { printf("\n Element found at position: %d", pos);
  }
  else
  { printf("\n Element not found");
  }

  if(update_node(found, 7) == 0)
  { printf("\n Update successful");
  }
  else
  { printf("\n Update failed - node not found");
  }

  printf("\n Doubly Linked list after update is: ");
  display(head);

  printf("\n Size of list is: %d", get_size(head));

  return 0;
}
