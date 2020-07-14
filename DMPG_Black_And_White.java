package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class DMPG_Black_And_White {

	public static void main(String[] args) throws IOException {
		FastReader in = new FastReader();
		int g = in.nextInt();
		int moves = in.nextInt();
		ArrayList<int[]> black = new ArrayList<int[]>();
		ArrayList<int[]> white = new ArrayList<int[]>();
		
		for (int i = 0; i < g; i++) {
			
		}
		
		for (int i = 0; i < moves; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			int w = in.nextInt();
			int h = in.nextInt();
		}
		int count = 0;
		
		System.out.println(count);
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
					st = new StringTokenizer(br.readLine());
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

		String nextLine() {
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
