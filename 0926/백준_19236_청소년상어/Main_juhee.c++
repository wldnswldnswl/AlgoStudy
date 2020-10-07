#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

//물고기의 위치, 방향, 생존여부를 나타내는 구조체
struct FISH {
	int x, y, dir;
	bool dead;
};
//물고기의 번호를 저장하는 지도 배열
int MAP[4][4];
//물고기들의 정보를 저장
FISH fish[17];
//물고기 번호의 합을 저장
int answer;
//방향에 따른 이동을 위한 변수를 저장한 배열
int dir[9][2] = { {0,0}, {-1,0}, {-1,-1} ,{0,-1} ,{1,-1} ,{1,0} ,{1,1} ,{0,1} ,{-1,1} };

//지도 배열 복사하는 함수
void func_MAPCopy(int arr[4][4], int arr2[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
}
//물고기 정보 복사하는 함수
void func_fishCopy(FISH arr[17], FISH arr2[17]) {
	for (int i = 1; i < 17; i++) {
		arr2[i]= arr[i];
	}
}
//번호순으로 물고기 이동하는 과정 구현한 함수
void move_fish(int shark_x, int shark_y){
	for (int i = 1; i < 17; i++) {
		//해당 물고기가 죽었을 경우 continue
		if (fish[i].dead)
			continue;
		int x = fish[i].x;
		int y = fish[i].y;
		//해당 물고기 방향 미리 저장
		int dir_temp = fish[i].dir - 1;
		for (int j = 0; j < 8; j++) {
			dir_temp++;
			if (dir_temp == 9)
				dir_temp = 1;
			//다음 탐색위치 저장
			int next_x = x + dir[dir_temp][0];
			int next_y = y + dir[dir_temp][1];
			//이동하려는 곳에 상어가 있을 시 continue
			if (next_x == shark_x && next_y == shark_y)
				continue;
			//이동하려는 곳이 공간의 경계를 넘어설 경우 continue
			if (next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4)
				continue;
			//지도 정보와 물고기 정보 교환
			MAP[x][y] = MAP[next_x][next_y];
			fish[i].x = fish[MAP[next_x][next_y]].x;
			fish[i].y = fish[MAP[next_x][next_y]].y;
			fish[i].dir = dir_temp;
			fish[MAP[next_x][next_y]].x = x;
			fish[MAP[next_x][next_y]].y = y;
			MAP[next_x][next_y] = i;
			//물고기 서로 교환해서 이동할 시 바로 반복문 종료
			break;
		}
	}
}

void dfs(vector<int> shark, int sum) {
	//지도와 물고기정보 복사할 배열 선언
	int MAP_copy[4][4];
	FISH fish_copy[17];
	//상어에게 죽은 물고기의 번호 저장
	int die_fishNum = MAP[shark[0]][shark[1]];
	//합계 복사할 변수 선언
	int copy_sum;
	//상어에게 죽은 물고기의 dead 속성 변경
	fish[die_fishNum].dead = true;
	//죽은 물고기 번호 더함
	sum += die_fishNum;

	//물고기들 이동
	move_fish(shark[0], shark[1]);
	//지도와 물고기 배열, 합계 변수 복사
	func_MAPCopy(MAP, MAP_copy);
	func_fishCopy(fish, fish_copy);
	copy_sum = sum;
	
	for (int i = 1; i <= 3; i++) {
		//상어 이동
		int next_x = shark[0] + dir[shark[2]][0] * i;
		int next_y = shark[1] + dir[shark[2]][1] * i;

		//상어가 공간의 경계를 벗어나면 정답 갱신한 후 리턴
		if (next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4) {
			answer = max(answer, sum);
			return;
		}

		//상어가 이동하려는 곳의 물고기가 죽었다면 continue;
		if (fish[MAP[next_x][next_y]].dead)
			continue;
		//재귀
		dfs({ next_x, next_y, fish[MAP[next_x][next_y]].dir }, sum);
		//재귀 종료됐다면 이전 배열들과 변수 복사
		func_MAPCopy(MAP_copy, MAP);
		func_fishCopy(fish_copy, fish);
		sum = copy_sum;
	}
}

int main() {
	int num, direction;
	//지도와 물고기 정보 입력받음
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num >> direction;
			MAP[i][j] = num;
			fish[num].x = i;
			fish[num].y = j;
			fish[num].dir = direction;
			fish[num].dead = false;
		}
	}

	dfs({0, 0, fish[MAP[0][0]].dir }, 0);

	cout << answer;
}
