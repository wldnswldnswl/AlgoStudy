// https://www.acmicpc.net/problem/8061
// SOL) BFS로 정점 1에서부터 정점 0까지의 최단 거리를 구한다.
// i:행, j:열
// 가장 가까운 white와의 거리

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_Baekjoon_8061_Bitmap {

    private static int[][] visit;
    private static int H, W;
    private static int[][] bitmap = new int[182][182];
    private static int[] dr = {-1,0,1,0};
    private static int[] dc = {0,1,0,-1};
    private static Queue<Node> q;

    public static void main(String[] args) throws IOException {
        // ---input start---
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        visit = new int[H][W];

        for (int i = 0; i < H; i++) {
            String input = br.readLine();
            for (int j = 0; j < W; j++) {
                bitmap[i][j] = input.charAt(j)-'0'; // char -> int
            }
        }// input end
        q = new LinkedList<>();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if(bitmap[i][j] == 1){//정점 1을 저장 (정점 1에서 정점0 까지의 최단거리를 구하기 위함)
                    visit[i][j] = 1;
                    q.offer(new Node(i,j));
                }
            }
        }// input end

        findMinDistance();
        printBitMap();
    }// end of main

    public static class Node{
        int r;
        int c;
        Node(int r, int c){
            this.r = r;
            this.c = c;
        }
    }

    private static void printBitMap() {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(visit[i][j]-1+" ");
            }
            System.out.println();
        }
    }

    // bfs
    // 0인 정점들을 시작으로 그래프 탐색
    private static void findMinDistance() {
        while (!q.isEmpty()) {
            Node node = q.poll();

            //4방 탐색
            for (int d = 0; d < 4; d++) {
                int nr = node.r + dr[d];
                int nc = node.c + dc[d];

                // 방문 할 수 없는 곳이면
                if (nr < 0 || nr >= H || nc < 0 || nc >= W )
                    continue;

                // 방문 할 수 있는 곳이면
                // = 구한 거리가 없고, 정점 0이라면
                if(visit[nr][nc] == 0 && bitmap[nr][nc] == 0){
                    visit[nr][nc] = visit[node.r][node.c]+1;
                    q.offer(new Node(nr,nc)); //새로 4방 탐색할 위치
                }
            }
        }
    }
}// end of class
