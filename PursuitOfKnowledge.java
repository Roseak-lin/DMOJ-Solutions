package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class PursuitOfKnowledge {
	static ArrayList<Integer> arr[];
	static int dp[][] = new int[1500][1500];

	public static void main(String[] args) throws IOException {
		FastReader in = new FastReader();
		int n = in.nextInt(), m = in.nextInt(), t = in.nextInt();
		arr = new ArrayList[n + 1];

		for (int i = 0; i <= n; i++) {
			arr[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < m; i++) {
			int a = in.nextInt(), b = in.nextInt();
			arr[a].add(b);
		}
		int tests = in.nextInt();
		outer: for (int i = 1; i <= n; i++) {
			LinkedList<int[]> q = new LinkedList<int[]>();
			for (int j : arr[i]) {
				q.add(new int[] { j, t });
			}

			boolean visited[] = new boolean[n + 1];
			while (!q.isEmpty()) {
				int curr[] = q.poll();
				
				if (visited[curr[0]]) {
					continue;
				} else {
					dp[i][curr[0]] = curr[1];
					visited[curr[0]] = true;
					for (int j : arr[curr[0]]) {
						q.add(new int[] { j, t + curr[1] });
					}
				}
			}
		}

		for (int i = 0; i < tests; i++) {
			int from = in.nextInt(), to = in.nextInt();
			System.out.println(dp[from][to] == 0 ? "Not enough hallways!" : dp[from][to]);
		}

	}
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine().trim());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String readLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

}
