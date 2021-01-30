// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/12982
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;
    // 신청금액을 오름차순으로 정렬
    sort(d.begin(), d.end());

    for (auto elem : d)
    {
        // 신청금액을 배정할 수 있는 예산이 남아있는 경우
        if (budget >= elem)
        {
            // 예산에서 현재 금액을 빼줌
            budget -= elem;
            // 예산이 배정된 부서 개수를 1 증가시킴
            answer++;
        }
        // 더 이상 예산이 없다면 반복문 종료
        else
        {
            break;
        }
    }

    return answer;
}