#include <algorithm>
#include <iostream>
using namespace std;
// N번째 피보나치 수는 dp[N]에 저장되므로 MAX값은 90+1로 설정한다.
#define MAX 91
// 문제링크: https://www.acmicpc.net/problem/2748
int main()
{
    int N;
    // N의 최대값은 90이므로 배열의 자료형은 long long으로 선언한다.
    long long dp[MAX];

    cin >> N;
    // 0번째, 1번째 피보나치 수 초기화
    dp[0] = 0;
    dp[1] = 1;
    // N번째 피보나치 수 계산하며 저장
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // 정답 출력
    cout << dp[N];
}