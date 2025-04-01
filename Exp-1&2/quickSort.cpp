#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;
int swaps = 0;
int recursions = 0;

int partition(vector<int> &arr, int low, int high)
{
   // First element is set as the pivot.
   int pivot = arr[low];
   int i = low;
   int j = high;

   while (i < j)
   {
      while (i <= high - 1 && arr[i] <= pivot)
      {
         comparisons++;
         i++;
      }

      while (j >= low + 1 && arr[j] > pivot)
      {
         comparisons++;
         j--;
      }

      if (i < j)
      {
         swap(arr[i], arr[j]);
         swaps++;
      }
   }

   // Once above loop is finished, place the pivot element in the correct place
   swap(arr[low], arr[j]);
   swaps++;
   return j; // We will return the pivoted element position and do the qucik sort in the left subarray and right subarray of it.
}

void quickSort(vector<int> &arr, int low, int high)
{
   recursions++;
   if (low < high)
   {
      int pIndex = partition(arr, low, high);
      quickSort(arr, low, pIndex - 1);
      quickSort(arr, pIndex + 1, high);
   }
}

int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   vector<int> arr(n);
   cout << "Enter elements: ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   quickSort(arr, 0, n - 1);

   cout << "Sorted array is: ";
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;

   cout << "Total comparisons: " << comparisons << endl;
   cout << "Total swaps: " << swaps << endl;
   cout << "Total recursive calls: " << recursions << endl;
   cout << "Total computational steps (comparisons + swaps + recursions): " << (comparisons + swaps + recursions) << endl;

   return 0;
}
