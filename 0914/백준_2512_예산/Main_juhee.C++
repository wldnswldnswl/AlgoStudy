#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//내림차순 정렬
bool cmp(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}

int main() {
	int N, total_budget, sum, idx, answer = 0;
	vector<int> budget;
	cin >> N;
	budget.resize(N);

	for (int i = 0; i < N; i++)
		cin >> budget[i];

	cin >> total_budget;
    //예산요청 값들을 내림차순으로 정렬한다
	sort(budget.begin(), budget.end(), cmp);
    //상한액을 계산해야 하는 지점을 찾는다.
	for (idx = 0; idx < N; idx++) {
		sum = budget[idx] * (idx+1); //해당 인덱스의 값보다 크거나 같은 원소들을 더한다.
		for (int j = idx + 1; j < N; j++)
			sum += budget[j]; //budget[idx]보다 작은 값들도 마저 더한다.
		//합계 변수가 총 예산액보다 적을때가 상한액을 계산해야 하는 지점이다.
		if (sum < total_budget) {
			if (idx == 0) 
				answer = budget[idx]; //모든 예산요청값의 합이 총예산보다 작다면 상한액은 첫번째 원소의 값이다.
			//합계 변수에는 해당인덱스와 같거나 작은 원소들의 합만 남긴다.
			sum -= budget[idx] * idx;
			break;
		}
		//상한액 계산 지점이 마지막 인덱스라면 합계 변수에 마지막 원소를 대입한다.
		if (idx == N - 1 && sum < total_budget)
			sum = budget[idx];
	}
	//상한액 계산 지점을 찾을 수 없다면 어차피 모든 지방에 동일한 금액의 예산이 배정될 것이다.
	if (sum > total_budget)
		answer = total_budget / N;

	if (answer == 0) {
		//상한액 계산하는 시점의 budget[idx]보다 예산을 많이 요청한 지방들은 같은 상한액을 배정받을 것이다.
		answer = (total_budget - sum) / idx;
	}

	cout << answer;
		
}
