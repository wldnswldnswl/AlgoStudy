#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int N, answer;
    // 수열과 최대합을 저장할 배열 
	vector<int> sequence, dp;

	cin >> N;
	sequence.assign(N, 0);
	dp.assign(N, 0);
    // 수열 입력받음
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}
    // 최대합 배열의 첫번째 원소와 정답 변수에 수열의 첫번째 원소 대입
	dp[0] = sequence[0];
	answer = sequence[0];

	for (int i = 1; i < N; i++) {
        // dp[i-1]과 sequence[i]를 더한값이 sequence[i]보다 작다면
        // 연속해서 더할 이유가 없음 => dp[i]에는 sequence[i]를 대입
		dp[i] = max(dp[i - 1] + sequence[i], sequence[i]);
        // 정답 변수 갱신
		answer = max(answer, dp[i]);
	}

	cout << answer;
}