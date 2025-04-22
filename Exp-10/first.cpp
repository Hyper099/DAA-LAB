#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct License
{
   int index;
   double rate;
};

bool comparator(const License &a, const License &b)
{
   return a.rate > b.rate; // descending order
}

int main()
{
   int n;
   cout << "Enter number of licenses: ";
   cin >> n;

   vector<License> licenses(n);
   cout << "Enter the growth rates:\n";
   for (int i = 0; i < n; i++)
   {
      cin >> licenses[i].rate;
      licenses[i].index = i + 1;
   }

   // descending sort rates on the basis of growth rate
   sort(licenses.begin(), licenses.end(), comparator);

   double totalCost = 0.0;
   for (int t = 0; t < n; t++)
   {
      totalCost += 100.0 * pow(licenses[t].rate, t);
      cout << "Buy license " << licenses[t].index << " in month " << t+1 << "\n";
   }

   cout << "Total cost: $" << totalCost << endl;
   return 0;
}
