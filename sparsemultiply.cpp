#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, value;
};

vector<Element> multiplySparseMatrices(vector<Element> &A, vector<Element> &B, int rA, int cA, int cB) {
    vector<Element> result;
    vector<vector<Element>> B_col(cB);
    for (const auto &ele : B) {
        B_col[ele.col].push_back(ele);
    }
    for (const auto &eleA : A) {
        for (const auto &eleB : B_col[eleA.col]) {
            int row = eleA.row;
            int col = eleB.col;
            int val = eleA.value * eleB.value;
            bool found = false;
            for (auto &eleR : result) {
                if (eleR.row == row && eleR.col == col) {
                    eleR.value += val;
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back({row, col, val});
            }
        }
    }
    return result;
}

void printSparseMatrix(vector<Element> &mat, int rows, int cols) {
    cout << "Sparse Matrix Representation (row, col, value):\n";
    for (const auto &ele : mat) {
        cout << "(" << ele.row << ", " << ele.col << ", " << ele.value << ")\n";
    }
}

int main() {
    int rA = 3, cA = 3, rB = 3, cB = 3;
    vector<Element> A = {{0, 0, 1}, {0, 2, 2}, {1, 1, 3}, {2, 0, 4}, {2, 2, 5}};
    vector<Element> B = {{0, 1, 6}, {1, 0, 7}, {1, 2, 8}, {2, 1, 9}};
    vector<Element> result = multiplySparseMatrices(A, B, rA, cA, cB);
    printSparseMatrix(result, rA, cB);
    return 0;
}
