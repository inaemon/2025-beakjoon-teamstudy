#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int n3;
    int n5 = n / 5;

    while (n5 >= 0) {
        int nn = n - n5 * 5;
        if (nn % 3 == 0) {
            cout << n5 + nn / 3;
            return 0;
        }
        n5--;
    }
    
    cout << -1;
    return 0;
}

/*
* �������
* n ų�α׷� ���.
* 3 / 5
* n�� �־����� �װ� ����Ͽ�
* ���� �ּ� ���� ��� (���� �� ������ -1)
* 5�� ���� ���� ���� �ɷ� 3 ���� 3���� �������� ���� ū 5kg ���� ã�ƾ� �� << �̰� Ű����Ʈ����
*/