// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/72410
function solution(new_id) {
	const answer = new_id
		.toLowerCase() // 문자열의 대문자를 소문자로 치환
		.replace(/[^\w-_.]/g, '') // 알파벳 소문자, 숫자, '-', '_', '.'를 제외한 모든 문자를 제거
		.replace(/\.{2,}/g, '.') // '.'이 2번 이상 연속되면 '.'로 변환
		.replace(/^\.|\.$/g, '') // '.'가 문자열의 처음이나 끝에 위치하면 제거
		.replace(/^$/, 'a') // 문자열이 비어있다면 'a'를 대입
		.substr(0, 15) // 문자열을 15개까지만 자름
		.replace(/\.$/g, ''); // '.'가 문자열의 끝에 위치하면 제거
	// answer의 길이가 3이 될때까지 answer의 마지막 원소를 반복해서 끝에 붙임
	return answer.padEnd(3, answer[answer.length - 1]);
}
