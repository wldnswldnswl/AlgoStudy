import java.io.BufferedReader;
//https://www.acmicpc.net/problem/11404
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/**
 * 1. 15가지 테트로미노 종류를 가지고 맵에 모든 경우에 놓아본다.
 * 		1.1. map의 모든 점을 차례로 선택.
 * 		1.2. 해당 위치에 15가지의 테트로미노 놓아보기.
 * 		1.3. 합을 최댓값으로 갱신
 * 2. 그 중 합이 최대가 되는 것을 리턴
 */
public class Main_jiun {
	static int[][] tmR = {// 테트로미노 종류 -  r: i,j위치에서부터 아래로 r칸 이동
			{0,1,2,3},{0,0,0,0},//1번
			{0,0,1,1},//2번
			{0,1,2,2},{0,0,1,2},{0,1,2,2},{0,0,1,2},{1,0,0,0},{0,0,0,1},{0,1,1,1},{1,1,1,0},//3
			{0,0,0,1},{0,1,2,1},{0,1,1,1},{1,0,1,2},//4
			{0,1,1,2},{0,1,1,2},{1,1,0,0},{0,0,1,1}//5
	}; 
	static int[][] tmC = {//테트로미노 종류 - c: i,j위치에서부터 오르쪽으로 c칸 이동
			{0,0,0,0},{0,1,2,3},//1번
			{0,1,0,1},//2번
			{0,0,0,1},{0,1,0,0},{1,1,1,0},{0,1,1,1},{0,0,1,2},{0,1,2,2},{0,0,1,2},{0,1,2,2},//3
			{0,1,2,1},{0,0,0,1},{1,0,1,2},{0,1,1,1},//4
			{0,0,1,1},{1,1,0,0},{0,1,1,2},{0,1,1,2}//5
	};
	private static int n,m; 
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st  = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		int max = 0; // 테트로미노 칸 합 중 최댓값.
		
		for (int i = 0; i < n; i++) {
			st  = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j]=Integer.parseInt(st.nextToken());
			}
		}// input
		
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < tmR.length; k++) {
					if(!isRange(i,j,k)) continue;
					sum = map[i+tmR[k][0]][j+tmC[k][0]] + map[i+tmR[k][1]][j+tmC[k][1]]+ map[i+tmR[k][2]][j+tmC[k][2]]+ map[i+tmR[k][3]][j+tmC[k][3]];
					if(max < sum)
						max = sum;
				}
			}
		}
		System.out.println(max);
	} // end of main

	/** k번째 테트로미노의 범위가 map의 범위를 벗어나면 false, 벗어나지 않으면 true 
	 * 0,0부터 오른쪽, 아래로 검사하므로 0,0이전으로 가는 경우는 고려하지 않는다.*/
	private static boolean isRange(int r, int c, int k) {
		if(r+tmR[k][0] >=n || r+tmR[k][1] >=n|| r+tmR[k][2] >=n|| r+tmR[k][3] >=n
		|| c+tmC[k][0] >=m || c+tmC[k][1] >=m|| c+tmC[k][2] >=m|| c+tmC[k][3] >=m)
		return false; //맵의 범위를 벗어나는 경우
		
		return true;// 맵의 범위 안에 있는 경우
	}
}// end of class
