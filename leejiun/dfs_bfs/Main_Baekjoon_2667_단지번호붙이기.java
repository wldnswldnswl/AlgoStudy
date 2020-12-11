import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main_Baekjoon_2667_단지번호붙이기 {
    static char[][] map;
    static boolean[][] visit;
    static int cnt = 0, N;

    public static void main(String[] args) throws IOException {

        // 단지 갯수를 저장하는 pq
        PriorityQueue<Integer> cnt_asc = new PriorityQueue<Integer>();

        // 0.map 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visit = new boolean[N][N];
        map = new char[N][N];
        for (int i = 0; i < N; i++) {
            map[i] = br.readLine().toCharArray();
        }

        // 1.map 순회
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visit[i][j] && map[i][j] == '1') { // 1이면
                    cnt_asc.add(makeVillage(i, j)); // 단지 순회 후 cnt값 정렬큐에 넣기.
                }
            }
        }

        // 2. 총 단지수 출력
        System.out.println(cnt_asc.size());

        // 3. 단지내 집 수 오름차순으로 출력
        // pq가 빌때까지
        while (cnt_asc.size() > 0) {
            System.out.println(cnt_asc.poll()); // poll()값 출력
        }
    }// end of class

    /**
     * 인접해 있는 1의 갯수를 세어주는 함수
     * bfs로 구현
     */
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static int makeVillage(int r, int c) {
        Queue<int[]> q = new LinkedList<int[]>();

        // 1. 순회 초깃값 설정
        cnt = 1;
        q.add(new int[]{r, c});
        visit[r][c] = true;

        // 2. bfs 진행:
        // 인접 위치가 1인 경우만 카운팅
        // 인접 하지 않으면 더이상 세지 않는다.
        while (q.size() > 0) {
            r = q.peek()[0];
            c = q.poll()[1];
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;

                if (map[nr][nc] == '1') {//인접한 위치에 1이 있을때만 넣기
                    cnt++;
                    visit[nr][nc] = true;
                    q.offer(new int[]{nr, nc});
                }
            }
        }

        return cnt;
    }// end of makeVillage
}//end of main
