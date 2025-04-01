#include <bits/stdc++.h>
using namespace std;

int merges = 0;
int recursions = 0;

// The subarrays are arr[low...mid] and arr[mid+1...high]
void merge(vector<int> &arr, int low, int mid, int high)
{
   vector<int> temp;
   int left = low, right = mid + 1;

   while (left <= mid && right <= high)
   {
      merges++;
      if (arr[left] <= arr[right])
      {
         temp.push_back(arr[left]);
         left++;
      }
      else
      {
         temp.push_back(arr[right]);
         right++;
      }
   }

   // Copy remaining elements from the left subarray
   while (left <= mid)
   {
      temp.push_back(arr[left]);
      left++;
   }

   // Copy remaining elements from the right subarray
   while (right <= high)
   {
      temp.push_back(arr[right]);
      right++;
   }

   // Copy the merged elements back into the original array
   for (int i = low; i <= high; i++)
   {
      arr[i] = temp[i - low];
   }
}

void mergeSort(vector<int> &arr, int low, int high)
{
   recursions++;

   if (low >= high)
      return;

   int mid = (low + high) / 2;

   // Recursively sort the left half and the right half
   mergeSort(arr, low, mid);
   mergeSort(arr, mid + 1, high);
   
   // Merge the sorted halves
   merge(arr, low, mid, high);
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

   mergeSort(arr, 0, n - 1);

   cout << "Sorted array is: ";
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;

   cout << "Total computational steps: " << merges + recursions << " (Recursions: " << recursions << ", Merges: " << merges << ")" << endl;

   return 0;
}
