#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define INF 300005

void Dijkstra(int start, vector<vector<pair<int, int>>> &graph, vector<int> &weight) {
	//탐색할 가중치, 정점 번호 저장 (가중치가 작은순으로 정렬하는 큐)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
	temp.push({ 0, start });
	//시작점의 최단경로는 0
	weight[start] = 0;

	while (!temp.empty()) {
		int w = temp.top().first;
		int v = temp.top().second;
		temp.pop();
		//탐색할 가중치가 탐색정점의 최단경로보다 클 경우 continue
		if (w > weight[v])
			continue;
		for (int i = 0; i < graph[v].size(); i++) {
			int next_v = graph[v][i].first;
			int next_w = w + graph[v][i].second;
			//최단경로를 발견했을 시 최단경로 갱신
			if (next_w < weight[next_v]) {
				weight[next_v] = next_w;
				//다음 탐색 가중치, 정점 저장
				temp.push({ next_w, next_v });
			}
		}
	}
}

int main() {
	int V, E, K;
	//그래프 연결 정보 저장
	vector<vector<pair<int, int>>> graph;
	//최단경로 저장 배열
	vector<int> weight;

	cin >> V >> E;
	cin >> K;
	graph.resize(V + 1);
	weight.assign(V + 1, INF);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		//그래프 정보 저장
		graph[u].push_back({ v, w });
	}

	Dijkstra(K, graph, weight);

	for (int i = 1; i < V + 1; i++) {
		//최단경로가 존재하지 않을경우 INF 출력
		if (weight[i] == INF)
			cout << "INF" << '\n';
		else
			cout << weight[i] << '\n';
	}
}
