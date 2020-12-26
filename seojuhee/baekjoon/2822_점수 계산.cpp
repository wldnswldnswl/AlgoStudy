#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/2822
// 점수가 더 큰 순서대로 벡터를 정렬하기 위해 사용하는 비교함수
bool cmp(vector<int> a, vector<int> b) {
	return a[0] > b[0];
}

int main() {
    // 점수와 인덱스를 저장하는 이중벡터
	vector<vector<int>> score(8, vector<int>(2));
    // 상위 5개 점수의 인덱스를 저장할 벡터
	vector<int> scoreIndex;
    // 최종 점수를 저장할 변수
	int sum = 0;
	// 점수 입력받고 인덱스 저장
	for (int i = 0; i < 8; i++) {
		cin >> score[i][0];
		score[i][1] = i + 1;
	}
    // 점수 내림차순으로 정렬
	sort(score.begin(), score.end(), cmp);
    // 최종 점수 계산 및 상위 점수들 인덱스에 저장
	for (int i = 0; i < 5; i++) {
		sum += score[i][0];
		scoreIndex.push_back(score[i][1]);
	};

	cout << sum << '\n';
    // 인덱스 오름차순으로 정렬
	sort(scoreIndex.begin(), scoreIndex.end());
    // 인덱스 출력
	for (auto elem : scoreIndex) {
		cout << elem << " ";
	}
}