#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 300

int main() {
	int N;
	// 각 계단의 점수를 저장하는 배열
	long long stairs[MAX];
	// 각 계단의 최대점수를 저장하는 배열
	long long dp[MAX];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stairs[i];
	}
	// 계단이 1개밖에 없다면 최댓값은 첫번째 계단의 점수
	if (N == 1) {
		cout << stairs[0];
		return 0;
	}
	// dp배열의 0~2번째 원소는 값을 미리 지정
	dp[0] = stairs[0]; 
	dp[1] = dp[0] + stairs[1];
	// 마지막 계단은 반드시 밟아야 하므로 최대값에는 두번째 계단의 점수가 들어가야 한다.
	dp[2] = stairs[2] + max(dp[0], stairs[1]);

	for (int i = 3; i < N; i++) {
		/*계단을 오르는데는 총 2가지의 경우가 있다.
		  1. 이전 계단을 밟지 않는 경우
		  => 전전 계단의 최대값과 현재 계단의 점수를 더하면 된다
		  2. 이전 계단을 밟는 경우
		  => 전전전 계단의 최대값, 전 계단, 현재 계단의 점수를 더하면 된다
		  두 경우 중의 최대값을 배열에 저장한다*/
		dp[i] = max(dp[i - 2] + stairs[i], dp[i-3] + stairs[i] + stairs[i-1]);
	}

	cout << dp[N - 1];
	return 0;
}