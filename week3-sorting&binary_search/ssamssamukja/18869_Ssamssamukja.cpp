#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> compress(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end()); // �ߺ� ����

    vector<int> compressed;
    for (int num : arr) {
        compressed.push_back(lower_bound(sortedArr.begin(), sortedArr.end(), num) - sortedArr.begin());
    }
    return compressed;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M, N;
    cin >> M >> N;

    unordered_map<string, int> universeCount;
    int result = 0;

    for (int i = 0; i < M; i++) {
        vector<int> planets(N);
        for (int j = 0; j < N; j++) {
            cin >> planets[j];
        }

        vector<int> compressedPlanets = compress(planets);

        string key;
        for (int num : compressedPlanets) {
            key += to_string(num) + ",";
        }

        result += universeCount[key];
        universeCount[key]++;
    }

    cout << result;
   
    return 0;
}

/*
* 18869 ��Ƽ���� 2
* M���� ����, 1 ~ N �༺
* �༺�� ũ�⸦ �˰� �־�. �յ��� ������ ���� �� ��? (������ ������ ������ �ٸ� ������ ���� �� ���� ����)
* ũ�� ������ ������ ���ָ� �յ��ϴٰ� �Ѵ�. 
* ���ϼ� �ְ� ���� ���Ͽ� ���� ���ָ� ã��. 
*/