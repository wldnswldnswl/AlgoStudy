#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 502

int n, m, answer = 0;
int MAP[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool visited[MAX][MAX];

//dfs이용해 만들 수 있는 모양 다 검사 (ㅏ, ㅗ, ㅓ, ㅜ 제외)
void shape1(int x, int y, int cnt, int sum) {
	visited[x][y] = true;
	//정사각형 네개 검사하면 정답 변수 갱신하고 리턴
	if (cnt == 4) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (visited[nx][ny])
			continue;
		shape1(nx, ny, cnt + 1, sum + MAP[nx][ny]);
		visited[nx][ny] = false;
	}
}
//ㅏ, ㅗ, ㅓ, ㅜ 모양 검사
void shape2(int x, int y) {
	//x, y 좌표에 따라 만들 수 있는 모양만 검사
	if (x != n-1 && y != 0 && y != m-1)
		answer = max(answer, MAP[x][y] + MAP[x+dx[1]][y+dy[1]] + MAP[x+dx[2]][y+dy[2]] + MAP[x+dx[3]][y+dy[3]]);
	if (x != 0 && x != n-1 && y != m-1)
		answer = max(answer, MAP[x][y] + MAP[x+dx[0]][y+dy[0]] + MAP[x+dx[2]][y+dy[2]] + MAP[x+dx[3]][y+dy[3]]);
	if (x != 0 && y != 0 && y != m-1)
		answer = max(answer, MAP[x][y] + MAP[x+dx[0]][y+dy[0]] + MAP[x+dx[1]][y+dy[1]] + MAP[x+dx[3]][y+dy[3]]);
	if (x != 0 && x != n-1 && y != 0)
		answer = max(answer, MAP[x][y] + MAP[x+dx[0]][y+dy[0]] + MAP[x+dx[1]][y+dy[1]] + MAP[x+dx[2]][y+dy[2]]);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
	//모든 좌표를 시작점으로 모양 검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			shape1(i, j, 1, MAP[i][j]);
			//지도의 모서리가 시작점일 경우 ㅏ, ㅗ, ㅓ, ㅜ 모양 못만듬 -> continue
			if (i == 0) {
				if (j == 0 || j == m - 1) {
					continue;
				}
			}
			if (i == n - 1) {
				if (j == 0 || j == m - 1) {
					continue;
				}
			}
			shape2(i, j);
		}
	}

	cout << answer;
}
