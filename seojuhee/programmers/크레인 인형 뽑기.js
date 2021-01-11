// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/64061
function solution(board, moves) {
	let answer = 0;
	// 각 배열의 길이 변수에 저장
	let movesLength = moves.length,
		boardLength = board.length;
	// 인형 바구니를 나타내는 배열
	let dolls = [];
	for (let k = 0; k < movesLength; k++) {
		// board배열에서 moves[k]열만 확인하면됨
		for (let i = 0; i < boardLength; i++) {
			// 현재 크레인이 있는 위치의 숫자를 저장
			const current = board[i][moves[k] - 1];
			// 인형바구니의 길이를 저장
			const dollsLength = dolls.length;
			// 현재 위치에 인형이 있을 경우
			if (current != 0) {
				// 인형바구니에 인형이 있고 마지막에 들어간 인형과 현재 위치의 인형이 일치하면
				if (dollsLength > 0 && dolls[dollsLength - 1] == current) {
					// 인형바구니에서 마지막 인형 제거
					dolls.pop();
					// 인형은 한번에 2개가 터지므로 2 증가
					answer += 2;
				} else {
					// 위 조건에 맞지 않으면 바구니에 인형 넣음
					dolls.push(current);
				}
				// 인형은 없어졌으니까 board배열 원소 0으로 바꿈
				board[i][moves[k] - 1] = 0;
				break;
			}
		}
	}
	return answer;
}
