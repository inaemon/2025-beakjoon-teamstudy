#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVPS(const string& vps) {
    stack<char> stk;

    for (char ch : vps) {
        if (ch == '(') { //���� ��ȣ
            stk.push(ch);
        }
        else if (ch == ')') { // �ݴ� ��ȣ
            if (stk.empty()) { // ����ִٸ� VPS �ƴ�
                return false;
            }
            stk.pop(); // ���ÿ��� ���� ��ȣ ����
        }
    }

    // ������ ��������� VPS, �ƴϸ� VPS�� �ƴ�
    return stk.empty();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

    while (T--) {
        string vps;
        cin >> vps;

        if (isVPS(vps)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n"
        }
    }

    return 0;
}


/* ( ) ���ڿ�
* �� ���� ��ȣ ��ȣ ���ڿ��� �⺻ VPS.
* x�� VPS => �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� (x) �� VPS
* VPS�� x�� y ���� ��Ų ���ο� ���ڿ� xy �� VPS
* �Է� ��ȣ ���ڿ��� VPS�̳� �ƴϳ� YES / NO �Ǻ��ϱ�
* 
* �Է� >> T���� �׽�Ʈ ������. �Է� ù �ٿ� �Է� ������ �� ��Ÿ���� ���� T �־���.
* 
* ù��° ���ڸ�ŭ �迭 ����. 
* ���� ���. �̷� ��ȣ ���ڿ��̸� ��κ� ���û�� ?? ¦ �̷�� pop ..
* 
* ( => ���� �߰�. 
* ) => pop���� ¦ ����. 
* 
* VPS���� Ȯ���ϴµ� ���� �̿��ؼ�.
* 
*/