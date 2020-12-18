// https://www.acmicpc.net/problem/1018
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_Baekjoon_1018_체스판 {
    private static int min = 64, N, M;
    private static char[][] map;
    private static char[] color={'W','B'};

    public static void main(String[] args) throws IOException {
        // ---input start---
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());//세로
        M = Integer.parseInt(st.nextToken());//가로

        map = new char[N][M];

        for (int i = 0; i < N; i++) {// map입력
            map[i] = br.readLine().toCharArray();
        }
        // ---input end---
        
        // 가능한 8*8 범위에 모두 놓아보기
        for (int i = 0; i < N-7; i++) {
            for (int j = 0; j < M-7; j++) {
                int white = fill(i,j);

                // min을 하얀색으로 시작된 체스판인경우, 검정색으로 시작된 체스판인경우 중 최솟값으로 갱신
                //검정색을 먼저 칠하는 경우는 (64 - 하얀색으로 칠했을 때의 새로 칠한 갯수)
                min = Math.min(min,Math.min(white,64-white));
            }
        }

        // 최솟값 출력
        System.out.println(min);

    }// end of main

    /** 하얀색을 시작으로하는 체스판을 그려보는 함수
     *  return 다시 칠한 칸의 갯수
     * */
    private static int fill(int r, int c) {
        int cnt = 0;
        int idx = 0;
        char currentColor = color[idx];// 첫번째 지점을 하얀색깔로 칠했을 때

        int end_r = r + 8;
        int end_c = c + 8;

        for (int i = r; i < end_r; i++) {
            for (int j = c; j < end_c; j++) {
                
                // 지정된 색깔로 칠해지지 않았으면 
                // 갯수 세어주기
                if(map[i][j] != currentColor){
                    cnt++;
                }

                currentColor = color[(++idx)%2];//다음 색깔 검사
            }//row
            currentColor = color[(++idx)%2];//다음줄로 가면 시작 색깔 바꾸기
        }//col

        return cnt;
    }// end of fill
}// end of class
