// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/17679?language=javascript
// 지울 수 있는 블록의 위치를 저장해서 반환하는 함수
function bfs(m, n, board) {
	// 블록의 위치 저장할 배열
	let point = [];
	for (let i = 0; i < m - 1; i++) {
		for (let j = 0; j < n - 1; j++) {
			// 4개의 블럭이 모두 같을 경우
			if (board[i][j] && board[i][j] === board[i][j + 1] && board[i][j + 1] === board[i + 1][j] && board[i + 1][j] === board[i + 1][j + 1]) {
				// 위치 저장
				point.push([i, j]);
			}
		}
	}
	return point;
}

function solution(m, n, board) {
	let answer = 0;
	// board의 문자열 원소들을 잘라서 2차원 배열로 저장함
	board = board.map((v) => v.split(''));

	while (1) {
		// 지워야 할 블록 위치 반환받음
		const point = bfs(m, n, board);
		// 더이상 지울 수 있는 블록이 없다면 반복문 종료
		if (point.length === 0) {
			break;
		}
		// 지워야 할 블록 위치 확인하여 4개의 블록을 지운다
		point.forEach((x) => {
			const row = x[0],
				column = x[1];
			board[row][column] = 0;
			board[row][column + 1] = 0;
			board[row + 1][column] = 0;
			board[row + 1][column + 1] = 0;
		});
		// 빈공간을 메꾸기 위해 블록을 아래로 내린다.
		for (let j = 0; j < n; j++) {
			for (let i = 0; i < m; i++) {
				// 현재 위치에 블록이 없다면
				if (!board[i][j]) {
					// 아래로 쫙쫙 내린다.
					for (let k = i; k > 0; k--) {
						board[k][j] = board[k - 1][j];
						board[k - 1][j] = 0;
					}
				}
			}
		}
	}
	// board를 다시 1차원 배열로 변환하고 지워진 블록의 개수를 센다
	answer = [].concat(...board).filter((v) => !v).length;

	return answer;
}
