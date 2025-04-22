#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Representing infinity (a very large number)

int N;                    // Number of cities
vector<vector<int>> cost; // Cost matrix

int final_res = INF;    // Store the final minimum cost
vector<int> final_path; // Store the final path

// Function to find the minimum edge cost going out from city i
int firstMin(const vector<vector<int>> &cost, int i)
{
   int min_val = INF;
   for (int k = 0; k < N; k++)
   {
      if (cost[i][k] != 0 && cost[i][k] < min_val)
         min_val = cost[i][k];
   }
   return min_val;
}

// Function to find the second minimum edge cost going out from city i
int secondMin(const vector<vector<int>> &cost, int i)
{
   int first = INF, second = INF;
   for (int j = 0; j < N; j++)
   {
      if (i == j)
         continue;
      if (cost[i][j] <= first)
      {
         second = first;
         first = cost[i][j];
      }
      else if (cost[i][j] < second && cost[i][j] != first)
         second = cost[i][j];
   }
   return second;
}

// Recursive function to solve TSP using Branch and Bound
void TSPRec(vector<vector<int>> &cost, vector<bool> &visited, int curr_bound,int curr_weight, int level, vector<int> &curr_path)
{

   if (level == N)
   {
      // All cities are visited, return to starting point
      int cost_to_last = cost[curr_path[level - 1]][curr_path[0]];
      if (cost_to_last != 0)
      {
         int curr_res = curr_weight + cost_to_last;

         if (curr_res < final_res)
         {
            final_path = curr_path;
            final_path.push_back(curr_path[0]);
            final_res = curr_res;
         }
      }
      return;
   }

   for (int i = 0; i < N; i++)
   {
      int cost_to_city = cost[curr_path[level - 1]][i];

      if (!visited[i] && cost_to_city!= 0)
      {
         int temp = curr_bound;
         curr_weight += cost_to_city;

         // Calculate new bound
         if (level == 1)
            curr_bound -= ((firstMin(cost, curr_path[level - 1]) + firstMin(cost, i)) / 2);
         else
            curr_bound -= ((secondMin(cost, curr_path[level - 1]) + firstMin(cost, i)) / 2);

         // If cost with the current bound is less than final result, proceed
         if (curr_bound + curr_weight < final_res)
         {
            curr_path[level] = i;
            visited[i] = true;

            TSPRec(cost, visited, curr_bound, curr_weight, level + 1, curr_path);
         }
         // Backtrack
         curr_weight -= cost_to_city;
         curr_bound = temp;

         fill(visited.begin(), visited.end(), false);
         for (int j = 0; j <= level - 1; j++)
         {
            visited[curr_path[j]] = true;
         }
      }
   }
}

void TSP()
{
   vector<int> curr_path(N + 1, -1); // Stores current path
   vector<bool> visited(N, false);   // To track visited cities

   // Calculate initial bound
   int curr_bound = 0;
   for (int i = 0; i < N; i++)
      curr_bound += (firstMin(cost, i) + secondMin(cost, i));

   curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

   visited[0] = true; // Start from city 0
   curr_path[0] = 0;

   TSPRec(cost, visited, curr_bound, 0, 1, curr_path);
}

int main()
{
   cout << "Enter number of cities: ";
   cin >> N;

   // Matrix which stores cost of travelling to that city.
   // Example 
//    0 10 15 20
//    10 0 35 25
//    15 35 0 30
//    20 25 30 0
   cost = vector<vector<int>>(N, vector<int>(N));
   cout << "Enter the cost matrix:\n";
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         cin >> cost[i][j];

   
   //! Initiate Algo.
   TSP();

   cout << "\nMinimum cost: " << final_res << endl;
   cout << "Path Taken: ";
   for (int city : final_path){
      if(city == -1)continue;
      cout << city << " ";
   }
   cout << endl;

   return 0;
}
