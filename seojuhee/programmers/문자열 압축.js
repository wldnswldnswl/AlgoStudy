// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/60057#qna
// ( 설명하기 너무 어렵다....말이 주저리주저리....이해도 안되고 단어 선택도 어렵군
//   귀찮으니까 수정은 하지 않겠어 )
// 추가되는 문자열의 길이를 반환하는 함수 (solution 함수 설명 먼저 읽는것을 추천)
function getAddLength(index, repeat, num) {
	// 자른 문자열이 반복되는 횟수를 문자열 형태로 변환
	const repeatToStr = repeat + '';
	// repeatToStr의 길이를 변수로 선언
	const repeatLength = repeatToStr.length;
	// 반복횟수가 1보다 클 경우
	if (repeat > 1) {
		// 현재 자른 문자열의 단위와 반복횟수의 길이를 더한값을 반환
		return index + repeatLength;
	}
	// 반복횟수가 1보다 작으면
	else {
		// num을 반환
		/*
            이전 문자열과 현재 문자열이 다른 경우 num은 i
            =>  이전 문자열과 같은 문자열이 하나도 없었다는 뜻이기 때문에
                현재 문자열의 단위만 반환하면됨
            더이상 확인할 문자열이 없는 경우 num은 length - j
            =>  남은 문자열의 길이를 반환 
         */
		return num;
	}
}

function solution(s) {
	// 정답변수에 s의 길이를 저장함(원래 문자열의 길이가 압축하여 표현할 수 있는 길이의 최대값이기 때문)
	let answer = s.length;
	// s의 길이를 변수에 저장
	const length = s.length;
	// 자른 문자열의 단위는 1부터 (문자열길이/2)까지만 가능
	for (let i = 1; i <= length / 2; i++) {
		// 임시 문자열 길이 변수는 0으로 초기화, 반복횟수는 1로 초기화
		let tempLength = 0,
			repeat = 1;
		// 이전에 자른 문자열 변수에 s[0]부터 s[i-1]까지 자른 문자열을 저장
		let previous = s.substr(0, i);
		for (let j = i; j < length; j += i) {
			// 현재 자른 문자열 저장
			const current = s.substr(j, i);
			// 이전 문자열과 현재 문자열이 같으면 반복횟수 증가
			if (current == previous) {
				repeat++;
				// 다르면
			} else {
				// 임시 길이 변수에 문자열 길이 추가
				tempLength += getAddLength(i, repeat, i);
				// 반복횟수 1로 초기화
				repeat = 1;
				// 이전 문자열 변수에 현재 문자열 저장
				previous = current;
			}
			// 더 이상 확인할 수 있는 문자열이 없는 경우
			if (i + j >= length) {
				// 임시 길이 변수에 문자열 길이 추가
				tempLength += getAddLength(i, repeat, length - j);
			}
		}
		// 최소값 갱신
		answer = Math.min(tempLength, answer);
	}
	return answer;
}
