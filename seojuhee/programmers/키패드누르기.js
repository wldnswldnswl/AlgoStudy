// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/67256
// 눌러야할 번호가 (2, 5, 8, 0)일 경우 사용하는 손을 반환하는 함수
function check(leftDistance, rightDistance, hand) {
	let result;
	// 왼손 엄지손가락이 눌러야 할 키패드의 위치와 더 가까울때
	if (leftDistance < rightDistance) {
		// 결과값은 'L'
		result = 'L';
	}
	// 오른손 엄지손가락이 눌러야 할 키패드의 위치와 더 가까울때
	else if (leftDistance > rightDistance) {
		// 결과값은 'R'
		result = 'R';
	}
	// 거리가 같다면 어느손잡이인지 확인해서 결과값 정함
	else {
		result = hand === 'right' ? 'R' : 'L';
	}
	return result;
}

function solution(numbers, hand) {
	// 왼손이 누르는 번호들을 배열에 저장
	const leftNum = [1, 4, 7];
	// 오른손이 누르는 번호들을 배열에 저장
	const rightNum = [3, 6, 9];
	// 양손 다 누를 수 있는 번호들을 배열에 저장
	const chooseNum = [2, 5, 8, 0];
	let answer = '';
	// 양손의 현재 위치를 저장
	let leftLocation = [3, 0],
		rightLocation = [3, 2];

	numbers.forEach((x) => {
		// 지금 누를 번호가 왼손만 누를 수 있는 번호일 경우
		if (leftNum.includes(x)) {
			// 정답변수에 'L'추가
			answer += 'L';
			// 현재 왼손 위치 변경
			leftLocation = [leftNum.indexOf(x), 0];
		}
		// 지금 누를 번호가 오른손만 누를 수 있는 번호일 경우
		else if (rightNum.includes(x)) {
			// 정답변수에 'R'추가
			answer += 'R';
			// 현재 오른손 위치 변경
			rightLocation = [rightNum.indexOf(x), 2];
		}
		// 지금 누를 번호가 양손 다 누를 수 있는 번호일 경우
		else {
			// index는 현재 누르려는 번호 위치의 x좌표가 됨
			const index = chooseNum.indexOf(x);
			// 현재 왼손의 위치에서 누르려는 번호까지의 거리를 저장
			const leftDistance = Math.abs(index - leftLocation[0]) + Math.abs(1 - leftLocation[1]);
			// 현재 오른손의 위치에서 누르려는 번호까지의 거리를 저장
			const rightDistance = Math.abs(index - rightLocation[0]) + Math.abs(1 - rightLocation[1]);
			// result에 사용하게 되는 손 저장
			const result = check(leftDistance, rightDistance, hand);
			// 결과에 따라 현재 손의 위치를 변경해줌
			result === 'L' ? (leftLocation = [index, 1]) : (rightLocation = [index, 1]);
			answer += result;
		}
	});

	return answer;
}
