import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

import java.util.StringTokenizer;
// 128ms
public class Main_3_jiun {
	private static int n;
	private static int[] arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		arr = new int[n];
		
		int sum = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
			sum+=arr[i];
		}
		
		int total_budget = Integer.parseInt(br.readLine());// input end
		Arrays.sort(arr);//오름차순 정렬
		
   
		// 1. 작은 예산요청부터 수용하며 상한가가 필요한 지점을 찾는다.
		int i = 0;
		for (i = 0; i < n; i++) {
			if(arr[i]*(n-i) < total_budget) {//해당 지방의 예산을 n-i개의 지방에 동일하게 적용했을때 수용가능한지 검사.
				total_budget -= arr[i]; // 전체 예산에서 해당 예산을 빼어 다음 계산에서 제외한다.
			}
			else
				break;
		}
		if(n-i==0) System.out.println(arr[n-1]);
		else System.out.println(total_budget/(n-i)); // 2. 상한가 지정 (남은 예산을 상한가를 지정해야할 지방의 갯수로 나누어준다.)
	}// end of main
}// end of class
