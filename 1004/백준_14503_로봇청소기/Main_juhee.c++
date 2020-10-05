#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 50
//지도정보
int map[MAX][MAX];
//방문정보
bool visited[MAX][MAX];
int N, M, answer = 0;
//로봇의 현재위치와 방향 저장
vector<int> robot(3);
//로봇의 방향에 따라 왼쪽으로 이동할때 이동하는 위치와 방향을 처리하기 위한 배열
int left_loc[4][3] = { {0,-1,3},{-1,0,0},{0,1,1},{1,0,2} };
//로봇의 방향에 따라 후진할 경우 위치를 처리하기 위한 배열
int back_loc[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };

void clean() {
	queue<vector<int>> need_visit;
	need_visit.push(robot);
	visited[robot[0]][robot[1]] = true;
	//0 북 1 동 2 남 3 서
	while (!need_visit.empty()) {
        //탐색할 로봇정보 저장
		vector<int> x = need_visit.front();
		need_visit.pop();
		answer++;
		for(int i=0; i<4; i++) {
            //로봇이 다음으로 청소할 위치를 임시변수에 저장
			int next_x = x[0] + left_loc[x[2]][0];
			int next_y = x[1] + left_loc[x[2]][1];
            //로봇의 방향은 계속 변함
			x[2] = left_loc[x[2]][2];
            //방문 가능하고 벽이 아니라면 다음에 탐색할 위치를 저장한다
			if (!visited[next_x][next_y] && map[next_x][next_y] == 0) {
				vector<int> temp = {next_x, next_y, x[2]};
				need_visit.push(temp);
				visited[next_x][next_y] = true;
				break;
			}
            //네 뱡향 모두 청소가 되어있거나 벽인 경우
			if (i == 3) {
                //청소기를 후진시킨다
				x[0] += back_loc[x[2]][0];
				x[1] += back_loc[x[2]][1];
                //후진할 수 없다면 반복문 종료
				if (map[x[0]][x[1]] == 1)
					break;
                //처음부터 다시 탐색
				i = -1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> robot[0] >> robot[1] >> robot[2];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	clean();

	cout << answer;
}