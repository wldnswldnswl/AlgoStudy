import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static boolean isEnd = false;
	static boolean[] visit;
	static int[][] gear;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		gear = new int[5][9];
		for (int i = 1; i < 5; i++) {
			String s = br.readLine();
			for (int j = 1; j < 9; j++) {
				gear[i][j] = s.charAt(j - 1) - '0';
			}
		}// 톱니 상태 입력

		int num = 0, k = 0;
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			String[] s = br.readLine().split(" ");
			num = Integer.parseInt(s[0]);
			k = Integer.parseInt(s[1]);// 1: 시계, -1:반시계
			isEnd = false;
			solution(num, k); // num번째 톱니바퀴를 k방향으로 회전

		} // t번 회전

		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if(gear[i+1][1] == 1) // 12시방향이 S극이면
				cnt += 1<<i; // 점수합산
		}
	
		System.out.println(cnt);

	}// end of main

	private static void solution(int num, int k) {
		left(num-1,-k);//왼쪽 검사
		right(num+1,-k);//오른쪽 검사
		rotate(num,k);
		
	}

	private static void right(int n, int k) {
		if(n > 4)
			return;
		
		if(gear[n][7] != gear[n-1][3]) {
			right(n+1,-k); // 반대방향
			rotate(n,k);
		}
	}

	private static void left(int n, int k) {
		if(n < 1)
			return;
		if(gear[n][3]!=gear[n+1][7]) {// 다르면 반대방향으로 돌릴 것.
			left(n-1,-k);
			rotate(n,k);
		}
	}

	/**
	 * isEnd가 true가 될 때 까지 n번째 톱니바퀴를 k바퀴로 돌린다 회전: gear[n] 수정 회전 후 양 옆 gear 검사 같으면
	 * isEnd = true;
	 */
	private static void rotate(int n, int k) {
		int tmp;
		switch (k) {
		case 1: //시계방향
			tmp = gear[n][8];
			for (int i = 7; i>= 1; i--) {
				gear[n][i+1] = gear[n][i];
			}
			gear[n][1] = tmp; // 회전 완료
			break;
		case -1: //반시계방향
			tmp = gear[n][1];
			for (int i = 1; i <= 7; i++) {
				gear[n][i] = gear[n][i+1];
			}
			gear[n][8] = tmp; // 회전 완료
			break;
		default:
			break;
		}
	}

}// end of class
