#include"linked_list.h"

int main()
{
  int i;
  Node *head = NULL;
  Node *list1 = NULL;
  for(i = 0; i < 5; i++)
    {
      head = InsertHead(head, i);
    }
  Print(head);


  Node *list2 = NULL;
  list1 = InsertHead(list1, 6);
  list1 = InsertHead(list1, 5);
  list1 = InsertHead(list1, 5);
  list1 = InsertHead(list1, 1);
  
  list2 = InsertHead(list2, 7);
  list2 = InsertHead(list2, 4);
  list2 = InsertHead(list2, 2);

  Print(list1);
  Print(list2);
  /* Node *newList = MergeLists(list1, list2); */
  /* Print(newList); */
  Node *newList = RemoveDuplicates(list1);
  Print(newList);
  return 0;
}

void Print(Node *head)
{
  while (head != NULL)
    {
      printf("%d->", head->data);
      head = head->next;
    }
  printf("NULL\n");
}

Node* InsertHead(Node *head,int data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  return head;
}
Node* InsertTail(Node *head,int data)
{
  Node * curr = head;
    
  // Complete this method
  if (head ==  NULL)
    {
      head = (Node *)malloc(sizeof(Node));
      head->next == NULL;
      head->data = data;
    }
  else {
    while(curr->next != NULL)
      {
        curr = curr->next;
      }
    curr->next = (Node *)malloc(sizeof(Node));
    curr->next->data = data;
    curr->next->next = NULL;
  }
  return head;
}
Node* InsertNth(Node *head, int data, int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node *temp;
    Node *curr = head;
    
    if (!position)
        {
        newNode->next = head;
        return newNode;
    }
    
    while (position-- > 1)
        {
        if (curr->next != NULL)
            curr = curr->next;
        else
            break;
    }
    temp = curr->next;
    curr->next = newNode;
    newNode->next = temp;
    return head;
}
Node* Delete(Node *head, int position)
{
  // Complete this method
    Node * curr = head;
    int i;
    if (position == 0)
        {
        return (head->next);
    } 
    position--;
    while (position-- > 0)
    {
        curr = curr->next;
        }
    curr->next = curr->next->next;
    
    return(head);
}
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if (head == NULL)
        return;
    ReversePrint(head->next);
    printf("%d\n", head->data);
}
Node* Reverse(Node *head)
{
  // Complete this method
    Node * curr = head;
    Node* prev = NULL;
    Node* next;
    
    while (curr != NULL)
        {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    
}
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
  Node *newList;
  Node *curr;
  if (headA == NULL)
    return headB;
  if (headB == NULL)
    return headA;
  if (headA->data < headB->data)
    {
      newList = headA;
      headA = headA->next;
    } else {
    newList = headB;
    headB = headB->next;
  }
  curr = newList;
    
  while (headA != NULL && headB != NULL)
    {
      if (headA->data < headB->data)
	{
	  curr->next = headA;
	  headA = headA->next;
	  curr = curr->next;
                    
	} else { 
	curr->next = headB;
	headB = headB->next;
	curr = curr->next;
      }
    }
  if (headA == NULL && headB == NULL)
    { 
      curr->next = NULL;
        
    } else if (headB == NULL)
    {
      curr->next = headA;
    } else
    {
      curr->next = headB;
    }
  return newList;
}

Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  if (head == NULL)
    return NULL;
  Node *curr = head->next;
  Node *prev = head;
    
  while (curr != NULL)
    {
      if (prev->data == curr->data)
	{
	  //delete the duplicated node
	  prev->next = curr->next;
        }
      else
	{
	  prev = curr;
        }
      curr = curr->next;
    }
  return head;
}

int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    if (head == NULL || head->next == NULL)
        return 0;
    Node *fastPtr = head;
    Node *slowPtr = head;
    
    while (1)
        {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == NULL || fastPtr == NULL || fastPtr->next == NULL)
            return 0;
        if (slowPtr == fastPtr)
            return 1;
    }
    
    return 0;
    
}
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 

    while(headA != NULL && headB != NULL)
        {
        if (headA->data != headB->data)
            return 0;
        headA = headA->next;
        headB = headB->next;
    }
    if (headA == NULL && headB == NULL)
        return 1;
    else
        return 0;
}

int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
 //reverse the list
    Node *curr, *next, *prev;
    curr = head;
    prev = NULL;
    while (curr != NULL)
        {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    int i;
    for (i = 0; i < positionFromTail; i++)
        {
        prev = prev->next;
    }
    return prev->data;
}
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node *ptrA = headA;
    Node *ptrB = headB;
    while (headA != NULL)
        {
        while (ptrB != NULL)
            {
            if (headA->data == ptrB->data)
                return ptrB->data;
            ptrB = ptrB->next;
        }
        headA = headA->next;
        ptrB = headB;
    }
    return 0;
}
