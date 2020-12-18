
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main_Baekjoon_2164_카드2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Queue<Integer> q = new LinkedList<Integer>();
        int card = 0;

        // 1. 큐에 카드 넣기
        // 카드는 1부터 N까지 N개가 있다.
        while(card++ < N){
            q.add(card);
        }

        // 2. 규칙 수행
        while(q.size() > 1) {
                q.poll();// 규칙1 수행
                q.add(q.poll());// 규칙2 수행
        }

        // 3. 남은 카드가 1장일 때
        System.out.println(q.poll());// 카드번호 출력

    }// end of main
}// end of class
