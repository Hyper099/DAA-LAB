#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
   int steps = 0; // To count the computational steps

   for (int i = 0; i < n - 1; i++)
   {
      int minIndex = i; // Assume the first element is the smallest

      for (int j = i + 1; j < n; j++)
      {
         steps++; // Count the comparison
         if (arr[j] < arr[minIndex])
         {
            minIndex = j; // Update the index of the smallest element
         }
      }

      // Swap the smallest element with the first element of the unsorted part
      if (minIndex != i)
      {
         swap(arr[i], arr[minIndex]);
      }
   }

   cout << "Sorted array is: ";
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
   cout << "Total computational steps: " << steps << endl;
}

int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   int arr[n];
   cout << "Enter elements: ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   selectionSort(arr, n);
   return 0;
}
