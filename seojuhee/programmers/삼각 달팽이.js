// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/68645
/*
    삼각형에 숫자를 채울때는 총 3가지의 방향이 존재한다. (아래, 오른쪽, 위)
    각 방향별로 턴이 진행될때마다 숫자가 처음 채워지는 초기 위치의 규칙을
    찾아서 이를 코드에 적용한다.
*/
function solution(n) {
	var answer = [];
	// 숫자를 채워넣을 삼각형 배열
	var triangle = new Array(n);
	// 각 방향의 초기값 선언 (행, 열)
	var up_x = n - 2,
		up_y = n - 2,
		down_x = 0,
		down_y = 0,
		right_x = n - 1,
		right_y = 1;
	// 현재 방향과 숫자를 저장하는 변수
	var direction = 0,
		num = 1;
	// 삼각형 모양이 될 수 있게 배열 채워넣기
	for (var i = 0; i < n; i++) {
		triangle[i] = new Array(i + 1);
	}
	// k는 한 방향으로 숫자를 채울때 얼마나 채울지 결정하는 변수
	// (맨 처음에는 아래방향으로 n개 채우고, 오른쪽 방향으로 n-1개, 위쪽으로 n-2개, ...)
	for (var k = n; k >= 1; k--) {
		// 현재 방향을 결정하는 변수
		var temp = direction % 3;
		switch (temp) {
			// 아래쪽 방향일때
			case 0:
				for (var i = down_x; i <= down_x + k - 1; i++) {
					triangle[i][down_y] = num++;
				}
				down_x += 2;
				down_y++;
				break;
			// 오른쪽 방향일때
			case 1:
				for (var j = right_y; j <= right_y + k - 1; j++) {
					triangle[right_x][j] = num++;
				}
				right_x--;
				right_y++;
				break;
			// 위쪽 방향일때
			case 2:
				var j = up_y;
				for (var i = up_x; i >= up_x - k + 1; i--) {
					triangle[i][j--] = num++;
				}
				up_x--;
				up_y -= 2;
		}
		// 방향이 변경될 수 있도록 1 증가시킴
		direction++;
	}
	// 결과값을 answer배열에 넣음
	for (var i = 0; i < n; i++) {
		for (var j = 0; j <= i; j++) {
			answer.push(triangle[i][j]);
		}
	}

	return answer;
}
