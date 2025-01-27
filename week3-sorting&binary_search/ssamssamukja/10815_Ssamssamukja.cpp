#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;

	cin >> N;

	vector<int> Nvector(N);
	for (int i = 0;i < N;i++) {
		cin >> Nvector[i];
	}

	// ���� Ž���� ���� �����ϱ�
	sort(Nvector.begin(), Nvector.end());

	cin >> M;
	vector<int> Mvector(M);

	for (int i = 0;i < M;i++) {
		cin >> Mvector[i];
	}

	// M�迭�� N�迭 ��ġ ���� �� �� �� 
	for (int i = 0;i < M;i++) {
		cout << binary_search(Nvector.begin(), Nvector.end(), Mvector[i]) << " ";
	}
	
	return 0;
}

/*
* 10815 ����ī��
* ����ī�� N�� ������ ����. 
* ���� M�� �־����� �� ����̰� ������ �ִ��� �ƴ��� ���ϱ�
* ù° �� N : ���� ī�� ���� �־�����(1 ~ 500,000)
* ��° �� ����ī�� �����ִ� ���� �־����� (-10,000,000 ~ 10,000,000)
* ��° �� M ���� �־���. 
* ��° �� : ���� ī������ �ƴ��� ���ؾ� �� M�� ���� �־���. �������� ���е�. (1~500000)
* ������ ������ 1, ������ 0
* 
* ����Ž�� �Ǵ� unordered_set�� ���� ȿ������ �˻� ����.
* vector<int> Nvector(N); ������ ũ�⸦ �� �� �ִٸ� �̸� �������ֱ�
* ó���� Answer vector �ϳ� ������ַ��� ������ �װ� ��ȿ����. �ٷ� ����ϴ� �ڵ�� ������.
*/