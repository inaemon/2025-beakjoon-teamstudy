#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int maze[100][100];
bool visited[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int BFS(int startX, int startY) { // ���� �켱
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    // (1,1)���� �����ϹǷ� �ִ� �Ÿ� 1�� �ʱ�ȭ
    int distance[100][100] = { 0 };
    distance[startX][startY] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return distance[x][y];
        }


        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && maze[nx][ny] == 1) {
                    visited[nx][ny] = true; // �湮ó��
                    q.push({ nx,ny });
                    distance[nx][ny] = distance[x][y] + 1;
                }
            }
        }
    }
    return -1;
}
   
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    // �̷� �Է� �ޱ� 
    for (int i = 0;i < N;i++) {
        string row;
        cin >> row;

        for (int j = 0;j < M;j++) {
            maze[i][j] = row[j] - '0';
        }
    }
    cout << BFS(0, 0) << "\n";
    return 0;
}

/*
* 2178 �̷�Ž��
* 1�� ����
* N*M �迭
* (1,1)���� (N,M)���� �̵� ���� ĭ�� ���ϱ�.
* N(2<=N), M(<=100) N�� �ٿ��� M�������� �̷� �־���.  
* 
* ��� : ������ �ϴ� �ּ� ĭ ��. 
* BFS ����ϱ�. �ִ� �Ÿ�(�ּ� ĭ �� ã��)
* ť�� ���� ��ġ�� ��������� �Ÿ��� �����ϰ� �����¿� �̵��ϰ� ĭ Ž���ϱ�.
* ������(N,M) ���� �� �̵�Ƚ�� ���
* 
* row[j] - '0'; => ���ڿ� �Է��� ���ڷ� ��ȯ
*/