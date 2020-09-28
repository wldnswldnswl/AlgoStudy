#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	//물건의 무게를 저장할 벡터
	vector<int> w;
	//물건의 가치를 저장할 벡터
	vector<int> v;
	//물건들의 가치합의 최대값을 저장
	//i번째 인덱스까지 탐색했을 때 j만큼의 무게를 가져갔을때의 가치의 최대값 저장
	vector<vector<int>> dp;
	int N, K, x, y;

	cin >> N >> K;
	//w, v의 1번째 인덱스부터 사용할거라 크기는 n+1로 잡음
	w.assign(N + 1, 0);
	v.assign(N + 1, 0);

	for (int i = 0; i <= N; i++) {
		if (i != 0)
			cin >> w[i] >> v[i]; //물건의 무게, 가치 입력받음
		//K 무게까지 저장하기 때문에 각 행의 열의 크기는 K+1
		dp.push_back(vector<int>(K + 1, 0)); 
	}
		
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			//무게의 합(j)이 해당 물건의 무게보다 크거나 같으면
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i-1][j]);
				//해당 물건을 선택하는 것과 선택하지 않는 것 중 가치의 최대값 저장
				//j-w[i] => 해당 물건을 선택하게 되면 dp[i-1]에서 해당 물건의 
				//무게를 더하지 않은 무게의 최대값을 구해야함
			//무게의 합(j)이 해당 물건의 무게보다 작으면
			else
				dp[i][j] = dp[i - 1][j];
				// 해당 물건 선택하지 않음
		}
	}
	//물건들의 가치합의 최대한 출력
	cout << dp[N][K];
}
