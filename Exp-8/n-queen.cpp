#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n;
int board[MAX];
int solutionCount = 0;

bool isSafe(int row, int col)
{
   for (int i = 0; i < row; i++)
   {
      // Condition to check if a queen exists in one these positions.
      if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
      {
         return false; // if exists then we cant place the queen there.
      }
   }
   return true;
}

void printSolution()
{
   cout << "Board Configuration:\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (board[i] == j)
         {
            cout << " Q ";
         }
         else
         {
            cout << " * ";
         }
      }
      cout << endl;
   }

   cout << "Queen Positions (row, column): ";
   for (int i = 0; i < n; i++)
   {
      cout << "(" << i << ", " << board[i] << ") ";
   }
   cout << "\n\n";
}

void solveNQueen(int row)
{
   if (solutionCount >= 3)
      return;

   if (row == n)
   {
      solutionCount++;
      printSolution();
      return;
   }

   for (int col = 0; col < n; col++)
   {
      if (isSafe(row, col))
      {
         board[row] = col;
         solveNQueen(row + 1);
      }
   }
}

int main()
{
   cout << "Enter the number of queens: ";
   cin >> n;

   if (n < 1 || n > MAX)
   {
      cout << "Please enter n between 1 and " << MAX << endl;
   }
   else
   {
      cout << "Showing up to 3 solutions for the " << n << "-Queens problem:\n\n";
      solveNQueen(0);
      if (solutionCount == 0)
      {
         cout << "No solutions exist for N = " << n << endl;
      }
      else if (solutionCount >= 3)
      {
         cout << "Only first 3 solutions shown. More exist." << endl;
      }
   }

   return 0;
}
