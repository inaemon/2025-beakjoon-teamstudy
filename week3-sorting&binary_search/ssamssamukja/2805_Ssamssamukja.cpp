#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long getWoodLength(vector<int>& woodVector, int height) {
	long long total = 0;
	for (int wood : woodVector) {
		if (wood > height) {
			total += (wood - height);
		}
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long long M;
	cin >> N;
	cin >> M;

	vector<int> woodVector(N);
	for (int i = 0;i < N;i++) {
		cin >> woodVector[i];
	}

	int left = 0, right = *max_element(woodVector.begin(), woodVector.end());
	int H = 0;
	

	while (left <= right) {
		int mid = (left + right) / 2;
		long long woodLength = getWoodLength(woodVector, mid);

		if (woodLength >= M) {
			// �ʿ� ���̺��� �� ������ ���� �÷�����
			H = mid;
			left = mid + 1;
		}
		else {
			// �� �ʿ���. ���� ���߱�
			right = mid - 1;
		}
	}
	

	cout << H;
	return 0;
}

/*
* 2805 ���� �ڸ��� 
* ���� M���� �ʿ���. 
* ���ܱ⿡ ���� H �����ϱ�. 
* H���� ���� ũ�� �߸��� ������ ���߸�. 
* ���ܱ⿡ ������ �� �ִ� ������ �ִ� ���ϱ�. 
* ���̴� 1,000,000,000 ���� �۰ų� ���� ���� ���� �Ǵ� 0. 
* ù° �ٿ� �����Ǽ� N, ���������� ���� ���� M
* ���� �ִ� ����ϱ�. 
* ���� ���� ������ ���� ���̺��� üũ�ϰ� �� �ʿ��ϴٸ� �Ʒ��� �������� �ʿ� ���ٸ� H �ö󰡱�. 
* => �� ����� H�� ���� ���� �� ���� �����ؼ� ����/���Ұ� ��ȿ�����̾ O(N^2)�� ���� ���. 
* ����Ž�� ����ϱ�. => O(N log MaxHeight)
* left�� right�� ���
* 
* �ִ� ã�� ��, sort�ϰ� �� ������ ���� �� �������� ��� ���� max_element�� �� ����. O(N log N) vs O(N) ��. 
*/