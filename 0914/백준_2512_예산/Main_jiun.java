import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
// 시간: 408ms
// 시간줄이기
// 1. input bufferedreader로 변경: 164ms
// 2. 이분탐색 => Main2_jiun.java

import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_jiun {

	private static int n;
	private static int[] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine()); // n은 최대 10억. 출력되는 값도 최대 10억이므로 long형 안써도 됨.
		arr = new int[n];
		int sum = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		int total_budget = Integer.parseInt(br.readLine());
		
		Arrays.sort(arr);// 정렬
		int max = 0;
		int i = 0;
		
		// 1. 상한가가 될 기준 인덱스를 정한다.
		for (i = n-1; i >= 0; i--) {
			sum = getSum(i,arr[i]); // 0~i-1는 그대로,i+1~n-1은 arr[i+1]을 상한가로 만들었을 때의 합. 
			if(total_budget >= sum) {// 합이 sum보다 크면 기준값이면 출력하고 종료.
				if(total_budget == sum || i == n-1) { // *) i == n-1을 추가해 런타임에러 해결
					System.out.println(arr[i]);
					return;
				}
				break;
			}
		}

		int tmp_budget = sum;
		int std= arr[i+1]; // 최대 상한가를 정해야 하므로 arr[기준인덱스+1]에서 1씩 뺀다.
		do{
			std -=1; // 1을 뺀값.
			tmp_budget = getSum(i+1,std); // 새로 구한 상한가로 합한 총 예산
		}while(tmp_budget>total_budget);// 상한가로 만든 예산이 기존 예산과 같거나 작아지면 break;
		
		System.out.println(std); // 정한 상한가(=arr중 가장 큰 값) 출력

	}

	/** 임의의 상한가(value)를 반영한 arr(각 지방의 요청예산)들의 합을 구하는 함수.
	 * idx ~ n까지 임의의 상한가(value)를 적용한다.
	 * */
	private static int getSum(int idx, int value) {
		int sum = 0;
		for (int i = 0; i < idx; i++) {
			sum += arr[i];
		}
		
		for (int i = idx; i < n; i++) {
			sum+=value;
		}
		return sum;
	}

}
