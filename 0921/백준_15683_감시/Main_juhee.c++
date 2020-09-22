#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> cctv;
vector<vector<int>> map;
int N, M;
//cctv 방향 전환을 위한 배열(각 cctv별 가능한 경우의수 저장)
int dir[6] = { 0, 4, 2, 4, 4, 1 };
int answer = 64;

//벡터 복사하는 함수
void copy(vector<vector<int>> arr, vector<vector<int>> &arr2) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
}

//사무실 정보 변경하는 함수
void change_map(vector<int> cctv_info, int dir) {
	int x = cctv_info[0];
	int y = cctv_info[1];
	int temp = dir % 4;

	//서쪽 방향
	if (temp == 0) {
		for (int i = y - 1; i >= 0; i--) {
			//해당 지점이 비어있을때 7로 변경
			if (map[x][i] == 0) 
				map[x][i] = 7;
			//해당 지점이 벽이면 반복문 종료
			else if (map[x][i] == 6) 
				break;
		}
	}
	//북쪽 방향
	else if (temp == 1) {
		for (int i = x - 1; i >= 0; i--) {
			if (map[i][y] == 0) 
				map[i][y] = 7;
			else if (map[i][y] == 6)
				break;
		}
	}
	//동쪽 방향
	else if (temp == 2) {
		for (int i = y + 1; i < M; i++) {
			if (map[x][i] == 0) 
				map[x][i] = 7;
			else if (map[x][i] == 6)
				break;
		}
	}
	//남쪽 방향
	else {
		for (int i = x + 1; i < N; i++) {
			if (map[i][y] == 0) 
				map[i][y] = 7;
			else if (map[i][y] == 6)
				break;
		}
	}
}

void dfs(int index) {
	//임시로 사무실 정보를 복사할 벡터
	vector<vector<int>> map_copy;
	map_copy.resize(N, vector<int>(M));
	//cctv확인이 끝나면
	if (index == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					cnt++;
			}
		}
		//사각지대 최소값 갱신
		answer = min(answer, cnt);

		return;
	}
	//확인할 cctv 번호
	int cctv_num = cctv[index][2];
	
	for (int i = 1; i <= dir[cctv_num]; i++) {
		//임시로 map_copy에 map 복사해놓음
		copy(map, map_copy);
		//cctv 번호에 따라 각 방향 검사
		if (cctv_num == 1) {
			change_map(cctv[index], i);
		}
		else if (cctv_num == 2) {
			change_map(cctv[index], i);
			change_map(cctv[index], i + 2);
		}
		else if (cctv_num == 3) {
			change_map(cctv[index], i);
			change_map(cctv[index], i + 1);
		}
		else if (cctv_num == 4) {
			change_map(cctv[index], i);
			change_map(cctv[index], i + 1);
			change_map(cctv[index], i + 2);
		}
		else {
			change_map(cctv[index], i);
			change_map(cctv[index], i + 1);
			change_map(cctv[index], i + 2);
			change_map(cctv[index], i + 3);
		}
		//다음 cctv 검사
		dfs(index + 1);	
		//재귀가 종료됐다면 이전 map정보를 가져와야하기 때문에 map에 map_copy 복사
		copy(map_copy, map);
	}
}

int main() {

	cin >> N >> M;

	map.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			//cctv 위치와 정보를 cctv벡터에 저장
			if (map[i][j] >= 1 && map[i][j] <= 5) 
				cctv.push_back({ i,j,map[i][j] });
		}
	}
	//dfs 호출
	dfs(0);

	cout << answer;
}
