#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 문제 링크: https://www.acmicpc.net/problem/11052
int main() {
	int N;
    // 구매 금액 최대값과 카드 금액을 저장할 벡터
	vector<int> dp, card;
    
	cin >> N;
    // i번째 원소는 i개의 카드를 구매했다는 의미이므로 벡터의 크기는 N+1로 설정한다
	dp.resize(N + 1);
	card.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
            // n개의 카드를 사기 위한 방법은 다음과 같다.
            // 1. 1개의 카드가 들어간 카드팩과 n-1개의 카드를 산다.
            // 2. 2개의 카드가 들어간 카드팩과 n-2개의 카드를 산다.
            // n. n개의 카드가 들어간 카드팩을 산다.
            // => i개의 카드가 들어간 카드팩과 n-i개의 카드를 산다.
            // => dp[n-i] + card[i]
            // 반복문을 이용해 최대값을 갱신하여 i개의 카드를 사기위한 최대 금액을 구한다.
			dp[i] = max(dp[i - j] + card[j], dp[i]);
		}
	}
	
	cout << dp[N];
}