#include<stdio.h>
#include<stdlib.h> //for malloc
#define MAX_Q_SIZE 500

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
}Node;

struct node* newNode(int data);
void rec_PreOrder(struct node*);
void rec_InOrder(struct node*);
void rec_PostOrder(struct node*);
void loop_PreOrder(struct node*);
void loop_InOrder(struct node*);
void loop_PostOrder(struct node*);
Node* invertTree(Node* root);
Node ** createQueue(int *front, int *rear);
void enQueue(Node **queue, int *rear, Node *newNode);
Node *deQueue(Node** queue, int *front);
void printLevelOrder(Node *root);
Node * insert(Node * root, int value);
