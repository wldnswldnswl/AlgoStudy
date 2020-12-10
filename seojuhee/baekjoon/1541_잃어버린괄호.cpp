#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	// 식을 입력받을 문자열, 현재숫자를 저장할 문자열 변수
	string expression, curNum = "";
	// 연산에 쓰일 숫자를 저장하는 벡터
	vector<int> numArr;
	// 변수의 총합과 정답, 식의 길이를 저장할 변수
	int sumNum = 0, answer, expression_size, numArr_size;

	cin >> expression;
	expression_size = expression.size();

	for (int i = 0; i < expression_size; i++) {
		int num = expression[i] - '0';
		// 현재 원소가 숫자일 경우
		if (num >= 0 && num <= 9) {
			// 현재숫자를 저장
			curNum += num;
			// 마지막원소일 경우
			if (i == expression_size - 1) {
				// 지금까지의 변수의 총합을 구한 후 배열에 추가한다
				sumNum += stoi(curNum);
				numArr.push_back(sumNum);
			}
			continue;
		}
		// 현재숫자를 더함
		sumNum += stoi(curNum);
		// '-' 연산자일 경우 배열에 총합값을 추가하고 총합변수 초기화
		if (expression[i] == '-') {
			numArr.push_back(sumNum);
			sumNum = 0;
		}
		// 현재숫자 초기화
		curNum = "";
	}
	// answer에 배열의 첫번째 원소를 대입함
	answer = numArr[0];
	numArr_size = numArr.size();

	for (int i = 1; i < numArr_size; i++) {
		// 배열 원소들을 계속 뺌
		answer -= numArr[i];
	}

	cout << answer;
}