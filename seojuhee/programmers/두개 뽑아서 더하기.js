// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/68644
function solution(numbers) {
	// 임시 배열 선언
	let temp = [];
	// 정답 배열 선언
	let answer;
	// numbers배열에서 서로 다른 인덱스에 있는 수를 뽑아서 더한값을 temp배열에 넣음
	// (가능한 경우는 다 더함)
	for (let i = 0; i < numbers.length - 1; i++) {
		for (let j = i + 1; j < numbers.length; j++) {
			temp.push(numbers[i] + numbers[j]);
		}
	}
	// temp배열에서 중복값을 제거하여 answer에 저장
	answer = [...new Set(temp)];
	// answer배열 오름차순으로 정렬
	answer.sort(function (a, b) {
		return a - b;
	});

	return answer;
}
