import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main_15683_jiun {

	static int m,n;
	static int[][] map;
	private static ArrayList list,cctv;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split(" ");
		n = Integer.parseInt(s[0]); m= Integer.parseInt(s[1]);
		map = new int[n][m];
		
		list = new ArrayList<>();
		cctv = new ArrayList<>();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			String input = br.readLine();
			for (int j = 0,idx=0; j < m; j++,idx+=2) {
				map[i][j]=input.charAt(idx)-'0';
				if(map[i][j]>0 && map[i][j] < 6) {
					list.add(new int[] {i,j});
					cctv.add(map[i][j]);
				}
			}
		}// input end
		getDirection(0);
		System.out.println(ans);
	}
	/* r,c에서부터 벽이나 맵 끝을 만날 때까지 cctv 감시 영역을 표시한다 */
	private static void start(int dir, int r, int c) {
		int nr=0,nc=0;
		switch(dir) {
		case 0://상
			nr  = r -1;
			if(nr <0 || map[nr][c]==6) return;
			map[nr][c]=9;
			start(dir,nr,c);
			break;
		case 1://우
			nc = c+1;
			if(nc >= m || map[r][nc]==6) return;
			map[r][nc]=9;
			start(dir,r,nc);
			break;
		case 2://하
			nr  = r+1;
			if(nr >=n || map[nr][c]==6) return;
			map[nr][c]=9;
			start(dir,nr,c);
			break;
		case 3://좌
			nc = c-1;
			if(nc < 0 || map[r][nc]==6) return;
			map[r][nc]=9;
			start(dir,r,nc);
			break;
		
		}
	}
	static boolean[][] visit;
	static int[] trr; // ex) trr:{0,0,0,0,0}
	static int ans = Integer.MAX_VALUE;
	private static void getDirection(int r) {
		if(r >= list.size()) {
			int cnt = 0;// 갯수세기
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if(map[i][j]==0) {
						cnt++;
                        if(cnt>ans)return;
					}
				}
			}
			
			if(ans > cnt)
				ans= cnt;
			return;
		}
		int[] cur = (int[]) list.get(r);
		int rr = cur[0];
		int cc = cur[1];
		int kind = (int)cctv.get(r); // cctv 종류 선택
		int[][] tmp = new int[n][m];
		if(kind == 1) {
			for (int i = 0; i < 4; i++) {
				copy(tmp,map);
				start(i,rr,cc);
				getDirection(r+1);
				copy(map,tmp); //원상복구
			}
			
		}else if(kind == 2) {
			for (int i = 0; i < 2; i++) {
				copy(tmp,map);
				start(i, rr,cc);
				start((i+2)%4, rr,cc);
				getDirection(r+1);
				copy(map,tmp);
			}
		}else if(kind == 3) {
			for (int i = 0; i < 4; i++) {
				copy(tmp,map);
				start(i, rr,cc);
				start((i+1)%4, rr,cc);
				getDirection(r+1);
				copy(map,tmp);
			}
		}else if(kind == 4) {
			for (int i = 0; i < 4; i++) {
				copy(tmp,map);
				start(i, rr,cc);
				start((i+1)%4, rr,cc);
				start((i+2)%4, rr,cc);
				getDirection(r+1);
				copy(map,tmp);
			}
		}else if(kind == 5) {//왜 else if로는 안되지..?
			copy(tmp,map);
			start(0, rr,cc);
			start(1, rr,cc);
			start(2, rr,cc);
			start(3, rr,cc);
			getDirection(r+1);
			copy(map,tmp);
		}
	}// end of main
	private static void copy(int[][] tmp, int[][] map2) {
		for (int i = 0; i < n; i++) {
			System.arraycopy(map2[i], 0, tmp[i], 0, m);
		}
		
	}
}// end of class

