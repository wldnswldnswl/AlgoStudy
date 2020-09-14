#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	string str;
    //원소들을 담을 스택 변수 선언
	stack<char> temp;
	int cnt = 1, answer = 0;
    //올바른 괄호열 여부를 체크해주는 flag 변수
	bool flag = true;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
        //str[i]가 '('일 경우 cnt를 2 곱해주고 스택에 푸시한 후 continue한다.
		if (str[i] == '(') {
			temp.push(str[i]);
			cnt *= 2;
            continue;
		}
        //str[i]가 '['일 경우 cnt를 3 곱해주고 스택에 푸시한 후 continue한다.
		else if (str[i] == '[') {
			temp.push(str[i]);
			cnt *= 3;
            continue;
		}
        //str[i]가 ')'일 경우
		else if (str[i] == ')') {
            //스택이 비어있거나 스택의 맨 위 원소가 '('이 아니라면 올바른 괄호열이 아니기 때문에
            //flag를 false로 바꿔주고 반복문을 종료한다.
			if (temp.empty() || temp.top() != '(') {
				flag = false;
				break;
			}
            //str[i-1]가 '('일 경우 answer에 cnt값을 더한다. 
            //=> 괄호쌍이 처음으로 맞는 경우
			if(str[i-1] == '(')
				answer += cnt;
            //스택에서 '('를 pop할 거니까 cnt는 2를 나눠준다
			cnt /= 2;
		}
        //str[i]가 ']'일 경우
		else {
            //스택이 비어있거나 스택의 맨 위 원소가 '['이 아니라면 올바른 괄호열이 아니기 때문에
            //flag를 false로 바꿔주고 반복문을 종료한다.
			if (temp.empty() || temp.top() != '[') {
				flag = false;
				break;
			}
            //str[i-1]가 '['일 경우 answer에 cnt값을 더한다. 
            //=> 괄호쌍이 처음으로 맞는 경우
			if(str[i-1] == '[')
				answer += cnt;
            //스택에서 '['를 pop할 거니까 cnt는 3을 나눠준다
			cnt /= 3;
		}
        //스택의 맨 위 원소를 pop한다.
       temp.pop();
	}
    //올바른 괄호열이 아닐 경우 0 출력
	if (!flag || !temp.empty())
		cout << "0";

	else
		cout << answer;
}