#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int getNumLines(long long lineLength, vector<long long>& lineVector) {
	int nums = 0;
	for (long long cable : lineVector) {
		nums += cable / lineLength;
	}
	return nums;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K;
	int N;
	cin >> K;
	cin >> N;
	vector<long long> lineVector(K);

	for (int i = 0;i < K;i++) {
		cin >> lineVector[i];
	}
	long long left = 1, right = *max_element(lineVector.begin(), lineVector.end());
	long long answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		int lineNums = getNumLines(mid, lineVector);

		if (lineNums >= N) {
			// �ʿ� �������� �� ������ ���� �÷�����
			answer = mid;
			left = mid + 1;
		}
		else {
			// �� �ʿ���. ���� ���߱�
			right = mid - 1;
		}
	}

	cout << answer << '\n';
	return 0;
}

/*
* 1654 ���� �ڸ���
* K���� ����. ���� ������. (1~10000)
* N���� ���� ������ �������� ����� ����. (1 ~ 1,000,000)
* �̺�Ž������ �ּ� ����, �ִ���� mid������ Ž���ϱ�.
* �ִ� ���̴� ���� �ִ� ����. 
*/