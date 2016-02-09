#include"tree.h"
int main()
{
  struct node* root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(7);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  /* root->right->right = newNode(9); */
  /* root->left->right->left = newNode(5); */
  /* root->left->right->right = newNode(11); */
  /* root->right->right->left = newNode(4); */

  /* printf("Preorder: "); */
  /* rec_PreOrder(root); */
  /* printf("\nInorder: "); */
  /* rec_InOrder(root); */
  /* printf("\nPostorder: "); */
  /* rec_PostOrder(root); */
  /* printf("\nPreorder_loop: "); */
  //loop_PreOrder(root);
  //loop_InOrder(root);
  //loop_PostOrder(root);

  
  root = insert(root, 6);
  printLevelOrder(root);
    
  
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

void rec_PreOrder(struct node* root)
{
  if (root == NULL)
    return;
  printf("%d ", root->data);
  rec_PreOrder(root->left);
  rec_PreOrder(root->right);
}

void rec_InOrder(struct node* root)
{
  if (root == NULL)
    return;
  
  rec_InOrder(root->left);
  printf("%d ", root->data);
  rec_InOrder(root->right);
}

void rec_PostOrder(struct node* root)
{
  if (root == NULL)
    return;

  rec_PostOrder(root->left);
  rec_PostOrder(root->right);
  printf("%d ", root->data);
}

void loop_PreOrder(struct node* root)
{
  struct node * temp = root;
  
}

Node* invertTree(Node* root) {
    if (!root)
        return NULL;
    else
    {
        Node * temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}

Node ** createQueue(int *front, int *rear)
{
  Node  **queue = (Node **)malloc(sizeof(Node*)*MAX_Q_SIZE);
  *front = *rear = 0;
  return queue;
}

void enQueue(Node **queue, int *rear, Node *newNode)
{
  queue[*rear] = newNode;
  (*rear)++;
}

Node *deQueue(Node** queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
}

void printLevelOrder(Node *root)
{
  int rear, front;
  Node **queue = createQueue(&front, &rear);
  Node *temp = root;

  while (temp)
    {
      printf("%d ", temp->data);

      if (temp->left)
	enQueue(queue, &rear, temp->left);

      if (temp->right)
	enQueue(queue, &rear, temp->right);
      temp = deQueue(queue, &front);
      
    }
}
  
Node * insert(Node * root, int value)
{
    Node * temp = root;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
      {
	return newNode;
      }
    while (temp)
        {
        if (temp->data > value)
            {
            if (temp->left == NULL)
                temp->left = newNode;
            else
                temp = temp->left;
        }
            
        else if (temp->data < value)
            {
            if (temp->right == NULL)
                temp->right = newNode;
            else
                temp = temp->right;
        }
        else
            return root;
            
    }

    return root;
}
