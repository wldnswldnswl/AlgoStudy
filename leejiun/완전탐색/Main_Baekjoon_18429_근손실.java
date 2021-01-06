import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
//https://www.acmicpc.net/problem/18429

/***
 * 1. 순열 구하기
 *    1.1. 현재 순서 선택
 *    1.2. 해당 순서일 때 중량이 500보다 작아지면 종료
 *    1.3. 모두 방문 했으면 ans(경우의 수)++
 */
public class Main_Baekjoon_18429_근손실 {
    static int[] kit; // 운동 루틴 키트
    static int K,N,ans = 0; // k: 매일 감소하는 중량, N: 운동 루틴 갯수, ans: 가능한 경우의 수
    static boolean[] visit; // 키트 사용 여부

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        kit = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            kit[i] = Integer.parseInt(st.nextToken());
        } // input end

        perm(kit, 0, N);

        System.out.println(ans);
    }// end of class

    private static void perm(int[] arr, int depth, int n) {
        if(depth == n){
            int allPower = 500;
            for (int i = 0; i < n; i++) {
                int amountOfPower = arr[i];
                if(allPower + amountOfPower - K >= 500)
                    allPower = allPower + amountOfPower - K;
                else return;//이용할 수 없는 루틴
            }
            ans++;
            return;
        }

        for (int i = depth; i < N; i++) {
            swap(kit, depth, i);
            perm(kit, depth+1,n);
            swap(kit,depth,i);
        }
    }

    private static void swap(int[] arr, int depth, int i){
        int tmp = arr[depth];
        arr[depth] = arr[i];
        arr[i] = tmp;
    }
}//end of main
