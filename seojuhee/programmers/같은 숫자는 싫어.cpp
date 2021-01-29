#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/12906

// 풀이방법 1
vector<int> solution(vector<int> arr)
{
    // 이전숫자를 저장하는 변수
    int prevNum = -1;
    vector<int> answer;

    for (auto elem : arr)
    {
        // 현재숫자가 이전숫자와 다를 경우
        if (prevNum != elem)
        {
            // 현재숫자를 정답 벡터에 추가
            answer.push_back(elem);
            // 현재숫자를 이전숫자 변수에 대입
            prevNum = elem;
        }
    }

    return answer;
}

// 풀이방법2
vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    // unique는 연속된 중복원소를 벡터의 뒷부분으로 쓰레기값으로 보냄
    // 그리고 그 쓰레기값의 제일 첫번째 원소를 반환하기 때문에 erase를 이용하면
    // 중복원소들을 한번에 제거할 수 있음
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    answer = arr;

    return answer;
}