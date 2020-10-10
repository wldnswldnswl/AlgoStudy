import java.io.BufferedReader;
//https://www.acmicpc.net/problem/11404
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		final int INF = 10000010; // 비용의 최댓값(100,000) * 100(정점 최대 갯수 = 모두 거쳐가는경우)를 넘게 주기. 합을 계산하므로 Integer.MAX_VALUE 버퍼 초과.
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		int[][] graph = new int[n+1][n+1];
	
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < n+1; j++) {
				if(i == j) continue;
				graph[i][j]= INF;
			}
		}//경로 초기화(자기 자신을 제외하고 끊기)
		
		while(m-->0) {
			st = new StringTokenizer(br.readLine()," ");
			 int start = Integer.parseInt(st.nextToken());
	         int end = Integer.parseInt(st.nextToken());
	         int time = Integer.parseInt(st.nextToken());   
	         graph[start][end] = Math.min(graph[start][end], time);    
		}//input
		
		for (int k = 1; k < n+1; k++) {//경유지
			for (int i = 1; i < n+1; i++) {//출발점
				for (int j = 1; j < n+1; j++) {//도착점
					graph[i][j]= Math.min(graph[i][k]+graph[k][j], graph[i][j]); // 경유지 거처서 목적지 까지 가는경우와 거치지 않는 경우 중 최솟값 저장.
				}
			}
		}
		
		for (int i = 1; i <n+1; i++) {
			for (int j = 1; j < n+1; j++) {
				if(graph[i][j] >= INF) System.out.print("0 ");
				else System.out.print(graph[i][j]+" ");
			}
			System.out.println();
		}	
	}
}
