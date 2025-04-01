#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
   int m = A.size();    // Rows in A
   int n = A[0].size(); // Columns in A / Rows in B
   int p = B[0].size(); // Columns in B

   // Resultant matrix
   vector<vector<int>> res(m, vector<int>(p, 0));

   // Matrix multiplication
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < p; j++)
      {
         for (int k = 0; k < n; k++)
         {
            res[i][j] += A[i][k] * B[k][j];
         }
      }
   }

   return res;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>> &matrix)
{
   for (const auto &row : matrix)
   {
      for (const auto &elem : row)
      {
         cout << elem << " ";
      }
      cout << endl;
   }
}

int main()
{
   vector<vector<int>> A = {
       {1, 2},
       {4, 5}};

   vector<vector<int>> B = {
       {7, 8, 13},
       {9, 10, 14},
       {11, 12, 15}};

   vector<vector<int>> C = multiplyMatrices(A, B);

   cout << "Matrix A:" << endl;
   printMatrix(A);

   cout << "Matrix B:" << endl;
   printMatrix(B);

   cout << "Matrix C (A * B):" << endl;
   printMatrix(C);

   return 0;
}
