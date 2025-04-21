#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>> &dist)
{
   int n = dist.size();

   for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            if (dist[i][k] != INF && dist[k][j] != INF)
               dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

   // Check for negative weight cycle
   for (int i = 0; i < n; i++)
   {
      if (dist[i][i] < 0)
      {
         cout << "Graph contains a negative weight cycle\n";
         return;
      }
   }
}

int main()
{
   vector<vector<int>> dist = {
       {0, -1, 4, INF, INF},
       {INF, 0, 3, 2, 2},
       {INF, INF, 0, INF, INF},
       {INF, 1, 5, 0, INF},
       {INF, INF, INF, -3, 0}};

   floydWarshall(dist);

   // Print the shortest distance matrix
   for (const auto &row : dist)
   {
      for (int val : row)
         cout << (val == INF ? "INF" : to_string(val)) << " ";
      cout << endl;
   }

   return 0;
}
