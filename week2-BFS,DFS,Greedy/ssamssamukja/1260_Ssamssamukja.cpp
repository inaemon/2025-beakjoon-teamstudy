#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void DFS(int v) { // ���� �켱
    cout << v << " "; // �湮�� ��� ���
    visited[v] = true;

    for (int next : graph[v]) {
        if (!visited[next]) {
            DFS(next); // ���
        }
    }
}

void BFS(int start) { // ���� �켱
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int next : graph[v]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0;i < M;i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // ����� �׷����̱� ����
    }

    // ���� ��ȣ ���� �ͺ��� �湮�ϱ� ���� �����ϱ�
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS
    fill(visited, visited + 1001, false);
    DFS(V);
    cout << "\n";

    // BFS
    fill(visited, visited + 1001, false);
    BFS(V);
    cout << "\n";

    return 0;
}

/*
* DFS�� BFS
* DFS�� ����(���)�� ����Ͽ� ���� �켱 Ž��
* BFS�� ť�� ����Ͽ� �ʺ� �켱 Ž��
* 
* �� ���� ���� ���� �� ���� ���� ����, �������.
* 
* 
* fill : �迭�̳� �����̳��� ��� ���Ҹ� Ư�� ������ �ʱ�ȭ�� �� ��� (�����ּ�, ���ּ�, ä�ﰪ)
* �迭 ������ �ʱ�ȭ ����
*/