#include <algorithm>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/14697
int main() {
	int room1, room2, room3, people, answer = 0;
    // 방의 정원과 인원수를 입력받음
	cin >> room1 >> room2 >> room3 >> people;
    // 반복문을 이용하여 각 방에 배정이 가능한 모든 경우의 수를 확인함
	for (int i = 0; i < (people / room1 + 1); i++) {
		for (int j = 0; j < (people / room2 + 1); j++) {
			for (int k = 0; k < (people / room3 + 1); k++) {
                // 빈 침대 없이 배정이 가능할 경우 정답변수에 1을 저장하고 반복문 종료
				if ((i*room1) + (j*room2) + (k*room3) == people) {
					answer = 1;
					goto printAnswer;
				}
			}
		}
	}

	printAnswer:
		cout << answer;
}