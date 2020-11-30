#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;



vector<vector<int>> edge;
vector<vector<int>>visited;
int row[4] = { -1,0,1,0 };
int col[4] = { 0,-1,0,1 };
int N, M;

typedef struct _pos {
    int x;
    int y;
}pos;

int checkRangeOver(pos p) {

    return !(p.x > M + 1 || p.x<1 || p.y>N + 1 || p.y < 1) ? true : false;
}

void bfs(int i, int j) {

    queue<pos> q;

    pos temp, cur;
    temp.x = j; temp.y = i;

    q.push(temp);
    visited[temp.y][temp.x] = 1;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp.x == M && temp.y == N) return;

        for (int a = 0; a < 4; ++a) {
            cur.y = row[a] + temp.y;
            cur.x = col[a] + temp.x;

            if (checkRangeOver(cur) && !visited[cur.y][cur.x]
                && edge[cur.y][cur.x]) {

                q.push(cur);
                visited[cur.y][cur.x] = visited[temp.y][temp.x] + 1;
            }
        }
    }
}

int main(void) {

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%1d", &edge[i][j]);
        }
    }

    bfs(1, 1);

    printf("%d\n", visited[N][M]);

    return 0;
}
