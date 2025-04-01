#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
   int steps = 0; // To count the computational steps

   for (int i = 1; i < n; i++)
   {
      int key = arr[i];
      int j = i - 1;

      // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
      while (j >= 0)
      {
         steps++; // Count the comparison in the `while` condition
         if (arr[j] > key)
         {
            arr[j + 1] = arr[j];
            j--;
         }
         else
            break;
      }
      arr[j + 1] = key;
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

   insertionSort(arr, n);
   return 0;
}
