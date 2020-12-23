#include <algorithm>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/14720
// 우유를 마시는 순서가 정해져 있으므로 순서에 맞게 먹어야 최대로 먹을 수 있음
int main() {
	int N, milk, answer = 0;
	// 마셔야할 우유의 종류를 저장할 변수 (0-딸기, 1-초코, 2-바나나)
	int index = 0; 

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> milk;
		// 가게에서 파는 우유와 마셔야 하는 우유가 일치할 경우
		if (milk == index) {
			// 바나나우유를 먹었을 경우에는 index를 -1로 바꿔 다음에 딸기우유를
			// 먹을 수 있도록 함
			if (index == 2) {
				index = -1;
			}
			// 다음에 먹을 우유를 저장
			index++;
			// 마신 우유 개수 증가
			answer++;
		}
	}
	cout << answer;
}