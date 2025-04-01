#include <iostream>
#include <vector>
using namespace std;

// Function to print matrix.
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

// Function to negate matrix.
vector<vector<int>> neg(const vector<vector<int>> &A, int r)
{
   vector<vector<int>> C(r, vector<int>(r));
   for (int i = 0; i < r; i++)
      for (int j = 0; j < r; j++)
         C[i][j] = -A[i][j];
   return C;
}

// Function to take sum of two matrices.
vector<vector<int>> matSum(const vector<vector<int>> &A, const vector<vector<int>> &B, int r)
{
   vector<vector<int>> C(r, vector<int>(r));
   for (int i = 0; i < r; i++)
      for (int j = 0; j < r; j++)
         C[i][j] = A[i][j] + B[i][j];
   return C;
}

// Function to extract sub-matrix from a matrix.
vector<vector<int>> subMat(const vector<vector<int>> &A, int inx, int iny, int r)
{
   vector<vector<int>> C(r, vector<int>(r));
   for (int i = 0; i < r; i++)
      for (int j = 0; j < r; j++)
         C[i][j] = A[inx + i][iny + j];
   return C;
}

// Strassen's algorithm.
vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B, int r)
{
   int n = r / 2;

   if (r == 2)
   {
      vector<vector<int>> s(2, vector<int>(2, 0));
      // Standard 2x2 matrix multiplication
      s[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
      s[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
      s[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
      s[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
      return s;
   }

   // Compute the 7 Strassen products using:
   // P1 = (A11) * (B12 - B22)
   vector<vector<int>> p1 = strassen(subMat(A, 0, 0, n), matSum(subMat(B, 0, n, n), neg(subMat(B, n, n, n), n), n), n);
   // P2 = (A11 + A12) * (B22)
   vector<vector<int>> p2 = strassen(matSum(subMat(A, 0, 0, n), subMat(A, 0, n, n), n), subMat(B, n, n, n), n);
   // P3 = (A21 + A22) * (B11)
   vector<vector<int>> p3 = strassen(matSum(subMat(A, n, 0, n), subMat(A, n, n, n), n), subMat(B, 0, 0, n), n);
   // P4 = (A22) * (B21 - B11)
   vector<vector<int>> p4 = strassen(subMat(A, n, n, n), matSum(subMat(B, n, 0, n), neg(subMat(B, 0, 0, n), n), n), n);
   // P5 = (A11 + A22) * (B11 + B22)
   vector<vector<int>> p5 = strassen(matSum(subMat(A, 0, 0, n), subMat(A, n, n, n), n), matSum(subMat(B, 0, 0, n), subMat(B, n, n, n), n), n);
   // P6 = (A12 - A22) * (B21 + B22)
   vector<vector<int>> p6 = strassen(matSum(subMat(A, 0, n, n), neg(subMat(A, n, n, n), n), n), matSum(subMat(B, n, 0, n), subMat(B, n, n, n), n), n);
   // P7 = (A11 - A21) * (B11 + B12)
   vector<vector<int>> p7 = strassen(matSum(subMat(A, 0, 0, n), neg(subMat(A, n, 0, n), n), n), matSum(subMat(B, 0, 0, n), subMat(B, 0, n, n), n), n);

   vector<vector<int>> res(r, vector<int>(r));

   // Compute the resulting submatrices using:
   // C11 = P5 + P4 - P2 + P6
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         res[i][j] = p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j];
   // C12 = P1 + P2
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         res[i][j + n] = p1[i][j] + p2[i][j];
   // C21 = P3 + P4
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         res[i + n][j] = p3[i][j] + p4[i][j];
   // C22 = P5 + P1 - P3 - P7
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         res[i + n][j + n] = p5[i][j] + p1[i][j] - p3[i][j] - p7[i][j];

   return res;
}

int main()
{
   vector<vector<int>> A = {
       {1, 2, 3, 4},
       {4, 5, 6, 7},
       {7, 8, 9, 10},
       {10, 11, 12, 13}};

   vector<vector<int>> B = {
       {12, 11, 10, 9},
       {9, 8, 7, 6},
       {6, 5, 4, 3},
       {3, 2, 1, 0}};

   vector<vector<int>> C = strassen(A, B, 4);

   cout << "Matrix A:" << endl;
   printMatrix(A);

   cout << "Matrix B:" << endl;
   printMatrix(B);

   cout << "Matrix C (A * B):" << endl;
   printMatrix(C);

   return 0;
}
