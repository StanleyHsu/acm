/**
 * Japan Acm 2.1.4 P32
 */

#include <iostream>

using namespace std;

const int N = 11, M = 13;
char field[N][M] = {
        {'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
        {'.', 'W', 'W', 'W', '.', '.', '.', '.', '.', '.', 'W', 'W', 'W'},
        {'.', '.', '.', '.', 'W', 'W', '.', '.', '.', '.', 'W', 'W', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', 'W', '.', '.', 'W', '.', '.'},
        {'.', '.', 'W', '.', '.', '.', '.', 'W', '.', '.', 'W', '.', '.'},
        {'.', 'W', '.', 'W', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
        {'W', '.', 'W', '.', 'W', '.', '.', '.', '.', '.', '.', 'W', '.'},
        {'.', 'W', '.', 'W', '.', '.', '.', '.', '.', '.', '.', 'W', '.'},
        {'.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.'},
};


void show_yark() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
}

void dfs(int x, int y) {
    field[x][y] = '.';

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy<= 1; dy++ ) {
            int nx = x + dx, ny = y + dy;
            if ( 0<= nx && nx <= N
                && 0 <= ny && ny <= M
                && field[nx][ny] == 'W' ){
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    show_yark();
    cout << endl;

    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << "Lake Counter: " << res << endl;
    return 0;
}