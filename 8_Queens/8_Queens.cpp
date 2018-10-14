#include <iostream>
#include <windows.h>
using namespace std;

int queen[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int result[100][8];
int _count = 0;
int _temp_count = 0;

bool Is_meet(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (col == queen[i])
            return true;
        if ((row + col) == (i + queen[i]))
            return true;
        if ((row - col) == (i - queen[i]))
            return true;
    }
    queen[row] = col;
    return false;
}

void display(int* queen_temp) {
    for (int i = 0; i < 8; i++) {
        if (queen_temp[i] == -1) {
            for (int j = 0; j < 8; j++)
                cout << ". ";
            cout << endl;
        }
        else {
            for (int j = 0; j < queen_temp[i]; j++) {
                cout << ". ";
            }
            cout << "# ";
            for (int k = queen_temp[i] + 1; k < 8; k++) {
                cout << ". ";
            }
            cout << endl;
        }
    }
}

void findQueenPosition(int row) {
    for (int j_col = 0; j_col < 8; j_col++) {
        if (!Is_meet(row, j_col)) {
            if (row == 7) {
                for (int i = 0; i < 8; i++) {
                    result[_count][i] = queen[i];
                }
                _count++;
                break;
            }
            else {
                findQueenPosition(row + 1);
            }
        }
    }
    queen[row] = -1;
    return;
}

int main() {
    findQueenPosition(0);
    cout << "The total case of eight queen problem is: " << _count << endl;
    for (int i = 0; i < _count; i++) {
        cout << "Case " << i << endl;
        display(result[i]);
    }
    return 0;
}