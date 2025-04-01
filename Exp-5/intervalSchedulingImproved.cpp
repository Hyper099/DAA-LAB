#include <bits/stdc++.h>
using namespace std;

bool sortEndTime(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
{
   return p1.second.second < p2.second.second;
}

void solve()
{
   int n, count = 1;
   cout << "Enter the number of Events : ";
   cin >> n;

   vector<pair<int, pair<int, int>>> events(n);
   vector<int> eventScheduled;
   cout << "Enter Starting Time followed by Ending Time -> " << endl;

   for (int i = 0; i < n; i++)
   {
      int start, end;
      cin >> start >> end;
      events[i].first = i + 1; // events number.
      events[i].second.first = start;
      events[i].second.second = end;

      if (events[i].second.first > events[i].second.second)
      {
         cout << "Starting time cannot be greater than ending time" << endl;
         return;
      }
   }

   // Sort by Ending time.
   sort(events.begin(), events.end(), sortEndTime);

   // Print
   cout << "Event Number\tStart Time\tEnd Time" << endl;
   for (int i = 0; i < n; i++)
   {
      cout << events[i].first << "\t\t" << events[i].second.first << "\t\t" << events[i].second.second << endl;
   }

   int lastEndTime = events[0].second.second;
   eventScheduled.push_back(events[0].first); // Add the first event to the scheduled list.

   for (int i = 1; i < n; i++)
   {
      if (events[i].second.first >= lastEndTime)
      {
         count++;
         lastEndTime = events[i].second.second;
         eventScheduled.push_back(events[i].first);
      }
   }

   cout << "Maximum number of events that can be scheduled : " << count << endl;
   cout << "Scheduled Events : ";
   for (int i = 0; i < eventScheduled.size(); i++)
      cout << eventScheduled[i] << " ";
   cout << endl;
}

int main()
{
   solve();
   return 0;
}