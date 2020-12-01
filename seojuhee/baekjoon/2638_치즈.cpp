#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 100

int N, M, day = 0, cheeseCnt = 0;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };
// 외부 공기와 두면 이상 접촉한 치즈를 녹이는 함수
void cheeseMelt(int x, int y) {
	int zeroCnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dirX[i];
		int ny = y + dirY[i];
		if (MAP[nx][ny] == 0 && visited[nx][ny]) {
			zeroCnt++;
		}
	}
	if (zeroCnt >= 2) {
		MAP[x][y] = 0;
		cheeseCnt--;
	}
}
// 외부 공기를 표시하는 함수
void outsideAir(int x, int y) {
	queue<pair<int, int>> needVisit;
	needVisit.push({ x, y });
	while (!needVisit.empty()) {
		int curx = needVisit.front().first;
		int cury = needVisit.front().second;
		needVisit.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dirX[i];
			int ny = cury + dirY[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (MAP[nx][ny] != 0 || visited[nx][ny])
				continue;
			needVisit.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
            // 전체 치즈의 개수를 미리 세어놓음
			if (MAP[i][j] == 1) {
				cheeseCnt++;
			}
		}
	}
    // 치즈가 모두 녹을때까지 반복문 진행
	while (cheeseCnt > 0) {
		visited[0][0] = true;
		outsideAir(0, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP[i][j] == 1) {
					cheeseMelt(i, j);
				}
			}
		}
		day++;
		memset(visited, 0, sizeof(visited));
	}

	cout << day;
}