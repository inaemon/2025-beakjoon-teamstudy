#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N; 

        vector<pair<int, int>> applicants(N);
        for (int i = 0; i < N; i++) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        sort(applicants.begin(), applicants.end());

        int count = 1; 
        int minInterviewRank = applicants[0].second; 

        for (int i = 1; i < N; i++) {
            if (applicants[i].second < minInterviewRank) {
                count++;
                minInterviewRank = applicants[i].second;
            }
        }

        cout << count << "\n";
    }

    return 0;
}


/*
* 1946 ���� ���
* ������ ���� �� �� �ϳ��� �ٸ� �����ں��� �������� �ʴ� �ڸ� �����Ѵ�. 
* 
* �׽�Ʈ ���̽� T(1<=T<=20)�� �� �׽�Ʈ ���̽����� ������ �� N�� �Է� �ް�
* �����ڵ��� ���� �ɻ� ������ ���� ������ ����
* �ִ� �ο����� �� �ٿ� �ϳ��� ���
*/