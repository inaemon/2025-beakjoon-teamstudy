#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Country {
	int id, gold, silver, bronze;
};

bool compare(const Country& a, const Country& b) {
	if (a.gold != b.gold) return a.gold > b.gold;
	if (a.silver != b.silver) return a.silver > b.silver;
	return a.bronze > b.bronze;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<Country> countries(N);

	for (int i = 0; i < N; i++) {
		cin >> countries[i].id >> countries[i].gold >> countries[i].silver >> countries[i].bronze;
	}

	sort(countries.begin(), countries.end(), compare);

	// �ʱⰪ
	int rank = 1;
	int prev_gold = countries[0].gold, prev_silver = countries[0].silver, prev_bronze = countries[0].bronze;

	for (int i = 0; i < N; i++) {
		// ���� ������ �޴� ������ �ٸ��� ���ο� ��� ����
		if (countries[i].gold != prev_gold || countries[i].silver != prev_silver || countries[i].bronze != prev_bronze) {
			rank = i + 1;
		}

		// ���� K�� ã���� ��� ���
		if (countries[i].id == K) {
			cout << rank;
			return 0;
		}


		// ���� �� ������Ʈ
		prev_gold = countries[i].gold;
		prev_silver = countries[i].silver;
		prev_bronze = countries[i].bronze;
	}
}

/*
* 8979 �ø���
* �ݸ޴� �� ���� / ������ ���޴� ���� / ���� ������ ���޴� ����
* �� ������ ��� ����. 
* ���� �� N(1~1000), �˰� ���� ���� K(1~N) 
* �޴� �� ������ 1,000,000 ����. 
* ����ü�� ���� �� ���� ���� ������ �ִ� ���� �����. �װɷ� ���� ����. 
* ���� ����� ���� ��� ����, �տ� ���� �������. �޶�. �׷��� ���� ��ġ��� �����. 
* 
* ���� ������ ������ �ִµ� �� ��� ��. => ����ü ���� ����ϱ�. 
* sort(countries.begin(), countries.end(), compare); boolean �� ��ȯ�ϴ� �Լ��� sort �ϱ�.
*/