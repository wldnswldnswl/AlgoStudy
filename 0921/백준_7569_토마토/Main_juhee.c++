#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
//토마토 정보 담을 배열 => 0으로 초기화 되어있음
int tomato[MAX][MAX][MAX];
//방문 정보 담을 배열 => 0으로 초기화 되어있음
int visited[MAX][MAX][MAX];
//상, 하, 좌, 우, 위층, 아래층 이동하기 위한 값 저장한 배열
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	int answer = 0; 
	int M, N, H;
	
	//방문할 지점을 담을 큐
	queue<pair<pair<int, int>,int>> need_visit;
	
	cin >> M >> N >> H;
	for (int z = 0; z < H; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> tomato[z][x][y];
				//토마토가 안익었을 경우 visited에 -1을 저장
				if (tomato[z][x][y] == 0)
					visited[z][x][y] = -1;
				//토마토가 익었을 경우 방문큐에 해당 지점 넣음
				if (tomato[z][x][y] == 1)
					need_visit.push({ {x, y},z });
			}
		}
	}

	while (!need_visit.empty()) {
		int x = need_visit.front().first.first;//방문 지점 x좌표
		int y = need_visit.front().first.second;//방문 지점 y좌표
		int z = need_visit.front().second;//방문 지점 z좌표
		need_visit.pop();//방문할 큐에서 해당 지점 제거

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			//특정 범위 벗어나면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
				continue;
			//검사 지점에 있는 토마토가 방문한 거라면 continue
			if (visited[nz][nx][ny] >=  0)
				continue;
			//올바른 검사 지점이면 현재 지점의 visited값 + 1 을 저장
			visited[nz][nx][ny] = visited[z][x][y] + 1;
			//방문할 지점 push
			need_visit.push({ {nx, ny}, nz });
		}
	}

	for (int z = 0; z < H; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				//토마토가 안익은 지점이 있다면 -1을 출력하고 종료
				if (visited[z][x][y] == -1) {
					cout << "-1";
					return 0;
				}
				//answer 갱신
				answer = max(answer, visited[z][x][y]);
			}
		}
	}

	cout << answer;
}