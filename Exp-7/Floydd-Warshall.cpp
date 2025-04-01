#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>> &dist)
{
   int n = dist.size();

   for (int k = 0; k < n; k++)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (dist[i][k] != INF && dist[k][j] != INF) // Avoid overflow
               dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
         }
      }
   }
}

int main()
{
   vector<vector<int>> dist = {{0, 3, INF, 5},
                               {2, 0, INF, 4},
                               {INF, 1, 0, INF},
                               {INF, INF, 2, 0}};

   floydWarshall(dist);

   // Print the shortest distance matrix
   for (const auto &row : dist)
   {
      for (int val : row)
      {
         if (val == INF)
            cout << "INF ";
         else
            cout << val << " ";
      }
      cout << endl;
   }

   return 0;
}
