

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 
 * 10진수를 입력받아 8진수로 출력. 
 * 입력 정수: int 범위
 *
 */
public class Main_codeup_1031 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		System.out.printf("%o",N);
	}
}
