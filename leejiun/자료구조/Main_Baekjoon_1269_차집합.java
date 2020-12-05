package algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_Baekjoon_1269_차집합{
	static final int MAX = 100000000;// 최대 원소의 갯수
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		// 두 배열의 크기 입력 (input: 1'st line)
		int aSize = Integer.parseInt(st.nextToken());
		int bSize = Integer.parseInt(st.nextToken()); 

		int[] arrA = new int[aSize];
		int[] arrB = new int[bSize];
		
		// A배열 입력(input: 2nd line)
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < aSize; i++) {
			arrA[i] = Integer.parseInt(st.nextToken());
		}
		
		// B배열 입력(input: 3rd line)
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < bSize; i++) {
			arrB[i] = Integer.parseInt(st.nextToken());
		}

		// A-B, B-A 차집합의 각 갯수를 구한다.
		// 합한값을 출력한다.
		System.out.println(getDifferenceSetSize(arrA,arrB,aSize,bSize)+getDifferenceSetSize(arrB,arrA,bSize,aSize));
		
	}// end of main

	/**
	 * name: getDifferenceSetSize
	 * description: 기준 집합과 타겟 집합의 차집합을 구하고, 차집합의 크기를 반환한다.
	 * @param standard_arr: 기준 집합
	 * @param target_arr: 타겟 집합
	 * @param standard_size: 기준 집합의 크기
	 * @param target_size: 타겟 집합의 크기
	 * @return cnt (차집합의 크기)
	 */
	private static int getDifferenceSetSize(int[] standard_arr, int[] target_arr,int standard_size,int target_size) {
		boolean[] contains = new boolean[MAX]; // 차집합의 원소임을 표시하는 배열
		int cnt = 0; //차집합의 크기를 세어줄 변수
		
		// 1. 기준 집합(standard_arr)의 원소들을 표시한다.
		for (int i = 0; i < standard_size; i++) {
			contains[standard_arr[i]] = true;
			cnt++; // 초기 원소 갯수 세기
		}
		
		// 2. 타겟 집합(target_arr)이 있으면 빼준다.
		for (int i = 0; i < target_size; i++) {
			int targetIndex = target_arr[i];
			if(contains[targetIndex]) {
				contains[targetIndex] = false; // 교집합 원소 빼기
				cnt--; // 그만큼 갯수도 빼주기.
			}
		}
		
		return cnt; // 차집합 갯수 리턴
	}
}// end of class