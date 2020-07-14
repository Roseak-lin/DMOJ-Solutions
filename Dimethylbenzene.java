package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Dimethylbenzene {
	static ArrayList<Integer> arr[];

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s = new StringTokenizer(in.readLine());
		int a = Integer.parseInt(s.nextToken());
		int l = Integer.parseInt(s.nextToken());
		if (a < 6) {
			System.out.println("NO");
			in.close();
			System.exit(0);
		}
		arr = new ArrayList[a + 1];
		for (int i = 1; i < arr.length; i++) {
			arr[i] = new ArrayList();
		}

		for (int i = 0; i < l; i++) {
			s = new StringTokenizer(in.readLine());
			int t1 = Integer.parseInt(s.nextToken());
			int t2 = Integer.parseInt(s.nextToken());
			arr[t1].add(t2);
			arr[t2].add(t1);
		}

		for (int i = 1; i < a; i++) {
			dfs(i, i, new boolean[a + 1], 0);
		}
		System.out.println("NO");
	}

	static void dfs(int s, int curr, boolean visited[], int d) {
		for (int i : arr[curr]) {
			if (i == s) {
				if (d + 1 >= 6 && !visited[i]) {
					System.out.println("YES");
					System.exit(0);
				}
			} else if (visited[i]) {
				continue;
			}
			visited[i] = true;
			dfs(s, i, visited, d + 1);

		}
	}

}
