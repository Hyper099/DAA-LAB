#include <iostream>
#include <vector>
using namespace std;

// Function to print the board and queen positions
void printBoard(vector<vector<int>> &board, int n, vector<pair<int, int>> &positions)
{
   cout << "Board Configuration:\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << (board[i][j] == 1 ? "Q " : ". ");
      }
      cout << endl;
   }

   cout << "Queen Positions (row, column): ";
   for (auto pos : positions)
   {
      cout << "(" << pos.first << ", " << pos.second << ") ";
   }
   cout << "\n\n";
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
   // Check column (upwards)
   for (int i = 0; i < row; i++)
   {
      if (board[i][col] == 1)
         return false;
   }

   // Check upper-left diagonal
   for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
   {
      if (board[i][j] == 1)
         return false;
   }

   // Check upper-right diagonal
   for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
   {
      if (board[i][j] == 1)
         return false;
   }

   return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(vector<vector<int>> &board, int row, int n, vector<pair<int, int>> &positions, int &solutionCount)
{
   if (solutionCount >= 3)
      return true; // Stop further processing after 3 solutions

   if (row == n)
   {
      solutionCount++;
      if (solutionCount <= 3)
      {
         printBoard(board, n, positions);
      }
      return true;
   }

   bool result = false;

   for (int col = 0; col < n; col++)
   {
      if (isSafe(board, row, col, n))
      {
         board[row][col] = 1;
         positions.push_back({row, col});

         result = solveNQueens(board, row + 1, n, positions, solutionCount) || result;

         board[row][col] = 0;
         positions.pop_back();

         if (solutionCount >= 3)
            break; // Stop trying more columns once 3 solutions are found
      }
   }

   return result;
}

int main()
{
   int n;
   cout << "Enter the value of N (e.g., 4): ";
   cin >> n;

   vector<vector<int>> board(n, vector<int>(n, 0));
   vector<pair<int, int>> positions;
   int solutionCount = 0;

   if (!solveNQueens(board, 0, n, positions, solutionCount))
   {
      cout << "No solution exists for N = " << n << endl;
   }
   else if (solutionCount > 3)
   {
      cout << "Only first 3 configurations shown (more exist)." << endl;
   }

   return 0;
}
