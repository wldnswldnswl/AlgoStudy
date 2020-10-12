#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H, answer = 10000;
//사다리 정보 저장 배열(H값을 행, N값을 열로 가짐)
bool MAP[31][11];
//사다리 타고 내려가보는 함수
bool ladder() {
	//모든 번호 사다리 타봄
	for (int i = 1; i <= N; i++) {
		//번호의 현재 사다리 위치
		int cur = i;
		for (int j = 1; j <= H; j++) {
			//왼쪽에 가로선 있으면 왼쪽으로 이동
			if (MAP[j][cur - 1])
				cur--;
			//밑에 가로선 있으면 오른쪽으로 이동
			else if (MAP[j][cur])
				cur++;
		}
		//i번의 사다리 결과가 i번이 아닐시 false 리턴
		if (cur != i)
			return false;
	}
	//결과가 올바르면 true 리턴
	return true;
}
//가로선 추가할 수 있는 모든 경우를 다 따짐
void line(int idx, int cnt) {
	//추가할 가로선 수가 3보다 크면 리턴
	if (cnt >= 4)
		return;
	//사다리 탄 결과가 올바를 경우 답 갱신하고 리턴
	if (ladder()) {
		answer = min(answer, cnt);
		return;
	}
	//가로선 추가할 수 있는 경우 모두 확인
	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			//이미 가로선이 놓여져 있으면 continue
			if (MAP[i][j])
				continue;
			//가로선이 연속되는 경우 continue
			if (MAP[i][j - 1])
				continue;
			if (MAP[i][j + 1])
				continue;
			//가로선 추가
			MAP[i][j] = true;
			line(i, cnt + 1);
			//가로선 제거
			MAP[i][j] = false;
		}
	}
}

int main() {
	int a, b;

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		MAP[a][b] = true;
	}
	//1번째 가로선부터 가능한 경우 검사
	line(1, 0);
	//불가능한 경우에는 -1 출력
	if (answer == 10000)
		answer = -1;

	cout << answer;
}
