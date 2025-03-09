#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Player {
    int level;
    string nickname;
};

struct Room {
    int minLevel;
    int maxLevel;
    vector<Player> players;
    int capacity;
    bool isStarted() {
        return players.size() == capacity;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int p, m;
    cin >> p >> m;

    vector<Room> rooms;

    for (int i = 0; i < p; i++) {
        int l;
        string n;
        cin >> l >> n;

        bool matched = false;

        for (auto& room : rooms) {
            if (room.players.size() < room.capacity &&
                room.minLevel <= l && l <= room.maxLevel) {
                room.players.push_back({ l, n });
                matched = true;
                break;
            }
        }

        // �� �� ����
        if (!matched) {
            Room newRoom = { l - 10, l + 10, {}, m };
            newRoom.players.push_back({ l, n });
            rooms.push_back(newRoom);
        }
    }

    for (auto& room : rooms) {
        // �г��� ������ ����
        sort(room.players.begin(), room.players.end(), [](const Player& a, const Player& b) {
            return a.nickname < b.nickname;
            });

        // �� ���� ���
        if (room.isStarted()) {
            cout << "Started!\n";
        }
        else {
            cout << "Waiting!\n";
        }

        // ���� �÷��̾� ���� ���
        for (const auto& player : room.players) {
            cout << player.level << " " << player.nickname << "\n";
        }
    }

    return 0;
}


/*
* 20006�� ��ŷ�� ��⿭
* 
* �÷��̾� ������ �濡 ��ġ / �� �� ����. 
* �� ���� ����(��� ��/ ���� ���� ����)
* 
* �Է��� �÷��̾� �� p, ���� m
* �� �÷��̾� ���� ���� l�� �г��� n
* 
* ��Ī ������ �� ������ ���ο� ��.
* ���ͷ� ��� ����
* 
* ���� �Է� �޾� �⺻ �� ��ȸ�ϰ� ���� ������ ���� ã��. ���� ������ �� ������ ���ο� �� ����. �� ���� ���� ���¸� Started.
* 
* ����� �� ������� . �� �÷��̾� ����Ʈ�� �г��� ���� ���� �� ���¶� �÷��̾� ���� ���
* 
* auto&�� �����Ͽ� ���
*/