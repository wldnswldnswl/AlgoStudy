#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
// 문제링크: https://www.acmicpc.net/problem/1439
int main() {
	string arr;
    // 뒤집어야 하는 0과 1의 개수를 저장하는 변수
	int cnt_0 = 0, cnt_1 = 0;
    // 문자 입력받음
	cin >> arr;
	for (int i = 0; i < arr.length() - 1; i++) {
        // 현재 원소가 0이고 다음원소가 1일 경우
		if (arr[i] == '0' && arr[i + 1] == '1') {
            // 문자열의 첫번째 원소가 0일 경우  cnt_0, cnt_1를 1 증가시킴
			if (arr[0] == '0') {
				cnt_0++;
				cnt_1++;
			}
            // 아닐 경우 cnt_0만 증가시킴
			else
				cnt_0++;
		}
        // 현재 원소가 1이고 다음원소가 0일 경우
		if (arr[i] == '1' && arr[i + 1] == '0') {
            // 문자열의 첫번째 원소가 1일 경우 cnt_0, cnt_1를 1 증가시킴
			if (arr[0] == '1') {
				cnt_0++;
				cnt_1++;
			}
            // 아닐 경우 cnt_1만 증가시킴
			else
				cnt_1++;
		}
	}
	// 변경된 0과 1의 갯수 중 최소횟수 출력
	printf("%d", min(cnt_0, cnt_1));

}
