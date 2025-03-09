#include <iostream>
#include <unordered_set>

using namespace std;

// ó�� A ���� ����, B ���� ���� �޾�
// A �迭 �޾�
// B �迭 �޾�
// ȿ���� ���� ������ ���� std::unordered_set ����ϱ� : �ߺ� ���� / ���� �˻� ����
// ���� ���� Ž�� O(1) �ɸ�. �׷��� O( A ���� ���� + B ���� ����)
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int aCount, bCount;
	cin >> aCount >> bCount;

	unordered_set<int> A, B;

	for (int i = 0;i < aCount;i++) {
		int source;
		cin >> source;
		A.insert(source);
	}

	for (int i = 0;i < bCount;i++) {
		int source;
		cin >> source;
		B.insert(source);
	}

	long minusSet = 0;

	for (int x : A) {
		if (B.find(x) == B.end()) {
			minusSet++;
		}
	}

	for (int x : B) {
		if (A.find(x) == A.end()) {
			minusSet++;
		}
	}

	cout << minusSet << endl;

	return 0;

}