#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void change_dice(vector<vector<int>> &dice, int num) {
    //이동명령에 따라 주사위 값을 바꿔줌. 
    //동쪽으로 이동할경우 주사위를 오른쪽으로 굴리는거고 그에 맞춰서 값을 바꾼다.
	if (num == 1) {
		swap(dice[1][0], dice[1][2]);
		swap(dice[1][0], dice[3][1]);
		swap(dice[1][1], dice[1][2]);
	}
	else if (num == 2) {
		swap(dice[1][0], dice[3][1]);
		swap(dice[1][0], dice[1][2]);
		swap(dice[1][0], dice[1][1]);
	}
	else if (num == 3) {
		swap(dice[0][1], dice[1][1]);
		swap(dice[1][1], dice[3][1]);
		swap(dice[1][1], dice[2][1]);
	}
	else {
		swap(dice[1][1], dice[3][1]);
		swap(dice[0][1], dice[1][1]);
		swap(dice[2][1], dice[3][1]);
	}
}

int main() {
	int N, M, x, y, K;
	int temp_x, temp_y;
	vector<vector<int>> map;
    //주사위의 전개도를 저장하는 배열, 초기에는 모두 0
	vector<vector<int>> dice(4, vector<int>(3, 0));
    //동, 서, 남, 북으로 이동할 시 위치를 바꿔주기 위한 변수를 저장한 배열
	int loc[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
                     //동     //서     //남      //북
	cin >> N >> M >> x >> y >> K;
	map.assign(N, vector<int>(M));
	vector<int> move(K);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
    //주사위 바닥면에 현재 지도 좌표의 칸에 써져있는 수를 대입한다.
	dice[3][1] = map[x][y];
	
	for (int i = 0; i < K; i++) 
		cin >> move[i];

	for (int i = 0; i < K; i++) {
        //이동 명령에 따라 임시 위치 조정
		temp_x = x + loc[move[i] - 1][0];//이동 명령값이 1~4이기 때문에 loc 값에 접근할때는 -1해야함
		temp_y = y + loc[move[i] - 1][1];
        //임시위치가 지도를 벗어난다면 해당 명령 무시
		if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= M)
			continue;
		x = temp_x;
		y = temp_y;
        //이동 명령에 따라 주사위 굴림
		change_dice(dice, move[i]);
        //이동한 칸의 수가 0이면 해당칸에 주사위 바닥면의 수 복사
		if (map[x][y] == 0)
			map[x][y] = dice[3][1];
        //0 아니면 주사위 바닥면에 해당 칸의 수가 복사됨
		else {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
        }
        //이동이 끝났으면 주사위 윗면 출력
		cout << dice[1][1] << '\n';
	}


}