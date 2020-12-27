#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/1158
int main() {
	int N, K, num;
    // 순열을 저장할 큐
	queue<int> josephus;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		josephus.push(i);
	}

	cout << "<";

	while (1) {
        // K번째의 원소를 출력해야 하기 때문에 K-1번째까지의 원소들은
        // 뒤쪽에 추가한 후에 제거한다.
		for (int i = 0; i < K - 1; i++) {
			josephus.push(josephus.front());
			josephus.pop();
		}
        // K번째 원소를 num에 저장
		num = josephus.front();
        // 해당 원소도 큐에서 제거한다
		josephus.pop();
        // 마지막 원소일 경우 출력하고 반복문 종료
		if (josephus.empty()) {
			cout << num << ">";
			break;
		}
        // 원소 출력
		cout << num << ", ";
	}
}