// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/68935
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    // 정답, 벡터의 길이, 마지막 반복문에서 3진법으로 표현된 수를 10진법으로
    // 변환하기 위해 사용할 변수들
    int answer = 0, length, mul = 1;
    // 3진법으로 변환된 숫자를 저장할 벡터
    vector<int> ternary;

    while (n > 0)
    {
        // n을 3으로 나눈 나머지를 벡터에 넣음 (앞뒤 반전)
        ternary.push_back(n % 3);
        // n을 3으로 나눔
        n /= 3;
    }
    // 벡터의 크기를 변수에 대입
    length = ternary.size();
    // 벡터에 저장된 숫자를 10진법으로 변환
    for (int i = length - 1; i >= 0; i--)
    {
        answer += ternary[i] * mul;
        mul *= 3;
    }

    return answer;
}