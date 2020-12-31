// https://www.acmicpc.net/problem/15650
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_Baekjoon_15650_N과M{
	private static int[] ret;
	private static boolean[] visit;
	private static int R;
	private static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		ret = new int[R];
		visit = new boolean[n];
		comb(0,1);
	}

	private static void comb(int idx, int start) {
		if(idx == R) {
			for (int j = 0; j < ret.length; j++) {
				System.out.print(ret[j]+" ");
			}
			System.out.println();
			return;
		}
		
		for (int j = start; j <= n; j++) {
				ret[idx]=j;
				comb(idx+1,j+1);
			}
		}
		
}
