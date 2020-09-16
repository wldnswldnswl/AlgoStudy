#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//톱니바퀴 방문 정보 저장하는 벡터
vector<bool> visited(5, false);

//톱니바퀴의 회전방향을 변경하는 함수
void change_dir(vector<vector<int>> wheel, int cur_num, vector<int> &wheel_dir) {
	//앞으로 방문할 톱니바퀴 정보 담은 큐
	queue<int> need_visit;
	//입력받은 톱니바퀴부터 방문
	need_visit.push(cur_num);
	//방문표시
	visited[cur_num] = true;

	while (!need_visit.empty()) {
		int node = need_visit.front();
		need_visit.pop();
		//4번 톱니바퀴는 뒤쪽을 확인할 수 없음
		if (node != 4) {
			//뒤쪽 톱니바퀴를 방문하지 않았다면
			if (!visited[node + 1]) {
				//현재 톱니바퀴와 뒤쪽 톱니바퀴의 맟닿아 있는 부분의 극이 다르다면
				if (wheel[node][2] != wheel[node + 1][6]) {
					//뒤쪽 톱니바퀴의 회전방향은 현재 톱니바퀴의 반대방향
					wheel_dir[node + 1] = -wheel_dir[node];
				}
				//뒤쪽 톱니바퀴 방문할것
				need_visit.push(node + 1);
				//방문표시
				visited[node + 1] = true;
			}
		}
		//1번 톱니바퀴는 앞쪽을 확인할 수 없음
		if (node != 1) {
			//앞쪽 톱니바퀴를 방문하지 않았다면
			if (!visited[node - 1]) {
				//현재 톱니바퀴와 앞쪽 톱니바퀴의 맟닿아 있는 부분의 극이 다르다면
				if (wheel[node - 1][2] != wheel[node][6]) {
					//앞쪽 톱니바퀴의 회전방향은 현재 톱니바퀴의 반대방향
					wheel_dir[node - 1] = -wheel_dir[node];
				}
				//앞쪽 톱니바퀴 방문할것
				need_visit.push(node - 1);
				//방문표시
				visited[node - 1] = true;
			}
		}
	}
}

//톱니바퀴의 값을 변경하는 함수
void change_wheel(vector<vector<int>> &wheel, vector<int> wheel_dir) {
	for (int i = 1; i < 5; i++) {
		//톱니바퀴가 시계방향으로 회전하면 뒤쪽 원소부터 스왑함
		if (wheel_dir[i] == 1) {
			for (int j = 7; j >= 1; j--)
				swap(wheel[i][j], wheel[i][j - 1]);
		}
		//톱니바퀴가 반시계방향으로 회전하면 앞쪽 원소부터 스왑함
		else if (wheel_dir[i] == -1) {
			for (int j = 0; j < 7; j++)
				swap(wheel[i][j], wheel[i][j + 1]);
		}
	}
}

int main() {
	int K, cur_num, cur_dir, answer = 0, temp = 1;
	//톱니바퀴들의 정보를 저장하는 벡터
	vector<vector<int>> wheel(5, vector<int>(8));
	//톱니바퀴의 회전정보를 저장하는 벡터
	vector<int> wheel_dir(5, 0);

	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &wheel[i][j]);
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> cur_num >> cur_dir;
		//입력받은 톱니바퀴의 회전정보 저장
		wheel_dir[cur_num] = cur_dir;
		change_dir(wheel, cur_num, wheel_dir);
		change_wheel(wheel, wheel_dir);
		//방문 정보 초기화
		visited.assign(5, false);
		//톱니바퀴 회정정보 초기화
		wheel_dir.assign(5, 0);
	}

	for (int i = 1; i < 5; i++) {
		//톱니바퀴의 12시방향이 S극이면 answer에 톱니바퀴 점수를 더함
		if (wheel[i][0] == 1)
			answer += temp;
		//톱니바퀴의 점수를 2씩 곱함 -> 1번: 1, 2번: 2, 3번: 4, 4번: 8
		temp *= 2;
	}

	cout << answer;
}
