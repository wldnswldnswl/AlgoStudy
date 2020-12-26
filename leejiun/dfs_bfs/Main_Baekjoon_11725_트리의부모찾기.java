import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_Baekjoon_11725_트리의부모찾기 {
    private static boolean[] visit;
    private static ArrayList<Integer>[] tree;
    private static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        tree = new ArrayList[n+1]; // 각 노드에 연결된 노드를 저장할 ArrayList배열
                                                        // ex: tree[1] = {4,6} 
        for (int i = 0; i < n+1; i++) {
            tree[i] = new ArrayList<Integer>();
        }
        parent = new int[n+1]; // 부모 노드 저장 배열
        visit = new boolean[n+1];

        for(int i = 0; i < n-1; i++){
            st = new StringTokenizer(br.readLine());
            int num1 = Integer.parseInt(st.nextToken());
            int num2 = Integer.parseInt(st.nextToken());
            
            tree[num1].add(num2);
            tree[num2].add(num1); //정점 양방향 연결
        }

        dfs(1);//부모노드 찾기
        for (int i = 2; i <= n; i++) {
            System.out.println(parent[i]);
        }
    }// end of main

    private static void dfs(int node) {
        visit[node] = true;
        for (int value: tree[node]) {
            if(!visit[value]){
                parent[value] = node; // 부모 설정
                dfs(value);//자식노드와 연결된 노드 찾기
            }
        }
    }
}//  end of class
