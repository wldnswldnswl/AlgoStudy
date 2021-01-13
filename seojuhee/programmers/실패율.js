// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/42889?language=javascript
function solution(N, stages) {
	let answer = [];
	// 스테이지를 클리어하지 못한 사용자의 수를 저장하는 배열
	let numberCount = new Array(N).fill(0);
	// 실패율과 해당 스테이지 숫자를 저장할 배열
	let failureRate = [];
	// 사용자의 수를 저장하는 변수
	let userCnt = stages.length;
	// 스테이지 번호를 오름차순으로 정렬
	stages.sort();

	stages.forEach((x) => {
		// 현재 원소가 제일 높은 스테이지보다 작거나 같을 경우
		// (현재 원소가 스테이지 최고단계보다 큰 숫자라는건 해당 사용자는 모든 스테이지를 클리어했다는 얘기)
		if (x <= N) {
			// numberCount[x-1]를 1 증가시킴
			numberCount[x - 1]++;
		}
	});

	for (let i = 0; i < N; i++) {
		// 실패율과 현재 스테이지 번호 저장
		failureRate.push([numberCount[i] / userCnt, i + 1]);
		// 전체 사용자 수에서 현재 스테이지를 클리어하지 못한 사용자의 수를 뺀다
		// (현재 스테이지도 클리어하지 못한 사용자는 다음 스테이지를 도전하지 못하기 때문)
		userCnt -= numberCount[i];
	}
	// 실패율을 저장한 배열에서 실패율을 기준으로 내림차순 정렬
	failureRate.sort((a, b) => {
		return b[0] - a[0];
	});
	// 실패율이 높은 스테이지 번호순대로 answer배열에 저장
	failureRate.forEach((x) => {
		answer.push(x[1]);
	});

	return answer;
}
