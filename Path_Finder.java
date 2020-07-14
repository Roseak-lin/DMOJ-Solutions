package other;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

public class Path_Finder {
	static ArrayList<Integer> bad[] = new ArrayList[500001];
	static boolean isList[] = new boolean[500001];
	static int m, n;
	static LinkedList<Integer> q = new LinkedList<Integer>();

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		n = in.nextInt();
		m = in.nextInt();
		int b = in.nextInt();

		while (b-- != 0) {
			int y = in.nextInt(), x = in.nextInt();
			if (isList[y]) {
				bad[y].add(x);
			} else {
				isList[y] = true;
				bad[y] = new ArrayList<Integer>();
				bad[y].add(x);
			}
			if (x == n) {
				q.addFirst(y);
				q.addFirst(x);
			} else if (y == 1) {
				q.addFirst(y);
				q.addFirst(x);
			}
		}
		in.close();
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				System.out.print((isList[i] && bad[i].contains(j)) ? '#' : '.');
//			}
//			System.out.println();
//		}
		while (!q.isEmpty()) {
			int y = q.poll(), x = q.poll();
			if (bfs(x, y)) {
				System.out.println("NO");
				System.exit(0);
			}
		}

		System.out.println("YES");
	}

	@SuppressWarnings("unchecked")
	static boolean bfs(int sy, int sx) {
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(sy);
		q.add(sx);
		ArrayList<Integer> visited[] = new ArrayList[m + 1];
		boolean isL[] = new boolean[500001];

		while (!q.isEmpty()) {
			int y = q.poll(), x = q.poll();
//			System.out.println(x + " " + y + " " + bad[y].contains(x));
			if (!isL[y]) {
				visited[y] = new ArrayList<Integer>();
				isL[y] = true;
			}
			if (y <= m && x <= n && y > 0 && x > 0 && isList[y] && bad[y].contains(x) && !visited[y].contains(x)) {
				if (x == 1 || y == m) {
					return true;
				}
				visited[y].add(x);
				q.add(y + 1);
				q.add(x);
				q.add(y + 1);
				q.add(x + 1);
				q.add(y + 1);
				q.add(x - 1);
				q.add(y);
				q.add(x - 1);
				q.add(y - 1);
				q.add(x);
				q.add(y - 1);
				q.add(x - 1);
				q.add(y - 1);
				q.add(x + 1);
			}
		}
		return false;
	}

	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[100000];
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}

}