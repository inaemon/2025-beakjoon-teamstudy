#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> priorities; // �߿䵵 �켱���� ť

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({ priority, i });
            priorities.push(priority);
        }

        int printOrder = 0;

        while (!q.empty()) {
            int currentPriority = q.front().first;
            int currentIndex = q.front().second;
            q.pop();

            // ���� ������ �߿䵵�� ���� ���� ���
            if (currentPriority == priorities.top()) {
                printOrder++;
                priorities.pop(); // �켱���� ť���� ����

                // �ñ��� ������ ��µ� ���
                if (currentIndex == M) {
                    cout << printOrder << '\n';
                    break;
                }
            }
            else {
                // �߿䵵�� ���� ������ ���� �ִ� ��� ť�� �ڷ� �̵�
                q.push({ currentPriority, currentIndex });
            }
        }
    }

    return 0;
}


/*
1966 ������ ť

���� ť�� ���� �տ� �ִ� ������ �߿䵵 Ȯ��. 
���� �������� �߿䵵 ���� �� ������ ���� ���� �� �ڷ� ���ġ ��. �׷��� ������ �μ�. 
���� �� �׳� �μ�.

ABCD -> BCDA -> CDAB -> C, DAB -> D, AB -> A, B -> B

�߿䵵 1 ~ 9

ù �ٿ� �׽�Ʈ ���̽� ��. �׽�Ʈ ���̽��� �� �پ�. 
�� ������ 0��°. 

���� ���� �ñݹ��� ���°�� �μ�Ǵ���. 

�׳� ť���� �� �տ� �� �����ͼ� ���ϰ� �³�? �׷� break. �ƴϴ� ������ ���� �ڷ� �־�. �װ� ť�� �� ������ �ݺ���.
*/
