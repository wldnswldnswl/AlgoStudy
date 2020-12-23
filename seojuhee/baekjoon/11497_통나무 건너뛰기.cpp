#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/11497

// 난이도를 계산하는 함수
int difficulty(vector<int> &arr) {
	int size = arr.size();
	int halfSize= size / 2;
	int index = 1, result = 0;
	// 최소난이도가 나오도록 정렬된 값을 저장할 벡터
	vector<int> temp(size);
	// 입력벡터를 내림차순으로 정렬
	sort(arr.begin(), arr.end(), greater<int>());
	// temp의 가운데에 arr의 가장 큰 원소를 대입
	temp[halfSize] = arr[0];
	// temp의 가운데를 기준으로 arr의 원소들을 양쪽에 배치한다.
	// arr의 원소가 작아질수록 가운데에서 점점 멀어진다.
	for (int i = 1; i < size; i++) {
		if (i % 2 != 0) {
			temp[halfSize + index] = arr[i];
		}
		else {
			temp[halfSize - index] = arr[i];
			index++;
		}
		// 만일 arr의 사이즈가 짝수이고 index가 halfSize가 같다면
		// 위의 halfSize + index는 temp의 인덱스를 벗어나므로 따로 처리해준다
		if (size % 2 == 0 && index == halfSize) {
			temp[0] = arr[size - 1];
			break;
		}
	}
	// 인접한 두 원소간의 차이의 최대값을 계산한다
	for (int i = 0; i < size; i++) {
		int compare;
		if (i == size - 1) {
			compare = abs(temp[i] - temp[0]);
		}
		else {
			compare = abs(temp[i+1] - temp[i]);
		}
		result = max(result, compare);
	}

	return result;
}

int main() {
	int T, N;
	// 반복횟수 입력받음
	cin >> T;

	while (T--) {
		vector<int> arr;
		cin >> N;
		arr.resize(N);

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		// 난이도 계산 결과 출력
		cout << difficulty(arr) << '\n';
	}
}