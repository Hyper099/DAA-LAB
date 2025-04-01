#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list.
typedef struct Node
{
   int data;
   struct Node *next;
} Node;

// Create a new node.
Node *CreateNode(int data)
{
   Node *node = (Node *)malloc(sizeof(Node));
   node->data = data;
   node->next = NULL;
   return node;
}

// Reverse the linked list in-place.
Node *ReverseLinkedList(Node *head)
{
   Node *prev = NULL, *curr = head, *next = NULL;
   while (curr)
   {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }
   return prev;
}

// Print the linked list as a number.
void PrintLinkedList(Node *head)
{
   if (!head)
   {
      printf("0");
   }
   while (head)
   {
      printf("%d", head->data);
      head = head->next;
   }
   printf("\n");
}

Node *SubtractLinkedList(Node *head1, Node *head2)
{
   // Reverse the input lists in place.
   head1 = ReverseLinkedList(head1);
   head2 = ReverseLinkedList(head2);

   Node *result = NULL, *tail = NULL;
   int borrow = 0;

   // Process the lists digit by digit.
   while (head1 != NULL || head2 != NULL)
   {
      int d1 = (head1 ? head1->data : 0);
      int d2 = (head2 ? head2->data : 0);
      int diff = d1 - d2 - borrow;
      if (diff < 0)
      {
         diff += 10;
         borrow = 1;
      }
      else
         borrow = 0;

      Node *newNode = CreateNode(diff);
      if (result == NULL)
         result = tail = newNode;
      else
      {
         tail->next = newNode;
         tail = newNode;
      }

      // Move to the next nodes.
      if (head1)
         head1 = head1->next;
      if (head2)
         head2 = head2->next;
   }

   // Reverse the result to restore normal order.
   result = ReverseLinkedList(result);

   // Remove any extra leading zeros.
   while (result && result->data == 0 && result->next)
   {
      Node *temp = result;
      result = result->next;
      free(temp);
   }

   return result;
}

int main()
{
   Node *num1 = CreateNode(12);

   Node *num2 = CreateNode(4);

   Node *diff = SubtractLinkedList(num1, num2);
   printf("Difference : ");
   PrintLinkedList(diff);

   return 0;
}
