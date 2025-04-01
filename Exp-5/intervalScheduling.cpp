#include <bits/stdc++.h>
using namespace std;

bool sortEndTime(pair<int, int> &p1, pair<int, int> &p2)
{
   return p1.second < p2.second; // Sort by ending time in ascending order.
}

void solve()
{
   int n, count = 1;
   cout << "Enter the number of Events : ";
   cin >> n;

   vector<pair<int, int>> events(n);
   cout << "Enter Starting Time followed by Ending Time -> " << endl;

   for (int i = 0; i < n; i++)
   {
      int start, end;
      cin >> start >> end;
      events[i].first = start;
      events[i].second = end;

      if (events[i].first > events[i].second)
      {
         cout << "Starting time cannot be greater than ending time" << endl;
         return;
      }
   }

   // Sort by Ending time.
   sort(events.begin(), events.end(), sortEndTime);

   // for (int i = 0; i < n; i++)
   //    cout << "(" << events[i].first << ", " << events[i].second << ")" << endl;

   int lastEndTime = events[0].second;
   for (int i = 1; i < n; i++)
   {
      if (events[i].first >= lastEndTime)
      {
         count++;
         lastEndTime = events[i].second;
      }
   }

   cout << "Maximum number of events that can be scheduled is : " << count << endl;
}

int main()
{
   solve();
   return 0;
}