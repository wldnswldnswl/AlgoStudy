#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 21

//택시와 가장 가까운 승객 구하기 위한 함수 (우선순위큐 비교함수는 리턴값을 반대로 짜야됨)
struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		if (a[0] < b[0])
			return false;
		//택시와의 거리가 같을 경우 행과 열을 비교함
		else if (a[0] == b[0]) {
			if (a[1] < b[1])
				return false;
			else if (a[1] == b[1])
				return a[2] >= b[2];
			else
				return true;
		}
		else
			return true;
	}
};

// 택시 연료, 탐색할 승객의 인덱스를 저장하는 변수
int N, M, taxi_fuel, cust_idx;
//승객위치에서 택시까지의 거리 저장 (거리, 승객_x, 승객_y, 승객번호)
priority_queue<vector<int>, vector<vector<int>>, cmp> dist;
//승객 출발지, 목적지 저장 (출_x, 출_y, 목_x, 목_y)
vector<vector<int>> cust_info;
//지도 정보
int MAP[MAX][MAX]; 
//방문 정보
int visited[MAX][MAX]; 
//지도 탐색할때 출발지점, 목적지점 저장 배열
int start[2], End[2];
//지도내에서 상하좌우로 이동하기 위한 변수
int loc[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

//승객과 택시들 간 거리 계산 or 승객 태우고 목적지 이동한 거리 계산
// => flag가 true이면 승객-택시 계산, false이면 승객태워서 목적지 이동
bool calc_dist(bool flag, int index) {
	//이동할 지점 저장 (초기에는 각 승객의 출발지 저장)
	queue<pair<int, int>> need_visit;
	need_visit.push({ start[0], start[1] });

	while (!need_visit.empty()) {
		int x = need_visit.front().first;
		int y = need_visit.front().second;
		need_visit.pop();

		//이동 중에 연료가 떨어질 경우 false 반환
		if (taxi_fuel < visited[x][y])
			return false;
		//목적지에 도착했을 경우
		if (x == End[0] && y == End[1]) {
			//승객과 택시 간의 거리를 계산하는 경우
			if (flag) {
				//dist에 거리, 출발지점, 인덱스를 저장
				dist.push({ visited[x][y], start[0], start[1], index });
				return true;
			}
			//승객 태우고 목적지 이동했을때 거리 계산하는 경우
			else {
				//연료에 이동한 거리 더함(-이동거리 + 이동거리*2 => +이동거리)
				taxi_fuel += visited[x][y];
				return true;
			}
		}
		//현재지점에서 상하좌우로 이동하며 목적지점 찾기
		for (int i = 0; i < 4; i++) {
			int n_x = x + loc[i][0];
			int n_y = y + loc[i][1];
			if (n_x < 1 || n_x > N || n_y < 1 || n_y > N)
				continue;
			if (MAP[n_x][n_y] == 1 || visited[n_x][n_y] != -1)
				continue;
			//탐색가능한 지점일 경우 이전지점의 visited값의 1을 더함
			visited[n_x][n_y] = visited[x][y] + 1;
			//다음 탐색 지점 저장
			need_visit.push({ n_x, n_y });
		}
	}
	//목적지에 도달할 수 없는 경우 false 반환
	return false;
}

void reset_visited() {
	//visited배열 -1로 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = -1;
		}
	}
	//시작지점은 0으로 변경
	visited[start[0]][start[1]] = 0;
}

int main() {
	bool flag;

	cin >> N >> M >> taxi_fuel;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	//택시의 현재위치를 도착지점으로 저장
	cin >> End[0] >> End[1];

	for (int i = 0; i < M; i++) {
		int s_x, s_y, e_x, e_y;
		cin >> s_x >> s_y >> e_x >> e_y;
		//승객정보 벡터에 출발지점 x,y좌표와 도착지점 x,y좌표 삽입
		cust_info.push_back({ s_x, s_y, e_x, e_y });
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < cust_info.size(); j++) {
			//각 승객의 출발지점을 출발지로 설정
			start[0] = cust_info[j][0];
			start[1] = cust_info[j][1];
			//visited배열 초기화, 시작점만 0으로 표시
			reset_visited();
			//승객과 택시까지의 최단 거리 계산
			flag = calc_dist(true, j);
		}
		//택시를 탈 수 있는 승객이 없으면 반복문 종료
		if (dist.empty()) {
			taxi_fuel = -1;
			break;
		}
		//이동거리만큼 택시 연료에서 뺌
		taxi_fuel -= dist.top().front();

		for (int i = 0; i < 2; i++) {
			//탐색 승객의 출발지와 목적지를 각 변수에 넣음
			start[i] = cust_info[dist.top().back()][i];
			End[i] = cust_info[dist.top().back()][i + 2];
		}
		//해당 승객은 승객정보에서 지움
		cust_info.erase(cust_info.begin() + dist.top().back());
		//이동정보 초기화
		while (!dist.empty())
			dist.pop();
		//visited배열 초기화
		reset_visited();
		//승객 출발지에서 목적지까지 이동
		flag = calc_dist(false, 0);
		//목적지에 도달하지 못하면 반복문 종료
		if (!flag) {
			taxi_fuel = -1;
			break;
		}
	}

	cout << taxi_fuel;
}
