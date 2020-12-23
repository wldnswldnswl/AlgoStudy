#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/1744
/* 처음에 구현했던 풀이방법
    1. 숫자를 입력받고 내림차순으로 정렬
    2. 배열을 0번째 원소부터 N-1번째까지 검사 (양수를 처리하는 과정)
    2-1. 현재 원소의 인덱스가 N-1이면 현재 원소 더하고 반복문 종료 
    2-2. 현재 원소가 0보다 작거나 같디면 해당 인덱스를 index에 저장해놓고 반복문 종료
    2-3. 다음 원소가 0보다 작거나 같다면 해당 인덱스 index에 저장하고 반복문 종료
    2-3-1. 만일 현재 인덱스가 짝수라면 현재 원소 더함
    2-4. 위 조건에 모두 해당하지 않으면 현재 원소와 다음 원소를 곱한 뒤 더하고 인덱스 1 증가시킴
    3. 마지막 원소부터 index까지 검사 (음수를 처리하는 과정)
    3-1. 현재 인덱스가 index라면 현재 원소 더함
    3-2. 위 조건에 해당하지 않을시 현재 원소와 이전 원소를 곱한 뒤 더하고 인덱스 1 감소시킴
    => 수열에 1이 존재할때는 다른 수와 곱하는게 아니라 따로 더해야 한다는 것을 간과함
    => 다른 분의 풀이를 보고 양수, 음수, 1을 다 다르게 묶는 방법을 선택 */
int main() {
	int N, num, answer = 0;
    // 양수 벡터와 음수 벡터의 크기를 저장할 변수
	int positiveSize, negativeSize;
    // 양수들을 저장할 벡터
	vector<int> positive;
    // 음수들을 저장할 벡터
	vector<int> negative;
    // 1들을 저장할 벡터
	vector<int> one;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
        // 입력값을 조건에 맞는 벡터에 저장
		if (num == 1)
			one.push_back(num);
		else if (num > 0)
			positive.push_back(num);
		else
			negative.push_back(num);
	}
    // 양수는 내림차순으로 정렬
	sort(positive.begin(), positive.end(), greater<int>());
    // 음수는 오름차순으로 정렬 
    // (음수끼리 곱할시에는 양수로 변환되므로 숫자가 작은걸 곱할수록 그 값이 더 커짐)
	sort(negative.begin(), negative.end());
    // 벡터의 크기들을 변수에 대입
	positiveSize = positive.size();
	negativeSize = negative.size();

	for (int i = 0; i < positiveSize; i++) {
        // 마지막 원소일때는 해당 원소 더함
		if (i == positiveSize - 1)
			answer += positive[i];
        // 마지막 원소가 아닐시에는 현재 원소와 다음 원소를 곱하여 더하고 i를 1 증가시킴
		else {
			answer += positive[i] * positive[i + 1];
			i++;
		}
	}

	for (int i = 0; i < negativeSize; i++) {
        // 마지막 원소일때는 해당 원소 더함
		if (i == negativeSize - 1)
			answer += negative[i];
        // 마지막 원소가 아닐시에는 현재 원소와 다음 원소를 곱하여 더하고 i를 1 증가시킴
		else {
			answer += negative[i] * negative[i + 1];
			i++;
		}
	}
    // one벡터의 크기를 더함
	answer += one.size();

	cout << answer;
}