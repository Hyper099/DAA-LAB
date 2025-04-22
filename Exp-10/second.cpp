#include <iostream>
#include <vector>

using namespace std;

int findPeak(const vector<int> &A)
{
   int low = 0, high = A.size() - 1;

   while (low < high)
   {
      int mid = low + (high - low) / 2;

      if (A[mid] < A[mid + 1])
      {
         low = mid + 1;
      }
      else
      {
         high = mid;
      }
   }

   return low; // or high, since low == high
}

int main()
{
   int n;
   cout << "Enter the size of array: ";
   cin >> n;
   vector<int> A(n);
   cout << "Enter the unimodal array elements:\n";
   for (int i = 0; i < n; i++)
   {
      cin >> A[i];
   }

   int peakIndex = findPeak(A);
   cout << "Peak found at index: " << peakIndex << " with value: " << A[peakIndex] << endl;
   return 0;
}
