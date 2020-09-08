import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_jiun {
	private static int N,max = Integer.MIN_VALUE;
	private static int[] time, price;
	private static int[] dp;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		time = new int[15];
		price = new int[15];
		dp = new int[15];
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			time[i]=Integer.parseInt(st.nextToken());
			price[i]=Integer.parseInt(st.nextToken());
			dp[i]=-1; // dp[i]: n일까지 얻은 수익
		}
		System.out.println(solve(0));
	}// end of main
	private static int solve(int day) {
		if(day > N) return Integer.MIN_VALUE;
		if(day == N) return 0;
		
		if(dp[day] != -1) return dp[day];
		
		return Math.max(solve(day+1), solve(day+time[day])+price[day]);
	}
}// end of class
