import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int len = 4;
		for(int i = 0; i < str.length(); i++) {
			System.out.print("[");
			System.out.print(str.charAt(i));
			for (int j = 0; j < len; j++) {
				System.out.print("0");
			}
			len--;
			System.out.println("]");
		}
	}
}
