#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, M, N, K;
int field[50][50];
bool visited[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void DFS(int x, int y) {
    visited[x][y] = true;

    for (int i = 0;i < 4;i++) { //�����¿� �̵��ؼ� ����� ���� ��� Ž��, �湮�Ѱ� visited�� true
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx <M && ny >= 0 && ny<N) { // ��ġ ��ȿ���� Ȯ��
            if (!visited[nx][ny] && field[nx][ny] == 1) { // �湮���� �ʾҰ� ���� �ִ� �� ã�Ƽ� �ٽ� DFS
                DFS(nx, ny);
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> M >> N >> K;

        fill(&field[0][0], &field[0][0] + 50 * 50, 0);
        fill(&visited[0][0], &visited[0][0] + 50 * 50, false);

        //���� ��ġ �Է�
        for (int i = 0;i < K;i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int worm_count = 0;

        // ã��
        for (int i = 0;i < M;i++) {
            for (int j = 0;j < N;j++) {
                if (!visited[i][j] && field[i][j] == 1) { // �湮���� �ʾҰ� �ش� ��ġ�� ���� �ִ� ���
                    DFS(i, j);
                    worm_count++;
                }
            }
        }
        cout << worm_count << "\n";
    }
    return 0;
}

/*
* 1012 ����� ����
* 
* � ���߿� �Ѹ����� ��� ������ ������ �ٸ� ���߷� �̵�����. �������κ��� ��ȣ.
* �׽�Ʈ ���� T, ���α���M 1-50, ���α��� N 1- 50, ��ġ ���� K 1- 2500, X(0 ~ M-1), Y(0~N-1) �־���. ��ġ ���� ��� ����
* 
* => ����� ���� ������ ����.
* �迭�� ǥ���ϱ�. �湮�� ���ߴ� 0���� ����. ������ ���� ����. 
* DFS �ݺ�
* 
*/