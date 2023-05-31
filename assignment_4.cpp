#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> answer;

void print_board()
{
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "solution " << i + 1 << endl;
        for (auto &str : answer[i])
        {
            for (auto &letter : str)
                cout << letter << " ";
            cout << endl;
        }
        cout << "\n\n";
    }
    return;
}

int safe(int row, int col, vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
        if (board[i][col] == 'Q')
            return false;

    int i = row, j = col;
    while (i >= 0 && j >= 0)
        if (board[i--][j--] == 'Q')
            return false;
    i = row, j = col;
    while (i >= 0 && j < board.size())
        if (board[i--][j++] == 'Q')
            return false;
    return true;
}

void rec(vector<string> board, int row)
{
    if (row == board.size())
    {
        answer.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
        if (safe(row, i, board))
        {
            board[row][i] = 'Q';
            rec(board, row + 1);
            board[row][i] = '*';
        }
    return;
}

int main()
{
    string s;
    int j;
    cin >> j;
    int n = j;
    // for (int n = 0; n < j; ++n)
    // {
        answer.clear();
        for (int i = 0; i < n; i++)
            s += '*';
        vector<string> board(n, s);
        rec(board, 0);

        cout << n << " -- " << answer.size() << endl;
         print_board();
    // }

    return 0;
}