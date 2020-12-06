

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 
 * 10진수를 입력받아 16진수 대문자로 출력. 
 * 입력 정수: int 범위
 *
 */
public class Main_codeup_1033 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// sol1.
//		String hexNum = Integer.toHexString(Integer.parseInt(br.readLine())).toUpperCase();
//		System.out.println(hexNum);
		
		// sol2.
		System.out.printf("%X",Integer.parseInt(br.readLine()));
	}
}
