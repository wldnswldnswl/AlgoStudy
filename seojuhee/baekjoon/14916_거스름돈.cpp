#include <algorithm>
#include <iostream>
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/14916
// 2원과 5원 조합으로 거스름돈을 줄 수 없는 경우에 사용하기 위한 상수
#define MAX 100000

int main()
{
    int n;
    int dp[MAX];

    cin >> n;
    // 0원과 1원은 거스름돈을 줄 수 없으므로 MAX로 초기화
    dp[0] = MAX;
    dp[1] = MAX;

    for (int i = 2; i <= n; i++)
    {
        // 2원을 추가했을 경우와 5원을 추가했을 경우를 비교할 변수들
        int twoNum = MAX, fiveNum = MAX;
        // 2원이나 5원의 최소 갯수는 1개이므로 1 대입
        if (i == 2 || i == 5)
        {
            dp[i] = 1;
            continue;
        }
        // i가 2원보다 클 경우
        if (i > 2)
        {
            // i-2원의 최소 갯수를 temp에 저장
            int temp = dp[i - 2];
            // i-2가 거스름돈을 줄 수 없는 금액이라면 twoNum에 MAX값 대입
            // 거스름돈을 줄 수 있는 금액이라면 temp에 2원의 최소갯수를 더한다.
            twoNum = temp == MAX ? MAX : dp[2] + temp;
        }
        // i가 5원보다 클 경우
        if (i > 5)
        {
            // i-5원의 최소 갯수를 temp에 저장
            int temp = dp[i - 5];
            // i-5가 거스름돈을 줄 수 없는 금액이라면 fiveNum에 MAX값 대입
            // 거스름돈을 줄 수 있는 금액이라면 temp에 5원의 최소갯수를 더한다.
            fiveNum = temp == MAX ? MAX : dp[5] + temp;
        }
        // 2원 추가했을 경우와 5원 추가했을 경우 중 동전 갯수가 작은 경우를 배열에 넣는다.
        dp[i] = min(twoNum, fiveNum);
    }
    // 거슬러 줄 수 없는 금액이라면 -1을 대입
    if (dp[n] == MAX)
    {
        dp[n] = -1;
    }
    // 최소갯수 출력
    cout << dp[n];
}