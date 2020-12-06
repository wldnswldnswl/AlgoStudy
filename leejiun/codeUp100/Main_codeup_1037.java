

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * <문제>
 * 10진수를 입력받아 
 * 아스키 문자로 출력 
 */
public class Main_codeup_1037 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine()); // 숫자 입력
		
		System.out.println((char)num); // 아스키 문자로 변환
	}
}
