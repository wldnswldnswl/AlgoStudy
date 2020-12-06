

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * <문제>
 * 문자를 입력받아 
 * 10진수로 출력 
 */
public class Main_codeup_1036 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char ch = br.readLine().charAt(0); // 문자 입력
		
		System.out.println(ch-'\0'); // 아스키 코드로 변환
		//System.out.println('1'-'0'); // int형으로 변환
	}
}
