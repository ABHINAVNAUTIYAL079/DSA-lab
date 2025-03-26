#include <bits/stdc++.h>
using namespace std;


void fastTranspose(int sparse[][3], int transposed[][3]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];


    transposed[0][0] = cols;
    transposed[0][1] = rows;
    transposed[0][2] = nonZero;


    int count[cols] = {0}; 
    for (int i = 1; i <= nonZero; i++) {
        count[sparse[i][1]]++;
    }


    int position[cols] = {0};
    position[0] = 1; 
    for (int i = 1; i < cols; i++) {
        position[i] = position[i - 1] + count[i - 1];
    }

    
    for (int i = 1; i <= nonZero; i++) {
        int col = sparse[i][1];  
        int pos = position[col];

        transposed[pos][0] = sparse[i][1]; 
        transposed[pos][1] = sparse[i][0]; 
        transposed[pos][2] = sparse[i][2]; 

        position[col]++;
    }
}


void printSparseMatrix(int sparse[][3]) {
    int nonZero = sparse[0][2]; 
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
}

int main() {
    
    int sparse[6][3] = {
        {4, 4, 5},  
        {0, 2, 10}, 
        {1, 1, 20},
        {2, 3, 30},
        {3, 0, 40},
        {3, 2, 50}
    };

    int transposed[6][3]; 

    cout << "Original Sparse Matrix:" << endl;
    printSparseMatrix(sparse);

    fastTranspose(sparse, transposed);

    cout << "\nFast Transposed Matrix:" << endl;
    printSparseMatrix(transposed);

    return 0;
}
