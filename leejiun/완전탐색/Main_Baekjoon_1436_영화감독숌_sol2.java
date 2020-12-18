import java.util.Scanner;

//https://www.acmicpc.net/problem/1436
public class Main_Baekjoon_1436_영화감독숌_sol2 {
	public static void main(String[] args) {
		Scanner sc = new  Scanner(System.in);
		int N = sc.nextInt();
		int candiate = 665;
		int seriesCount = 0,tmp=1;
		//  2666799
		while(N != seriesCount) {
			tmp = candiate;

			while(tmp != 0) {
				if(tmp % 1000 == 666) {
					seriesCount++;
					break;
				}
				tmp /= 10;
			}
			candiate++;
		}
		
		System.out.println(candiate-1);
	}
}
