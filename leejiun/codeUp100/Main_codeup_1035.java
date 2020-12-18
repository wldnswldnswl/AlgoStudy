

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * <문제>
 * 16진수 정수를 입력받아 
 * 8진수로 출력 
 */
public class Main_codeup_1035 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine(),16); // 16진수 -> 10진수
		String octalNum = Integer.toOctalString(num); // 10진수 -> 8진수
		
		System.out.println(octalNum);
	}
}
