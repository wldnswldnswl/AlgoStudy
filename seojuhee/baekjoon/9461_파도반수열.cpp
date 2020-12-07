#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 101
// 점화식을 이용해서 풀이
int main() {
	int T, N;
	int triangle[MAX] = { 0 };
	vector<int> answer;

	cin >> T;
    // 1, 2, 3번째 원소는 1로 초기화
	for (int i = 1; i <= 3; i++) {
		triangle[i] = 1;
	}

	for (int i = 0; i < T; i++) {
		cin >> N;
        // N번째 원소가 0일 경우에만 dp를 이용하여 값을 계산한다
        // N번째 원소가 0이 아니면 이미 정답이 구해진 것이므로 다시 계산할 필요가 없음
		if (triangle[N] == 0) {
			for (int j = 4; j <= N; j++) {
				triangle[j] = triangle[j - 2] + triangle[j - 3];
			}
		}
		answer.push_back(triangle[N]);
	}

	for (auto elem : answer) {
		cout << elem << '\n';
	}
}