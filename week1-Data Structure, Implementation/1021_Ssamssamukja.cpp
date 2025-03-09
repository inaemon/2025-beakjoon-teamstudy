#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int totalMoves = 0;
    while (M--) {
        int target;
        cin >> target;

        int targetIndex = 0;
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                targetIndex = i;
                break;
            }
        }

        // ����, ������ �̵� �� �ּ� ���� ����
        if (targetIndex <= dq.size() / 2) {
            // ���� �̵��� �� ���� ���
            totalMoves += targetIndex;
            while (targetIndex--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            // ������ �̵��� �� ���� ���
            totalMoves += dq.size() - targetIndex;
            int moves = dq.size() - targetIndex;
            while (moves--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        // �̾Ƴ�
        dq.pop_front();
    }

    cout << totalMoves << endl;
    return 0;
}



/*
1021 ȸ���ϴ� ť
1. ù ��° ���� �̾Ƴ���
2. �������� �� ĭ �̵����� ù��° ���� �̾Ƴ��� �ڷ� �̵���Ű��. �ڿ��� �б�
3. ���������� �� ĭ �̵����� �� ���� ���� �̾Ƴ��� ������ �̵���Ű��. �տ��� �б�

������� �ϴ� ã�� ���� �ڶ� ������� ���� ���̶� ������� �ε����� Ȯ��. 
�� ù��° ���Ұ� �Ǿ�� �ϴ� ���ݾ�. 

 ť�� ũ�� N, �̾Ƴ� ������ ���� M

*/