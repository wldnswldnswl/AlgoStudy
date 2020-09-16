#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 10000

int main() {
	int N, M, answer = MAX;
	//도시 정보 담을 벡터
	vector<vector<int>> city;
	//집의 위치정보를 저장할 벡터
	vector<pair<int, int>> home;
	//치킨집의 위치정보를 저장할 벡터
	vector<pair<int, int>> chicken;
	//조합 처리를 위한 벡터
	vector<int> comb;
	

	cin >> N >> M;
	city.assign(N + 1, vector<int>(N+1));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> city[i][j];
			//집의 위치가 입력될 시 home벡터에 위치정보 저장
			if (city[i][j] == 1)
				home.push_back(make_pair(i, j));
			//치킨집의 위치가 입력될 시 chicken벡터에 위치정보 저장
			else if(city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	//comb벡터의 사이즈는 치킨집 개수로 지정
	comb.assign(chicken.size(), 0);

	//폐업하지 않을 치킨집 개수만큼 comb벡터에 1을 저장
	for (int i = 0; i < M; i++)
		comb[i] = 1;

	//조합 처리를 위해 정렬
	sort(comb.begin(), comb.end());
	
	/*comb벡터에 {1 1 0 0 0} 이런식으로 값이 저장되어 있다 가정
	밑의 조합 반복문을 사용하게 되면 반복문이 실시될 때마다
	{1 0 1 0 0} {1 0 0 1 0} 이런식으로 폐업하지 않는 치킨집의 조합을
	여러개 만듬 이를 이용해서 치킨거리를 계산*/
	do {
		//치킨거리의 합을 저장할 임시 변수
		int answer_temp = 0;
		//각 집에서 폐업하지 않는 치킨집까지의 거리를 모두 계산해 가장 작은값을 임시 변수에 더한다
		for (int i = 0; i < home.size(); i++) {
			//각 집마다의 치킨거리를 저장할 변수
			int temp_cmp = MAX;
			for (int j = 0; j < comb.size(); j++) {
				if (comb[j] == 1) {
					//abs는 절댓값을 계산해주는 함수
					int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
					//temp_cmp에 치킨거리의 값을 저장할 수 있도록 갱신
					if (temp_cmp > dist)
						temp_cmp = dist;
				}
			}
			//치킨거리의 임시 합을 구함
			answer_temp += temp_cmp;
		}
		//임시 합이 원래 합보다 작다면 원래 합에 임시 합을 대입
		if (answer > answer_temp)
			answer = answer_temp;
	}while(next_permutation(comb.begin(), comb.end()));
	
	cout << answer;

}
