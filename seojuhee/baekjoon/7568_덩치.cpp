#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 문제 링크: https://www.acmicpc.net/problem/7568
int main() {
	int N;
    // 사람의 몸무게와 키를 저장할 벡터
	vector<pair<int, int>> people;
    // 등수를 저장할 벡터
	vector<int> res;

	cin >> N;
	people.resize(N);
    // 가장 작은 등수는 1이므로 벡터값을 1로 초기화
	res.assign(N, 1);

	for (int i = 0; i < N; i++) {
        // 사람들의 몸무게와 키를 입력받음
		cin >> people[i].first >> people[i].second;
    }

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
            // 자신보다 몸무게와 키가 큰 사람이 있다면 등수를 1 증가시킴
			if (people[i].first < people[j].first && people[i].second < people[j].second) {
				res[i]++;
            }
		}
	}

	for (auto elem : res) {
		cout << elem << " ";
    }
}