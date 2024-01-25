#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void inputMatrix(int** A, int m, int n) 
{
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> A[i][j];
        }
    }
}

void displayMatrix(const int* const * A, int m, int n)
{
    cout << "Matrix elements:" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int sumOfElements(const int* const * A, int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            sum += A[i][j];
        }
    }
    return sum;
}

void rowWiseSum(const int* const * A, int m, int n) 
{
    cout << "Row-wise sum of the matrix:" << endl;
    for (int i = 0; i < m; ++i) 
    {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) 
        {
            rowSum += A[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }
}

void columnWiseSum(const int* const * A, int m, int n)
{
    cout << "Column-wise sum of the matrix:" << endl;
    for (int j = 0; j < n; ++j)
    {
        int colSum = 0;
        for (int i = 0; i < m; ++i)
        {
            colSum += A[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }
}

int** transposeMatrix(const int* const * A, int m, int n)
{
    int** transposedMatrix = new int*[n];
    for (int i = 0; i < n; ++i) 
    {
        transposedMatrix[i] = new int[m];
        for (int j = 0; j < m; ++j) 
        {
            transposedMatrix[i][j] = A[j][i];
        }
    }
    return transposedMatrix;
}

void deleteMatrix(int** A, int m)
{
    for (int i = 0; i < m; ++i) 
    {
        delete[] A[i];
    }
    delete[] A;
}

int main() 
{
    int m, n;

    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    // Allocate memory for the dynamic 2D array
    int** A = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        A[i] = new int[n];
    }

    int ch;
    do 
    {
        cout << endl;
        cout << "Menu: " << endl
             << "1. Input elements in the matrix"<<endl
             << "2. Display elements of the matrix"<<endl
             << "3. Sum of all elements of the matrix"<<endl
             << "4. Display row-wise sum of the matrix"<<endl
             << "5. Display column-wise sum of the matrix"<<endl
             << "6. Transpose of the matrix"<<endl
             << "0. Exit"<<endl
             << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch) 
        {
            case 1:
                inputMatrix(A, m, n);
                break;
            case 2:
                displayMatrix(A, m, n);
                break;
            case 3:
                cout << "Sum of all of the elements:: " << sumOfElements(A, m, n) << endl;
                break;
            case 4:
                rowWiseSum(A, m, n);
                break;
            case 5:
                columnWiseSum(A, m, n);
                break;
            case 6:
            {
                int** transposed = transposeMatrix(A, m, n);
                displayMatrix(const_cast<const int* const*>(transposed), n, m);
                deleteMatrix(transposed, n);
                break;
            }
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } 
    while (choice != 0);
    deleteMatrix(A, m);

    return 0;
}
