#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** create2DArray(int col, int row) {
    T** matrix = new T * [col];
    for (size_t i = 0; i < col; i++) {
        matrix[i] = new T[row];
    }
    return matrix;
}

template<typename T>
void fill2DArray(T** matrix, int col, int row) {
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

template<typename T>
void print2DArray(T** matrix, int col, int row) {
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void delete2DArray(T** matrix, int col) {
    for (size_t i = 0; i < col; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
T** add2DArray(T** matrix, int& col, int row, T* addCol, int goPos) {
    T** newMatrix = create2DArray<T>(col + 1, row);
    for (size_t i = 0; i < col + 1; i++) {
        for (size_t j = 0; j < row; j++) {
            if (i == goPos) {
                newMatrix[i][j] = addCol[j];
            }
            else if (i < goPos) {
                newMatrix[i][j] = matrix[i][j];
            }
            else {
                newMatrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    col = col + 1;
    delete2DArray(matrix, col - 1);

    return newMatrix;
}

int main() {
    srand(time(0));

    int col, row;

    cout << "Enter the number of columns: ";
    cin >> col;
    cout << "Enter the number of rows: ";
    cin >> row;

    int** matrix = create2DArray<int>(col, row);
    fill2DArray<int>(matrix, col, row);
    print2DArray<int>(matrix, col, row);

    int* addCol = new int[row];
    cout << "Enter the numbers for the new column: ";
    for (size_t i = 0; i < row; i++) {
        cin >> addCol[i];
    }

    int goPos;
    cout << "Enter the position for new column (0 - " << col << "): ";
    cin >> goPos;

    if (goPos < 0 || goPos > col) {
        cout << "No! Bad position..." << endl;
    }
    else {
        matrix = add2DArray<int>(matrix, col, row, addCol, goPos);
        print2DArray<int>(matrix, col, row);
    }

    delete[] addCol;
    delete2DArray<int>(matrix, col);

    return 0;
}