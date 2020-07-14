package other;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.LinkedList;

public class DMOPC_13_P4_AFK {

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int tests = Integer.parseInt(in.readLine());
		outer: for (int i = 0; i < tests; i++) {
			String limits[] = in.readLine().split(" ");
			int n1 = Integer.parseInt(limits[0]);
			int n2 = Integer.parseInt(limits[1]);
			boolean visited[][] = new boolean[n2][n1];
			char arr[][] = new char[n2][n1];
			LinkedList<int[]> queue = new LinkedList<int[]>();
			for (int j = 0; j < n2; j++) {
				char line[] = in.readLine().toCharArray();
				for (int x = 0; x < n1; x++) {
					arr[j][x] = line[x];
					if (arr[j][x] == 'C') {
						queue.addLast(new int[] { x, j, 0 });
					}
				}
			}

			while (!queue.isEmpty()) {
				int curr[] = queue.removeFirst();
				if (curr[0] < 0 || curr[0] >= n1 || curr[1] < 0 || curr[1] >= n2 || arr[curr[1]][curr[0]] == 'X'
						|| visited[curr[1]][curr[0]]) {
					continue;
				}
				visited[curr[1]][curr[0]] = true;
				if (arr[curr[1]][curr[0]] == 'W') {
					System.out.println(curr[2] < 60 ? curr[2] : "#notworth");
					continue outer;
				}
				queue.addLast(new int[] { curr[0] + 1, curr[1], curr[2] + 1 });
				queue.addLast(new int[] { curr[0] - 1, curr[1], curr[2] + 1 });
				queue.addLast(new int[] { curr[0], curr[1] + 1, curr[2] + 1 });
				queue.addLast(new int[] { curr[0], curr[1] - 1, curr[2] + 1 });
			}
			System.out.println("#notworth");
		}
		in.close();
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
			byte[] buf = new byte[64]; // line length
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