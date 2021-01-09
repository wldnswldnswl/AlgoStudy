// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/17676
/*
    요청량은 로그의 시작과 끝에서만 변경된다.
    따라서 각 로그의 시작과 끝에서부터 1초간 처리하는 요청의 개수를 각각 구하고
    그 중의 최대값을 구하면 된다.
*/
// 초당 최대 처리량을 반환하는 함수 (index: 0 - 로그 시작시간, index: 1 - 로그 종료시간)
function getMaxProcess(times, index) {
	// times배열의 길이를 변수에 저장
	const timesLength = times.length;
	// 초당 최대 처리량을 저장할 변수
	let result = 0;
	for (let i = 0; i < timesLength; i++) {
		// 시작구간
		const startRange = times[i][index];
		// 종료구간
		const endRange = startRange + 1;
		// 해당 구간에서 처리되는 요청의 개수를 저장하기 위한 변수
		let count = 0;
		for (let j = 0; j < timesLength; j++) {
			// 각 로그의 시작시간과 종료시간을 저장
			const itemStart = times[j][0];
			const itemEnd = times[j][1];
			/*  
                로그가 해당 구간에 포함되는 경우는 총 3가지가 있다
                1. 해당 구간이 로그의 시작시간과 종료시간 사이에 포함될때
                2. 로그의 시작시간이 해당 구간 사이에 포함될때
                3. 로그의 종료시간이 해당 구간 사이에 포함될때
                => 위에 해당된다면 처리되는 요청 개수를 1 증가시킴
             */
			if ((itemStart <= startRange && itemEnd >= endRange) || (itemEnd >= startRange && itemEnd < endRange) || (itemStart >= startRange && itemStart < endRange)) {
				count++;
			}
		}
		// 최대값을 result에 저장
		result = Math.max(result, count);
	}
	return result;
}

function solution(lines) {
	// lines배열의 길이를 저장
	const linesLength = lines.length;
	// 정답을 저장할 변수
	let answer = 0;
	// 각 로그의 시작시간과 종료시간을 저장할 배열
	let times = [];
	for (let i = 0; i < linesLength; i++) {
		// 로그의 종료시간을 시 / 분 / 초 단위로 쪼갬
		const separation = lines[i].substr(11, 12).split(':');
		// 분리된 시간의 길이를 저장하는 변수
		const separationLength = separation.length;
		// 로그의 처리시간을 저장
		const process = lines[i].slice(24, -1);
		let temp = 3600,
			sum = 0;
		// 로그의 종료시간을 초단위로 바꿈
		for (let i = 0; i < separationLength; i++) {
			sum += separation[i] * temp;
			temp /= 60;
		}
		// times배열에 해당 로그의 시작시간과 종료시간을 저장
		times.push([sum - process + 0.001, sum]);
	}
	// 로그의 시작시간을 기준으로 배열을 오름차순으로 정렬
	times.sort((a, b) => a[0] - b[0]);
	// 로그의 시작시간을 기준으로 정했을때 / 종료시간을 기준으로 정했을때의 최대 처리량을 구하고
	// 거기서 또 최대값을 구해서 answer에 저장
	answer = Math.max(getMaxProcess(times, 0), getMaxProcess(times, 1));
	return answer;
}
