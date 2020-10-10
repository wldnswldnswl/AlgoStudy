#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000
#define MAX 101
using namespace std;

int n, m;
//도시는 1번부터 시작
int city[MAX][MAX];
//플로이드 와샬 함수
void floydWarshall() {
	//경유지
	for (int k = 1; k <= n; k++) {
		//출발지
		for (int i = 1; i <= n; i++) {
			//도착지
			for (int j = 1; j <= n; j++) {
				//출발지에서 경유지를 거쳐 도착하는 비용과 출발지에서 도착지까지의 비용 비교해서 작은값 대입
				city[i][j] = min(city[i][k] + city[k][j], city[i][j]);
			}
		}
	}
}

int main() {
	int x, y, z;

	cin >> n;
	cin >> m;

	//도시 비용 배열 최대값으로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//출발지 도착지 같으면 0으로 초기화
			if (i == j)
				city[i][j] = 0;
			//다른값들은 INF로 초기화
			else
				city[i][j] = INF;
		}
	}
	//비용 정보 저장
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		city[x][y] = min(city[x][y], z);
	}
	
	floydWarshall();

	//비용 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == INF)
				city[i][j] = 0;
			cout << city[i][j] << " ";
		}
		cout << '\n';
	}
}
