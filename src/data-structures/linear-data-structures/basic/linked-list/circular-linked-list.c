#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{ int data;
  struct Node* next;
} Node;

Node* create_node(int data)
{ Node* new_node = (Node*)malloc(sizeof(Node));
  if(!new_node)
  { printf("Memory error\n");
    exit(0);
  }
  new_node->data = data;
  new_node->next = new_node; // next points to itself
  return new_node;
}

Node* insert_node(Node* head, int data)
{ Node* new_node = create_node(data);
  if(!head)
  { return new_node;
  }

  Node* temp = head;
  while(temp->next != head)
  { temp = temp->next;
  }
  temp->next = new_node;
  newNode->next = head;
  return head;
}

Node* delete_node(Node* head, int key)
{ if(!head)
  { printf("List is empty\n");
    return NULL;
  }
  Node *prev = NULL, *cur = head;
  do
  { if(cur->data == key)
    { // the node to delete is the head
      if(cur == head)
      { // the node is the only node in the list
	      if(head->next == head)
	      { head = NULL;
	      }
	      else
	      { Node* temp = head;
	        while(temp->next != head)
	        { temp = temp->next;
	        }
	        head = head->next;
	        temp->next = head;
	      }
      }
      else
      { // the node to delete is not the head
	      prev->next = cur->next;
      }
      free(cur);
      return head;
    }
    prev = cur;
    cur = cur->next;
  } while(cur != head);

  printf("Key not found\n");
  return head;
}

void printList(Node* head)
{ if(!head)
  { printf("List is empty\n");
    return;
  }
  Node* temp = head;
  do
  { printf("%d ", temp->data);
    temp = temp->next;
  } while(temp != head);
  printf("\n");
}

int main()
{ Node* head = NULL;
  head = insertNode(head, 1);
  head = insertNode(head, 2);
  head = insertNode(head, 3);
  head = insertNode(head, 4);

  printf("Circular Linked List: ");
  printList(head);

  head = deleteNode(head, 4);
  printf("After deletion: ");
  printList(head);

  return 0;
}
