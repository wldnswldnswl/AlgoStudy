// 720ms
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String[] s = br.readLine().split(" ");
		int m = Integer.parseInt(s[0]), n = Integer.parseInt(s[1]), h = Integer.parseInt(s[2]);// m:가로, n:세로, h:세로
																								// (아래서부터 쌓아올린다.)
		int[][][] map = new int[h][n][m];

		int[] dr = { -1, 1, 0, 0 };
		int[] dc = { 0, 0, -1, 1 };
		int cnt = 0;// 익지 않은 토마토
		Queue<int[]> q = new LinkedList<>();
		boolean[][][] visit = new boolean[h][n][m];

		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < m; k++) {
					map[i][j][k] = Integer.parseInt(st.nextToken()); // 1: 익은 토마토, 0: 익지 않은 토마토, -1: 빈 칸
					if (map[i][j][k] == 0)
						cnt++;
					else if (map[i][j][k] == 1) {
						visit[i][j][k] = true;
						q.add(new int[] { i, j, k, 0 });
					}
				}
			}
		} // input end

		// 토마토가 모두 익을 때까지 최소 며칠. 모두 익지 못하는 경우는 -1, 시작부터 익어있는 경우는 0
		if (cnt == 0) { // 익지않은 토마토가 0개인 경우는
			System.out.println(0); // 시작부터 익어있는 경우이므로
			return;
		}

		int time = 0;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			int hh = cur[0];
			int rr = cur[1];
			int cc = cur[2];
			time = cur[3];

			// 윗칸 검사
			if (hh - 1 >= 0 && !visit[hh - 1][rr][cc] && map[hh - 1][rr][cc] == 0) { // 익지않은 토마토면 전파
				visit[hh - 1][rr][cc] = true;
				map[hh - 1][rr][cc] = 1;
				q.offer(new int[] { hh - 1, rr, cc, time + 1 });
				cnt--;
			}

			// 아래칸 검사
			if (hh + 1 < h && !visit[hh + 1][rr][cc] && map[hh + 1][rr][cc] == 0) { // 익지않은 토마토면 전파
				visit[hh + 1][rr][cc] = true;
				map[hh + 1][rr][cc] = 1;
				q.offer(new int[] { hh + 1, rr, cc, time + 1 });
				cnt--;
			}

			// 나머지 인접 칸 검사
			for (int i = 0; i < 4; i++) {
				int nr = rr + dr[i];
				int nc = cc + dc[i];

				if (nr < 0 || nr >= n || nc < 0 || nc >= m|| visit[hh][nr][nc])
					continue;
				
				if (map[hh][nr][nc] == 0) {//익지 않은 토마토면
					visit[hh][nr][nc]=true;
					cnt--;
					q.offer(new int[] { hh, nr, nc, time + 1 });
				}

			}

		}
		System.out.println(cnt == 0 ? time : -1);
	}// end of main
}// end of class
