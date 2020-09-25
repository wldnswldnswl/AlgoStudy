import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
public class Main_16235_jiun {
	private static PriorityQueue<Tree> trees;
	private static Queue<Tree> alive, dead;
	private static int[][] A, map;
	private static int cnt;
	private static int n, m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken()); // 첫째줄
		cnt = m; // 살아있는 나무의 갯수
		A = new int[n + 1][n + 1];
		map = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= n; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
				map[i][j] = 5;// 처음 양분으 5
			}
		} // 2-n까지의줄
		trees = new PriorityQueue<Tree>();
		alive = new LinkedList<Tree>();
		dead = new LinkedList<Tree>();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			trees.add(new Tree(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken())));// 0:r좌표, 1:c좌표, 2: 나이
		} // m개의 줄

		for (int i = 0; i < k; i++) {
			spring();
			summer();
			autumn();
			winter();
		}
		System.out.println(trees.size());
	}// end of main

	/** map에 양분을 추가. 현재칸에 A[r][c]를 더한다. */
	private static void winter() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] += A[i][j];
			}
		}
	}

	static int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	/**
	 * 나무의 나이가 5의 배수이면, 인접한 8개의 칸으로 나이가 1인 나무 추가(번식) 칸을 벗어나면 생기지 않음.
	 */
	private static void autumn() {
		while (!alive.isEmpty()) {
			Tree cur = alive.poll();
			if (cur.age % 5 == 0) {
				for (int i = 0; i < 8; i++) {// 번식
					int nr = cur.r + dr[i];
					int nc = cur.c + dc[i];
					if (nr < 1 || nr >= n + 1 || nc < 1 || nc >= n + 1)
						continue;
					trees.add(new Tree(nr,nc,1));
				}
			}
			trees.add(cur);
		}
	}

	/**
	 * 죽은 나무이면 (나무 나이)/2를 양분으로 추가. 소수점 아래는 버린다.
	 */
	private static void summer() {
		while (!dead.isEmpty()) { // 죽은 나무 list에서 없애기ㅣ.
			Tree cur = dead.poll();
			map[cur.r][cur.c] += cur.age / 2; // (나무 나이)/2를 양분으로 추가
		}

	}

	/**
	 * 자신의 나이만큼 양분을 먹고, 나이가 1 증가. 하나의 칸에 여러개의 나무가 있다면 어린 나무부터 양분을 먹는다. 양분이 부족해 자신의
	 * 나이만큼 먹지 못하면 죽는다.
	 */
	private static void spring() {
		while (!trees.isEmpty()) {
			Tree cur = trees.poll();
			int r = cur.r;
			int c = cur.c;
			int age = cur.age;

			if (map[r][c] >= age) { // 양분이 나이보다 많고, 죽은 나무가 아니라면
				map[r][c] -= age;
				cur.age += 1;
				alive.add(cur);
			} else {
				dead.add(cur);
			}

		}
	}

	static class Tree implements Comparable<Tree> {
		int r,c,age;

		public Tree(int r, int c, int age) {
			this.r = r;
			this.c = c;
			this.age = age;
		}

		@Override
		public int compareTo(Tree o) {
			return Integer.compare(this.age, o.age);
		}

	}
}// end of class
