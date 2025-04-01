#include <iostream>
#include <cmath>
using namespace std;

// cityNode structure
typedef struct Node
{
   string cityName;
   float x, y; // coordinates of cities
   struct Node *next;
   Node(string cityName, float x, float y) : cityName(cityName), x(x), y(y), next(NULL) {}
} cityNode;

// Print the linked list of cities
void printCityList(cityNode *head)
{
   cityNode *temp = head;
   while (temp != NULL)
   {
      cout << temp->cityName << " (" << temp->x << ", " << temp->y << ")" << endl;
      temp = temp->next;
   }
}

// Insert a city at the front of the list
cityNode *insertAtFront(cityNode *head)
{
   string cityName;
   cout << "Enter the name of the city: ";
   cin >> cityName;
   float x, y;
   cout << "Enter the x-coordinate of the city: ";
   cin >> x;
   cout << "Enter the y-coordinate of the city: ";
   cin >> y;
   cityNode *newCity = new cityNode(cityName, x, y);

   newCity->next = head;
   return newCity;
}

// Delete a city by name
cityNode *deleteByName(cityNode *head, string cityName)
{
   if (head == NULL)
      return head;

   cityNode *temp = head, *prev = NULL;

   if (temp != NULL && temp->cityName == cityName)
   {
      head = temp->next;
      delete temp;
      cout << "City with name " << cityName << " deleted successfully.\n";
      return head;
   }

   while (temp != NULL && temp->cityName != cityName)
   {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL)
   {
      cout << "City with given name not found.\n";
      return head;
   }

   prev->next = temp->next;
   delete temp;
   cout << "City with name " << cityName << " deleted successfully.\n";
   return head;
}

// Delete a city by coordinates
cityNode *deleteByCoordinate(cityNode *head, float x, float y)
{
   cityNode *temp = head, *prev = NULL;
   while (temp != NULL)
   {
      if (temp->x == x && temp->y == y)
      {
         if (temp == head)
         {
            head = temp->next;
         }
         else
         {
            prev->next = temp->next;
         }
         delete temp;
         cout << "City with coordinates (" << x << ", " << y << ") deleted successfully.\n";
         return head;
      }
      prev = temp;
      temp = temp->next;
   }
   cout << "City with given coordinates not found.\n";
   return head;
}

// Search city by name
void searchByName(cityNode *head, string cityName)
{
   cityNode *temp = head;
   while (temp != NULL)
   {
      if (temp->cityName == cityName)
      {
         cout << "City found: " << temp->cityName << " (" << temp->x << ", " << temp->y << ")\n";
         return;
      }
      temp = temp->next;
   }
   cout << "City with name " << cityName << " not found.\n";
}

// Search city by coordinates
void searchByCoordinate(cityNode *head, float x, float y)
{
   cityNode *temp = head;
   while (temp != NULL)
   {
      if (temp->x == x && temp->y == y)
      {
         cout << "City found: " << temp->cityName << " (" << temp->x << ", " << temp->y << ")\n";
         return;
      }
      temp = temp->next;
   }
   cout << "City with coordinates (" << x << ", " << y << ") not found.\n";
}

// Print all cities within a given distance from a specified point
void printCitiesWithinDistance(cityNode *head, float x, float y, float distance)
{
   cityNode *temp = head;
   cout << "Cities within " << distance << " units from (" << x << ", " << y << "):\n";
   bool found = false;
   while (temp != NULL)
   {
      float dist = sqrt(pow(temp->x - x, 2) + pow(temp->y - y, 2));
      if (dist <= distance)
      {
         cout << temp->cityName << " (" << temp->x << ", " << temp->y << ")\n";
         found = true;
      }
      temp = temp->next;
   }
   if (!found)
   {
      cout << "No cities found within the given distance.\n";
   }
}

// Free memory before exiting
void freeMemory(cityNode *head)
{
   cityNode *temp;
   while (head != NULL)
   {
      temp = head;
      head = head->next;
      delete temp;
   }
}

int main()
{
   cityNode *head = NULL;

   cout << "\n---------- Welcome to City Database Management System ----------\n\n";

   int run = 1;
   while (run)
   {
      cout << "Choose the operation to be done:\n";
      cout << "a) Insert a record\n";
      cout << "b) Delete a record by name or coordinate\n";
      cout << "c) Search a record by name or coordinate\n";
      cout << "d) Print all records within a given distance of a specified point\n";
      cout << "e) Exit the Program\n\n";

      char choice;
      cout << "Select choice from [a-e]: ";
      cin >> choice;

      switch (choice)
      {
      case 'a':
         head = insertAtFront(head);
         break;
      case 'b':
      {
         int deleteChoice;
         cout << "1. Delete by City Name\n2. Delete by City Coordinates\n";
         cin >> deleteChoice;
         if (deleteChoice == 1)
         {
            string cityName;
            cout << "Enter the name of the city: ";
            cin >> cityName;
            head = deleteByName(head, cityName);
         }
         else if (deleteChoice == 2)
         {
            float x, y;
            cout << "Enter the x-coordinate of the city: ";
            cin >> x;
            cout << "Enter the y-coordinate of the city: ";
            cin >> y;
            head = deleteByCoordinate(head, x, y);
         }
         else
         {
            cout << "Invalid choice. Try again.\n";
         }
         break;
      }
      case 'c':
      {
         int searchChoice;
         cout << "1. Search by City Name\n2. Search by City Coordinates\n";
         cin >> searchChoice;
         if (searchChoice == 1)
         {
            string cityName;
            cout << "Enter the name of the city: ";
            cin >> cityName;
            searchByName(head, cityName);
         }
         else if (searchChoice == 2)
         {
            float x, y;
            cout << "Enter the x-coordinate of the city: ";
            cin >> x;
            cout << "Enter the y-coordinate of the city: ";
            cin >> y;
            searchByCoordinate(head, x, y);
         }
         else
         {
            cout << "Invalid choice. Try again.\n";
         }
         break;
      }
      case 'd':
      {
         float x, y, distance;
         cout << "Enter the reference x-coordinate: ";
         cin >> x;
         cout << "Enter the reference y-coordinate: ";
         cin >> y;
         cout << "Enter the maximum distance: ";
         cin >> distance;
         printCitiesWithinDistance(head, x, y, distance);
         break;
      }
      case 'e':
         cout << "Exiting the Program...\n";
         freeMemory(head);
         exit(0);
      default:
         cout << "Invalid choice. Try again.\n";
      }

      char turn;
      cout << "Do you want to continue? [Y/N]: ";
      cin >> turn;
      run = (turn == 'y' || turn == 'Y');
   }

   freeMemory(head);
   return 0;
}
