#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 11

int loc[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
int N, M, K;
//추가되는 양분 배열
int insert_food[MAX][MAX];
//땅의 양분 정보를 담은 배열
int food[MAX][MAX];
//나무 정보 배열
vector<int> tree[MAX][MAX];

void change_tree() {
	//봄&여름
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0)
				continue;
			//죽은 나무를 양분으로 저장할 변수
			int die_food = 0;
			//어린 나무순대로 정렬
			sort(tree[i][j].begin(), tree[i][j].end());
			//봄
			for (int k = 0; k < tree[i][j].size(); k++) {
				//남은 양분이 나무 나이보다 적을 시
				if (tree[i][j][k] > food[i][j]) {
					//양분 변수에 (죽은 나무 나이 / 2) 더함
					die_food += tree[i][j][k] / 2;
					//나무배열에서 해당 나무 삭제
					tree[i][j].erase(tree[i][j].begin() + k);
					k--;
				}
				//남은 양분이 나무 나이보다 크거나 같을 시
				else {
					//나무 나이만큼 양분 감소
					food[i][j] -= tree[i][j][k];
					//나무나이증가
					tree[i][j][k]++;
				}
			}
			//여름
			//땅에 죽은나무 양분 더함
			food[i][j] += die_food;
		}
	}

	//가을
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0)
				continue;
			for (int k = 0; k < tree[i][j].size(); k++) {
				//나무나이가 5의배수 일때
				if (tree[i][j][k] % 5 == 0) {
					for (auto elem : loc) {
						//나무 번식되는 위치 담은 변수
						int x = i + elem[0];
						int y = j + elem[1];
						//위치가 땅을 벗어날 시 continue
						if (x < 1 || x > N || y < 1 || y > N)
							continue;
						//해당 위치에 나이가 1인 나무 저장
						tree[x][y].push_back(1);
					}
				}
			}
		}
	}

	//겨울
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//땅에 양분 추가
			food[i][j] += insert_food[i][j];
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> insert_food[i][j];
			//모든 땅의 양분 5로 초기화
			food[i][j] = 5;
		}

	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		//나무 정보 저장
		tree[x][y].push_back(c);
	}

	for (int i = 0; i < K; i++)
		change_tree();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//나무 개수 더함
			answer += tree[i][j].size();
		}
	}

	cout << answer;
}