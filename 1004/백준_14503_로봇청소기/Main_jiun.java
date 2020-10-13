import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	static int n,m,r,c,dir;
	static int[] dr= {-1,0,1,0};
	static int[] dc= {0,1,0,-1};//북동남서
	private static int[][] map;
	private static boolean[][] visit;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); //n:세로
		m = Integer.parseInt(st.nextToken()); //m:가로
		st = new StringTokenizer(br.readLine());
		r=Integer.parseInt(st.nextToken()); //로봇위치 :r
		c=Integer.parseInt(st.nextToken()); //로봇위치 :c
		dir=Integer.parseInt(st.nextToken()); //로봇방향:dir
		map= new int[n][m];
		visit= new boolean[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j]=Integer.parseInt(st.nextToken()); 
			}
		}// input end
		/////////////////////////////////////////////////////////////////
		//////////////////// logic start////////////////////////////////
		
		while(true) {
			
			if(map[r][c] == 0) {//1. 빈공간이면
				map[r][c] = 9;//청소
			}else { 
				if(map[r+1][c] != 0 && map[r][c+1] != 0
						&& map[r-1][c] != 0 && map[r][c-1] != 0) {// 네 방향 모두 청소 or 벽
					if(map[r-dr[dir]][c-dc[dir]] == 1) break;
					else {//방향 유지, 후진
						r = r-dr[dir];
						c = c-dc[dir];
					}
				}else {
					dir = (dir+3) % 4;//왼쪽방향 보기
					if(map[r+dr[dir]][c+dc[dir]] == 0) {
        				r = r+dr[dir];
        				c = c+dc[dir];
        			}

				}
				
			}// for
		}// bfs end
		
		
		int cnt= 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(map[i][j]==9) cnt++;
			}
		}
		System.out.println(cnt);
		return;
	}// main
}// class
