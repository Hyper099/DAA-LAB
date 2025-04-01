#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int data;
   struct Node *next;
} Node;

Node *CreateNode(int data)
{
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

Node *AddLinkedList(Node *head1, Node *head2)
{
   // int num1 = 0, num2 = 0;
   // Node *result = NULL;

   // Node *temp1 = head1;
   // while (temp1 != NULL)
   // {
   //    num1 = num1 * 10 + temp1->data;
   //    temp1 = temp1->next;
   // }

   // Node *temp2 = head2;
   // while (temp2 != NULL)
   // {
   //    num2 = num2 * 10 + temp2->data;
   //    temp2 = temp2->next;
   // }

   // int sum = num1 + num2;

   // // Create a new linked list to store the sum
   // while (sum != 0)
   // {
   //    int rem = sum % 10;
   //    Node *newNode = CreateNode(rem);
   //    newNode->next = result;
   //    result = newNode;
   //    sum = sum / 10;
   // }

   // return result;

   Node *result = NULL;

   while (head1 != NULL && head2 != NULL)
   {
      if (head1->next == NULL && head2->next != NULL)
      {
         head1->next = CreateNode(0);
      }

      if (head2->next == NULL && head1->next != NULL)
      {
         head2->next = CreateNode(0);
      }

      int num = head1->data + head2->data;
      if (num < 10)
      {
         Node *temp = CreateNode(num);
         temp->next = result;
         result = temp;
      }
      else
      {

         Node *temp = CreateNode(num % 10);
         temp->next = result;
         result = temp;
         if (head1->next != NULL)
         {
            head1->next->data += 1;
         }
         else
         {
            head1->next = CreateNode(1);
         }
      }

      head1 = head1->next;
      head2 = head2->next;
   }

   return result;
}

//! Function to print linked list.
void PrintLinkedList(Node *Node)
{
   while (Node != NULL)
   {
      printf("%d ", Node->data);
      Node = Node->next;
   }
   printf("\n");
}

int main()
{
   //! First linked list.
   // create Nodes
   Node *head1 = CreateNode(1);
   Node *second1 = CreateNode(2);
   Node *third1 = CreateNode(4);
   Node *fourth1 = CreateNode(4);

   // link Nodes
   head1->next = second1;
   second1->next = third1;
   third1->next = fourth1;

   //! Second linked list.
   // create Nodes
   Node *head2 = CreateNode(4);
   Node *second2 = CreateNode(5);
   Node *third2 = CreateNode(6);

   // link Nodes
   head2->next = second2;
   second2->next = third2;

   //! Summation linked list

   Node *sum = AddLinkedList(head1, head2);
   PrintLinkedList(sum);

   return 0;
}