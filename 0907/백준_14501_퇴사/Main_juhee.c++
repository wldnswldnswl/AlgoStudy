#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;
//dfs를 통해 상담의 최대 이익을 구함
void dfs(vector<pair<int, int>> consult, int start, int cost) {
	cost += consult[start].second;

	for (int i = start + consult[start].first; i < consult.size(); i++) {
        //상담이 퇴사전에 끝난다면 dfs함수 호출
		if (i + consult[i].first <= consult.size()) 
			dfs(consult, i, cost);
	}
	//더 이상 할 수 있는 상담이 없으면 최대 이익을 정답 변수에 넣어줌
	answer = max(answer, cost);
}

int main() {
	int N;
    //상담에 대한 정보를 저장하는 벡터
	vector<pair<int, int>> consult;
	cin >> N;
	consult.resize(N+1);

	for (int i = 1; i < N+1; i++) {
        //상담에 걸리는 시간과 비용을 입력받음
		cin >> consult[i].first >> consult[i].second;
    }

	for (int i = 1; i < N + 1; i++) {
        //상담이 퇴사전에 끝난다면 dfs함수 호출
		if(i + consult[i].first <= consult.size()) {
			dfs(consult, i, 0);
        }
	}

	cout << answer;

}