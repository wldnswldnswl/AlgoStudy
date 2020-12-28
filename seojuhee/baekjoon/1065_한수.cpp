#include <algorithm>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/1065
// 한수여부를 확인하는 함수
bool hansu(int num)
{
    // 이전 자릿수, 이전의 자릿수 간 차이, 반복문 횟수를 저장하는 변수
    int prevNum = 0, prevSub = 0, count = 0;

    while (num > 0)
    {
        // 현재 자릿수 저장
        int currentNum = num % 10;
        // 현재 자릿수와 이전 자릿수의 차이 저장
        int currentSub = currentNum - prevNum;
        // 세번째 자릿수를 확인하는데 현재 차이값과 이전 차이값이 같지 않다면 false 리턴
        if (count > 1 && prevSub != currentSub)
        {
            return false;
        }
        // 다음 자릿수 검사를 위해 num은 10으로 나눠줌
        num /= 10;
        // 현재 자릿수와 차이값은 prev변수들에 저장
        prevNum = currentNum;
        prevSub = currentSub;
        count++;
    }
    // num이 한수라면 true 반환
    return true;
}

int main()
{
    int N, answer = 0;
    // 숫자 입력받음
    cin >> N;
    // 입력 숫자가 한자릿수이거나 두자릿수라면 각 자릿수간 차이가 무조건 같으므로 입력값이 정답이 됨
    if (N / 10 < 10)
    {
        answer = N;
    }
    // 입력 숫자가 세자릿수 이상인 경우
    else
    {
        // 두자릿수까지의 개수를 더함
        answer += 99;
        // 모든 숫자들을 검사
        for (int i = 100; i <= N; i++)
        {
            // 해당 숫자가 한수라면 answer을 1 증가시킴
            if (hansu(i))
            {
                answer += 1;
            }
        }
    }
    // 정답 출력
    cout << answer;
}