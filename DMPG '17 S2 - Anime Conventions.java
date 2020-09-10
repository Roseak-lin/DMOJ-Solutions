import java.io.DataInputStream;
import java.util.StringTokenizer;

public class Anime_Conventions {
	static int parent[] = new int[100001], rank[] = new int[100001];

	public static void main(String[] args) throws Exception {
		
		DataInputStream in = new DataInputStream(System.in);
		StringTokenizer s = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(s.nextToken()), m = Integer.parseInt(s.nextToken());
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		while (m-- != 0) {
			s = new StringTokenizer(in.readLine());
			if (s.nextToken().charAt(0) == 'A') {
				union(Integer.parseInt(s.nextToken()), Integer.parseInt(s.nextToken()));
			} else {
				if (find(Integer.parseInt(s.nextToken())) == find(Integer.parseInt(s.nextToken()))) {
					System.out.println("Y");
				} else {
					System.out.println("N");
				}
			}
		}
	}

	static void union(int x, int y) {
		int xr = find(x), yr = find(y);
		if (xr == yr) {
			return;
		} else if (rank[xr] < rank[yr]) {
			parent[xr] = parent[yr];
		} else if (rank[yr] < rank[xr]) {
			parent[yr] = parent[xr];
		} else {
			parent[yr] = xr;
			rank[xr]++;
		}
	}

	static int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}

}