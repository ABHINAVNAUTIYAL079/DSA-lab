#include <stdio.h>

#define MAX 10


struct sparse {
    int row;
    int col;
    int val;
};

void printSparseMatrix(struct sparse matrix[], int nonZeroElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroElements; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].val);
    }
}

void transposeSparseMatrix(struct sparse matrix[], int nonZeroElements, struct sparse transpose[]) {
    int index = 0;
    
    
    for (int i = 0; i < nonZeroElements; i++) {
        transpose[i].row = matrix[i].col;
        transpose[i].col = matrix[i].row;
        transpose[i].val = matrix[i].val;
    }
}

int main() {
    
    struct sparse matrix[MAX] = {
        {0, 1, 5}, 
        {1, 0, 3},  
        {2, 2, 8}   
    };
    
   
    int nonZeroElements = 3;
    
    
    struct sparse transpose[MAX];
    
   
    printf("Original Sparse Matrix:\n");
    printSparseMatrix(matrix, nonZeroElements);
    

    transposeSparseMatrix(matrix, nonZeroElements, transpose);
    
   
    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(transpose, nonZeroElements);

    return 0;
}