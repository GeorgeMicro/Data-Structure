#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
}Node;

void Print(Node *);
Node* InsertHead(Node *head,int data);
Node* InsertTail(Node *head,int data);
Node* InsertNth(Node *head, int data, int position);
Node* Delete(Node *head, int position);
void ReversePrint(Node *head);
Node* Reverse(Node *head);
Node* MergeLists(Node *headA, Node* headB);
Node* RemoveDuplicates(Node *head);
int HasCycle(Node* head);
int CompareLists(Node *headA, Node* head);
int GetNode(Node *head,int positionFromTail);
int FindMergeNode(Node *headA, Node *headB);
