

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * <문제>
 * 8진수 정수를 입력받아 
 * 10진수로 출력 
 * 
 * <풀이방법>
 * 1. String으로 입력받는다.
 * 2. int len = 입력 문자열의 길이
 * 	  int num = 0
 * 3. 앞 글자 부터 문자열을 순회
 * 	  3.1. num += 현재 문자.toInt * 8의 (len - i - 1) 제곱
 * 4. num(최종 10진수) 출력
 */
public class Main_codeup_1034 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String octalNum = br.readLine(); // 1
		int len = octalNum.length(); // 2
		int num = 0;
		
		for (int i = 0; i < len; i++) {// 3
			int currentNum = octalNum.charAt(i) -'0';  // 현재 문자를 int형으로 변환
			int square = len - i - 1; // 제곱수 구하기
			num += currentNum * Math.pow(8, square); // 현재 문자 변환결과를 최종 10진수에 더하기.
		}
		System.out.println(num);
	}
}
