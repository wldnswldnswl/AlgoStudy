package _20_10_1st.Baekjoon_1753_최단경로;

// https://www.acmicpc.net/problem/1753
// 메모리 초과 해결방법: 인접리스트로 해결 && pq로 성능개선
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_jiun {
	private static int[] distance;
	private static boolean[] visit;
	private static int e, v, s;
	private static ArrayList<Node>[] graph;
	static final int INF = Integer.MAX_VALUE;

	static class Node implements Comparable<Node>{
		int idx, w;

		public Node(int idx, int w) {
			this.idx = idx;
			this.w = w;
		}

		@Override
		public int compareTo(Node o) {
			return Integer.compare(this.w, o.w); // 가중치가 적은순으로 정렬
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken()); // 정점갯수
		e = Integer.parseInt(st.nextToken()); // 간선갯수
		s = Integer.parseInt(br.readLine()); // 시작점
		graph = new ArrayList[v + 1];

		for (int i = 1; i < v+1; i++) {
			graph[i] = new ArrayList<Node>(); // 정점생성
		}
		for (int i = 0; i < e; i++) {// 간선,정점,가중치 저장
			st = new StringTokenizer(br.readLine());
			graph[Integer.parseInt(st.nextToken())]
					.add(new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}

		distance = new int[v + 1];// ** N까지의 거리를 저장하는 DISTANCE 배열 생성
		for (int i = 0; i < v + 1; i++) {
			distance[i] = INF; // ** 후 INF로 초기화
		}
		다익스트라(s);
		// 출력
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < v + 1; i++) {
			if (distance[i] == INF)
				sb.append("INF").append("\n");
			else
				sb.append(distance[i]).append("\n");
		}
		System.out.println(sb);
	}// end of main

	private static void 다익스트라(int cur) {
		PriorityQueue<Node> queue = new PriorityQueue<>();
		boolean[] visit = new boolean[v + 1];

		queue.add(new Node(cur, 0));
		distance[cur] = 0;

		while (!queue.isEmpty()) {
			Node curNode = queue.poll();
			int end = curNode.idx;

			if (visit[end])
				continue;
			visit[end] = true; // 인접 최소 정점 방문 표시

			for (Node node : graph[end]) {
				if (distance[node.idx] > distance[end] + node.w) {
					distance[node.idx] = distance[end] + node.w;
					queue.add(new Node(node.idx, distance[node.idx]));
				}
			}

		}
	}

}// end of class
