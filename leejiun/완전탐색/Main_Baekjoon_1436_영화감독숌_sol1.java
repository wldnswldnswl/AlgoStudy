import java.util.Scanner;

//https://www.acmicpc.net/problem/1436
public class Main_Baekjoon_1436_영화감독숌_sol1 {
	public static void main(String[] args) {
		Scanner sc = new  Scanner(System.in);
		int N = sc.nextInt();
		int candiate = 666;
		int seriesCount = 1;
		
		while(true) {
			if((candiate+"").contains("666")) {
				if(N == seriesCount) {
					System.out.println(candiate);
					return;
				}else {
					seriesCount++;
				}
			}
			candiate++;
		}
	}
}
