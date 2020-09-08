import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_jiun {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<int[]> list = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[1] == o2[1])
					return Integer.compare(o1[0], o2[0]);// 종료시간이 같다면, 시작 시간이 빠른 시간부터!!!
				return Integer.compare(o1[1], o2[1]); // 종료시간 오름차순 정렬
			}
		});
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			list.offer(new int[] { Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) });
		} // input end

		int cnt = 0;
		int end = Integer.MIN_VALUE;
		for (int i = 0; i < N; i++) {
			int[] arr = list.poll();
			if(arr[0] >= end) {
				end = arr[1];
				cnt++;
			}
		}
		System.out.println(cnt);
	}
}
