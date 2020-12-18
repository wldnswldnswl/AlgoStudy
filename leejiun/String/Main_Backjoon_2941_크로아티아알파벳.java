import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

// https://www.acmicpc.net/problem/2941
public class Main_Backjoon_2941_크로아티아알파벳 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] dic = {"dz=","d-","lj","nj","s=","z=","c=","c-"};
		int dic_size = dic.length;
		int cnt = 0;

			for (int i = 0; i < dic_size; i++) {
					input = input.replace(dic[i], "&");
			}
		
		System.out.println(input.length());
			

	}

}
