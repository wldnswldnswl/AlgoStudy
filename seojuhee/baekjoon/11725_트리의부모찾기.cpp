#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/11725
int N;
// 노드간의 연결관계를 저장할 벡터
vector<vector<int>> node;
// 방문지점을 표시할 벡터
vector<int> visited;
// 각 노드의 부모노드를 저장할 벡터
vector<int> parentNode;

void bfs(int start) {
	queue<int> needVisit;
    // 방문할 지점 큐에 넣고 방문 표시
	needVisit.push(start);
	visited[start] = 1;

	while (!needVisit.empty()) {
		int x = needVisit.front();
		needVisit.pop();
        // 현재 방문지점과 연결된 정점들 모두 탐색
		for (int i = 0; i < node[x].size(); i++) {
			int childNode = node[x][i];
            // 방문하지 않은 자식노드일 경우
			if (visited[childNode] == 0) {
                // 방문표시하고 해당 노드의 부모노드를 저장
				visited[childNode] = 1;
				parentNode[childNode] = x;
                // 큐에 해당 노드 넣음
				needVisit.push(childNode);
			}
		}
	}
}

int main() {
	int x, y;

	cin >> N;
    // 노드는 1번부터 시작하기 때문에 벡터들의 크기를 N+1로 설정
	node.resize(N + 1);
	parentNode.resize(N + 1);
	visited.assign(N + 1, 0);

    // 입력받음
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
    // 너비우선탐색 실시
	bfs(1);
    //결과값 출력
	for (int i = 2; i < parentNode.size(); i++) {
		cout << parentNode[i] << '\n';
	}
}