#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 50
/*
 	체스판을 색칠하는 경우는 두가지로 나뉨
	1. 맨 왼쪽 위 칸이 흰색인 경우
	2. 맨 왼쪽 위 칸이 검은색인 경우
*/
int N, M;
// 체스판의 정보를 저장할 배열
char board[MAX][MAX];
// 색깔 정보를 저장하는 배열
char color[2] = { 'W', 'B' };
/*	다시 칠해야 하는 정사각형의 개수를 세는 함수
	1. flag가 0이면 맨 왼쪽 위 칸을 흰색으로 칠하는 경우
	2. flag가 1이면 맨 왼쪽 위 칸을 검은색으로 칠하는 경우
*/
int count_board(int x, int y, bool flag) {
	int cnt = 0;
	// 체스판의 현재 원소와 비교하기 위한 변수
	char current = color[flag];
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			// current와 체스판의 현재 원소가 다르다면
			if (current != board[i][j]) {
				// 체스판을 다시 칠해야 하는 경우이므로 cnt를 1 증가
				cnt++;
			}
			// 탐색위치가 마지막 열이 아닐 경우
			// (마지막 열과 첫번째 열의 원소는 문자가 같아야함)
			if (j != y + 7) {
				// 비교할 문자를 바꿈
				// W -> B, B -> W
				flag = !flag;
				current = color[flag];
			}
		}
	}
	return cnt;
}

int main() {
	// answer을 최대값으로 설정해놓음
	int answer = MAX * MAX, compare;
	// 체스판 크기 입력받음
	cin >> N >> M;
	// 체스판 정보 입력받음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	// 8*8크기가 가능한 경우만 확인
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			// 체스판을 칠할 수 있는 두가지 경우 중
			// 다시 칠해야 하는 사각형의 최소값을 compare변수에 저장
			compare = min(count_board(i, j, true), count_board(i, j, false));
			// answer에 최소값을 저장
			answer = min(answer, compare);
		}
	}

	cout << answer;
}