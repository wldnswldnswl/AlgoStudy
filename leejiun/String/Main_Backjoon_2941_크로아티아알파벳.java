import java.io.BufferedReader;
import java.io.InputStreamReader;

// https://www.acmicpc.net/problem/2941\
/**
 * 아이디어: 변환 무ㅏ를 차으며 replace("창으
 *
 */
public class Main_Backjoon_2941_크로아티아알파벳 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] dic = {"dz=","d-","lj","nj","s=","z=","c=","c-"};
		int dic_size = dic.length;
		int cnt = 0;

		while(input.length() > 0) {//
			for (int i = 0; i < dic_size; i++) {
				int startIndex = input.indexOf(dic[i]);
				if(startIndex != -1) {
					input = input.replaceFirst(dic[i], "&");
					cnt++;
					break;
				}
				if(i == dic_size - 1 && startIndex == -1) {
					input = input.replace("&", "");
					cnt += input.length();
					input = "";
				}
			}
			
		}
		
		System.out.println(cnt);
			

	}

}
