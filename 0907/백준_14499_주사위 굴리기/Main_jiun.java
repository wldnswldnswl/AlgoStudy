import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main_jiun {
	private static int N;// map 세로크기
	private static int M;// map 가로크기
	private static int r;// 출발점(행)
	private static int c;// 출발점(열)
	private static int K;// 명령어의 갯수
	private static int[][] map; // 주사위 판
	private static int[] cmd; // 명령어 저장
	private static int[] dice = { 0, 0, 0, 0, 0, 0, 0 }; // 현재 주사위 전개도
	static int[] dr = { 0, 0, 0, -1, 1 };// 동,서,북,남
	static int[] dc = { 0, 1, -1, 0, 0 };// 동,서,북,남

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); // 첫번째 줄 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken()); // x좌표 먼저 입력
		c = Integer.parseInt(st.nextToken()); // y좌표
		K = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		cmd = new int[K];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine()); // MAP한줄씩
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());// 명령어 입력
		for (int i = 0; i < K; i++) {
			cmd[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < K; i++) {// 주사위 굴리기는 다음과 같은 과정으로 k번 반복된다.
			int nr = r + dr[cmd[i]];
			int nc = c + dc[cmd[i]];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;

			r = nr;
			c = nc; // 다음 위치로 이동
			rollDice(cmd[i]);// 1. 명령어 방향으로 주사위 이동시키기
			arrangeMap(r, c);// 2. 주어진 규칙대로 map 변경하기.

			System.out.println(dice[1]);// 3. 이동 후 주사위 상단 값 출력
		}
		
		System.out.println();

	}// end of main

	/**
	 * 2. 주어진 규칙대로 map 변경하기. value의 값이 0인경우, 0 초과인 경우 다른 처리.
	 */
	private static void arrangeMap(int nr, int nc) {

		int value = map[nr][nc];
		switch (value) {
		case 0: // 이동한 칸의 숫자가 0인 경우: 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
			map[nr][nc] = dice[6];
			break;

		default: // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
			dice[6] = value;
			map[nr][nc] = 0;
			break;
		}

	}

	/** 1. 명령어 방향으로 주사위 이동시키기 */
	private static void rollDice(int d) {
		int[] tmp = new int[7];
		switch (d) {
		case 1: // 동
			tmp[1] = dice[4];
			tmp[2] = dice[2];
			tmp[3] = dice[1];
			tmp[4] = dice[6];
			tmp[5] = dice[5];
			tmp[6] = dice[3];
			break;
		case 2:// 서
			tmp[1] = dice[3];
			tmp[2] = dice[2];
			tmp[3] = dice[6];
			tmp[4] = dice[1];
			tmp[5] = dice[5];
			tmp[6] = dice[4];
			break;
		case 3:// 북
			tmp[1] = dice[5];
			tmp[2] = dice[1];
			tmp[3] = dice[3];
			tmp[4] = dice[4];
			tmp[5] = dice[6];
			tmp[6] = dice[2];
			break;
		case 4:// 남
			tmp[1] = dice[2];
			tmp[2] = dice[6];
			tmp[3] = dice[3];
			tmp[4] = dice[4];
			tmp[5] = dice[1];
			tmp[6] = dice[5];
			break;
		}
		// tmp값 dice로 복사
		System.arraycopy(tmp, 0, dice, 0, 7);
	}
}// end of class
