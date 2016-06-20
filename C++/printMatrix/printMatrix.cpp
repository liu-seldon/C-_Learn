#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    int minRow = 0,  maxRow = matrix.size();
    int minCol = 0, maxCol = matrix[0].size();
    vector<int> result;
    int indexX = 0, indexY = 0;
    bool rowAdd = true;
    bool colAdd = true;
    while (minRow < maxRow  && minCol < maxCol) {
        for (; indexX >= minCol && indexX < maxCol; colAdd ? indexX++: indexX--) {
            result.push_back(matrix[indexY][indexX]);
        }
        if (indexX >= maxCol) indexX = maxCol - 1;
        if (indexX < minCol) indexX = minCol;
        colAdd ?  indexY++ : indexY--;
        colAdd ? maxCol--: minCol++;
        colAdd = !colAdd;
        cout << "maxRow is " << maxRow << endl;
        for (; indexY >= minRow && indexY < maxRow; rowAdd ? indexY++ : indexY--) {
            result.push_back(matrix[indexY][indexX]);
        }
        if (indexY >= maxRow) indexY = maxRow - 1;
        if (indexY < minRow) indexY = minRow;
        rowAdd ? indexX--: indexX++;
        rowAdd ? minRow++ : maxRow--;
        rowAdd = !rowAdd;
    }
    return result;
}

int main() {
    vector<vector<int> > matrix;
    vector<int> row;
    for (int i = 1; i <= 25; i++) {
        row.push_back(i);
        if (i % 5 == 0) {
            matrix.push_back(row);
            row.clear();
        }
    };

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    vector<int> result = printMatrix(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
