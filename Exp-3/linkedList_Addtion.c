#include <stdio.h>
#include <stdlib.h>

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
      printf("0");

   while (head)
   {
      printf("%d", head->data);
      head = head->next;
   }
   printf("\n");
}

Node *AddLinkedList(Node *head1, Node *head2)
{
   // Reverse the input lists in place.
   head1 = ReverseLinkedList(head1);
   head2 = ReverseLinkedList(head2);

   Node *result = NULL, *tail = NULL;
   int carry = 0;

   // Process both lists and any remaining carry.
   while (head1 || head2 || carry)
   {
      int sum = carry;
      if (head1)
      {
         sum += head1->data;
         head1 = head1->next;
      }
      if (head2)
      {
         sum += head2->data;
         head2 = head2->next;
      }
      carry = sum / 10;
      int digit = sum % 10;

      // Create a new node for the resulting digit.
      Node *newNode = CreateNode(digit);
      if (!result)
         result = tail = newNode;
      
      else
      {
         tail->next = newNode;
         tail = newNode;
      }
   }

   // Reverse the result to restore the normal order.
   result = ReverseLinkedList(result);
   return result;
}

int main()
{

   Node *num1 = CreateNode(1);

   Node *num2 = CreateNode(9);

   Node *sum = AddLinkedList(num1, num2);

   printf("Sum: ");
   PrintLinkedList(sum);

   return 0;
}
