// https://www.acmicpc.net/problem/16967

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_16967_배열복원하기 {

    public static void main(String[] args) throws IOException {
        // ---input start---
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        int len_h = H+X;
        int len_w = W+Y;

        int[][] B = new int[1000][1000];
        int[][] A = new int[1000][1000];

        for (int i = 0; i < len_h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < len_w; j++) {
                B[i][j] = Integer.parseInt(st.nextToken());
            }
        }// ---- end of input ----

        // 안겹치는 부분
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < W; j++) {
                A[i][j] = B[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < Y; j++) {
                A[i][j] = B[i][j];
            }
        }


        // 겹치는 부분
        for (int i = X; i < H; i++) {
            for (int j = Y; j < W; j++) {
                A[i][j] = B[i][j] - A[i-X][j-Y];
            }
        }

        // 결과 출력
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.printf("%d ",A[i][j]);
            }
            System.out.println();
        }

    }// end of main
}// end of class
