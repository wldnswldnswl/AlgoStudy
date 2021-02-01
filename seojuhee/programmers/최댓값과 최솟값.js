// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/12939?language=javascript
function solution(s) {
	// 입력된 문자열을 공백을 기준으로 분할
	const inputSplit = s.split(' ');
	// 배열의 최소값과 최대값을 구해 반환
	return Math.min(...inputSplit) + ' ' + Math.max(...inputSplit);
}
