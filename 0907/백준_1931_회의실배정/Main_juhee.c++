#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    //meeting의 뒤의 원소의 끝나는 시간이 앞의 원소보다 크다면 true 리턴 
	if (a.second < b.second)
		return true;
    //반대일시 false 리턴
	else
		return false;
}

int main() {
	int N, start,end, answer = 0;
    //회의 시작시간과 끝나는시간 입력받을 배열 생성
    //pair사용하는건 이중벡터와 비슷함. => meeting[N][2]와 같음 / 벡터는 배열과 비슷
	vector<pair<int, int>> meeting;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}
    //회의 끝나는시간을 기준으로 오름차순으로 정렬
	sort(meeting.begin(), meeting.end(), cmp);
	end = 0;
    //meeting배열의 모든값을 검사
    //for(int i=0; i<meeting.size(); i++) if(meeting[i].first >= end)라고 하는것과 같음
	for (auto elem : meeting) {
        //meeting[i]의 시작시간이 이전 회의의 끝나는 시간보다 크거나 같다면
		if (elem.first >= end) {
            //회의개수 1 증가
			answer++;
            //end에 현재 meeting[i]의 끝나는시간을 대입함
			end = elem.second;
		}
	}

	cout << answer;

}
