#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 80
// 문제링크: https://www.acmicpc.net/problem/13301
/*
    풀이방법: 타일 갯수에 따른 직사각형의 둘레를 계산해보며 규칙성을 파악한다.
    N = 1 => 1 * 4 = 4
    N = 2 => 1 * 3 + 1 * 3 = 6 
    N = 3 => 1 * 2 + 1 * 2 + 2 * 3 = 10
    N = 4 => 1 * 2 + 1 * 1 + 2 * 2 + 3 * 3 = 16
    N = 5 => 1 * 1 + 1 * 0 + 2 * 2 + 3 * 2 + 5 * 3 = 26
    DP[i] = DP[i - 1] + DP[i - 2] (i >= 2)라는 식을 얻을 수 있다.
*/
int main()
{
    int N;
    long long dp[MAX];

    cin >> N;
    // 0번째 원소와 1번째 원소의 초기값은 따로 설정
    dp[0] = 4;
    dp[1] = 6;
    // 위에서 얻은 식을 적용
    for (int i = 2; i < N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N - 1];
}