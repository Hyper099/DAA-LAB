#include <iostream>
#include <cmath>
using namespace std;

// Maximum number of cities that can be stored
const int MAX_CITIES = 100;

// Structure for city data
struct City
{
   string cityName;
   float x, y;
};

// Array to store city records and its size
City cityList[MAX_CITIES];
int cityCount = 0;

// Print the list of cities
void printCityList()
{
   if (cityCount == 0)
   {
      cout << "No cities available." << endl;
      return;
   }
   for (int i = 0; i < cityCount; i++)
   {
      cout << cityList[i].cityName << " (" << cityList[i].x << ", " << cityList[i].y << ")" << endl;
   }
}

// Insert a city into the array
void insertCity()
{
   if (cityCount >= MAX_CITIES)
   {
      cout << "City database is full!" << endl;
      return;
   }

   cout << "Enter the name of the city: ";
   cin >> cityList[cityCount].cityName;
   cout << "Enter the x-coordinate of the city: ";
   cin >> cityList[cityCount].x;
   cout << "Enter the y-coordinate of the city: ";
   cin >> cityList[cityCount].y;
   cityCount++;
   cout << "City added successfully." << endl;
}

// Delete a city by name
void deleteByName(string cityName)
{
   for (int i = 0; i < cityCount; i++)
   {
      if (cityList[i].cityName == cityName)
      {
         cityList[i] = cityList[cityCount - 1]; // Move last city to current index
         cityCount--;
         cout << "City " << cityName << " deleted successfully." << endl;
         return;
      }
   }
   cout << "City not found." << endl;
}

// Delete a city by coordinates
void deleteByCoordinate(float x, float y)
{
   for (int i = 0; i < cityCount; i++)
   {
      if (cityList[i].x == x && cityList[i].y == y)
      {
         cityList[i] = cityList[cityCount - 1]; // Move last city to current index
         cityCount--;
         cout << "City with coordinates (" << x << ", " << y << ") deleted successfully." << endl;
         return;
      }
   }
   cout << "City not found." << endl;
}

// Search a city by name
void searchByName(string cityName)
{
   for (int i = 0; i < cityCount; i++)
   {
      if (cityList[i].cityName == cityName)
      {
         cout << "City found: " << cityList[i].cityName << " (" << cityList[i].x << ", " << cityList[i].y << ")" << endl;
         return;
      }
   }
   cout << "City not found." << endl;
}

// Search a city by coordinates
void searchByCoordinate(float x, float y)
{
   for (int i = 0; i < cityCount; i++)
   {
      if (cityList[i].x == x && cityList[i].y == y)
      {
         cout << "City found: " << cityList[i].cityName << " (" << cityList[i].x << ", " << cityList[i].y << ")" << endl;
         return;
      }
   }
   cout << "City not found." << endl;
}

// Print all cities within a given distance from a specified point
void printCitiesWithinDistance(float x, float y, float distance)
{
   bool found = false;
   cout << "Cities within " << distance << " units from (" << x << ", " << y << "):" << endl;
   for (int i = 0; i < cityCount; i++)
   {
      float dist = sqrt(pow(cityList[i].x - x, 2) + pow(cityList[i].y - y, 2));
      if (dist <= distance)
      {
         cout << cityList[i].cityName << " (" << cityList[i].x << ", " << cityList[i].y << ")" << endl;
         found = true;
      }
   }
   if (!found)
   {
      cout << "No cities found within the given distance." << endl;
   }
}

int main()
{
   cout << "\n---------- Welcome to City Database Management System ----------\n\n";
   int run = 1;
   while (run)
   {
      cout << "Choose an operation:\n";
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
         insertCity();
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
            deleteByName(cityName);
         }
         else if (deleteChoice == 2)
         {
            float x, y;
            cout << "Enter the x-coordinate: ";
            cin >> x;
            cout << "Enter the y-coordinate: ";
            cin >> y;
            deleteByCoordinate(x, y);
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
            searchByName(cityName);
         }
         else if (searchChoice == 2)
         {
            float x, y;
            cout << "Enter the x-coordinate: ";
            cin >> x;
            cout << "Enter the y-coordinate: ";
            cin >> y;
            searchByCoordinate(x, y);
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
         printCitiesWithinDistance(x, y, distance);
         break;
      }
      case 'e':
         cout << "Exiting the Program...\n";
         exit(0);
      default:
         cout << "Invalid choice. Try again.\n";
      }
   }
   return 0;
}
