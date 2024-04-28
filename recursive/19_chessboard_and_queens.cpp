#include <iostream>
#include <vector>

using namespace std;

bool safe(int row, int col, vector<pair<int, int>> queens) {
    for (auto q: queens) {
        if (abs(q.first - row) == abs(q.second - col)) {
            return false;
        }
        if (q.first == row or q.second == col) {
            return false;
        }
    }
    return true;
}


void solve(int row, vector<string> &board, int &combinations, vector<pair<int, int>> queens) {
    if (row == board.size()) {
        combinations++;
        return;
    }

    for (int col = 0; col < board.size(); ++col) {
        if (board[row][col] == '.' && safe(row, col, queens)) {
            queens.emplace_back(row, col);
            solve(row + 1, board, combinations, queens);
            queens.pop_back();
        }
    }
}

int main() {
    vector<string> board(8);
    for (auto &i: board) {
        cin >> i;
    }
    int combinations = 0;
    vector<pair<int, int>> queens;

    solve(0, board, combinations, queens);

    cout << combinations << endl;

    return 0;
}
