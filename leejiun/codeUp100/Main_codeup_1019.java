import java.util.*;
import java.io.*;
public class Main_codeup_1019
{
	public static void main(String[] args) throws Exception{
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   StringTokenizer st = new StringTokenizer(br.readLine(),".");
	   System.out.printf("%04d.%02d.%02d", Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
	   
	}
}