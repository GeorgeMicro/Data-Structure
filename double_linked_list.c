#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
}Node;

void Print(Node *head);
Node* InsertHead(Node *head, int data);
Node* Reverse(Node* head);

int main()
{
  Node *head = InsertHead(head, 1);
  head = InsertHead(head, 2);
  head = InsertHead(head, 3);
  head = InsertHead(head, 4);
  Print(head);
  head = Reverse(head);
  Print(head);
  
}

void Print(Node *head)
{
  printf("NULL<-");
  while (head != NULL)
    {
      printf("->%d<-", head->data);
      head = head->next;
    }
  printf("NULL\n");
}

Node* InsertHead(Node *head,int data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  newNode->prev = NULL;
  if (head != NULL)
    head->prev = newNode;
  return newNode;
}

Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    if (head == NULL)
        return head;
    Node *prev = NULL;
    Node *next;
    Node *curr = head;
    /* printf("%d", head->data); */
    while (curr != NULL)
        {
        next = curr->next;
	if (next != NULL)
	  printf("next = %d\n", next->data);
	prev = curr->prev;
	if (prev != NULL)
	  printf("prev = %d\n", prev->data);
        curr->next = prev;
        curr->prev = next;
        curr = next;
    }
    printf("head = %d\n", prev->prev->data);
    return (prev->prev);
}
