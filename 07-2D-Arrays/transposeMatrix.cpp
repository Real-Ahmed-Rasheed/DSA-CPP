#include <iostream>
using namespace std;
int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    int i = 0;
    int j = 0;

    while (i < rows)
    {
        j = i + 1;
        while (j < cols)
        {
            swap(matrix[i][j], matrix[j][i]);
            j++;
        }

        i++;
    }

    for (int i = 0; i < rows; i++)
    {
        int s = 0;
        int e = cols - 1;
        swap(matrix[i][s++], matrix[i][e--]);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}