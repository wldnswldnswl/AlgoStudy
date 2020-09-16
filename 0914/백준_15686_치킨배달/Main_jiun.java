import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main_jiun {
	static int n,m;
	static int[][] map;
	static boolean[] visit;
	static List<Integer> store = new ArrayList<>();// 선택된 치킨집 저장.
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split(" " );
		n = Integer.parseInt(s[0]); 
		m = Integer.parseInt(s[1]);
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			String line= br.readLine();
			for (int j = 0,idx=0; j < n; j++,idx+=2) {
				map[i][j]= line.charAt(idx)-'0';
				if(map[i][j]==2) {
					store.add(i*n+j);
				}
			}
		} // input end
		trr = new int[m];
		visit = new boolean[store.size()];
		comb(0,0);
		System.out.println(result);
	}// end of main

	static int result = Integer.MAX_VALUE;
	static int[] trr;
	/** m개를 고르는 경우 */
	private static void comb(int select, int idx) {
		if(select == m) {
			int minCnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int min = Integer.MAX_VALUE;
					if(map[i][j]==1) {//일반집이면
						for (int chichken : trr) {
							int cur = getDistance(i, j, chichken/n, chichken%n);	// 각 치킨집으로부터와의 거리 구하기
							min = Math.min(cur, min);// 그 중 최솟값을 minCnt에 더하기
						}
						minCnt+=min;
					}
				}
			}
			if(result > minCnt)
				result = minCnt;
			return;
		}
		
		
		for (int i = idx; i < store.size(); i++) {
			if(!visit[i]) {//치킨집이면
				// 조합구하기
				visit[i]=true;
				trr[select]=store.get(i);
				comb(select+1, i+1);// 선택
				
				visit[i]=false;
				comb(select, i+1);// 비선택
			}
		}
		
		
		
	}
	private static int getDistance(int i, int j, int i2, int j2) {
		return Math.abs(i-i2) + Math.abs(j-j2);
	}
}// end of class
