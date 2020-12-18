

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * <문제>
 * 정수 1개를 입력받아 
 * 부호를 바꾸어 출력
 */
public class Main_codeup_1040 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long num = -Long.parseLong(br.readLine());// -로 반대부호 붙이기
		System.out.println(num);
	}
}
