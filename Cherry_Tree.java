package other;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

public class Cherry_Tree {
	static ArrayList<long[]> arr[];

	public static void main(String[] args) throws Exception {
		Reader in = new Reader();
		long nodes = in.nextLong(), min = in.nextLong(), max = in.nextLong();
		long cherries[] = new long[(int) (nodes + 1)];
		for (int i = 1; i <= nodes; i++) {
			cherries[i] = in.nextLong();
		}
		arr = new ArrayList[(int) (nodes + 1)];
		for (int i = 0; i <= nodes; i++) {
			arr[i] = new ArrayList<long[]>();
		}

		for (int i = 0; i < nodes - 1; i++) {
			long a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
			arr[(int) a].add(new long[] { b, c });
		}
		int count = 0;
		boolean visited[] = new boolean[(int) (nodes + 1)];
		for (int i = 1; i <= nodes; i++) {
			LinkedList<long[]> q = new LinkedList<long[]>();
			for (long[] x : arr[i]) {
				visited[(int) x[0]] = true;
				q.addLast(new long[] { x[0], x[1] });
			}

			while (!q.isEmpty()) {
				LinkedList<long[]> queue = new LinkedList<long[]>();
				queue.add(q.poll());
//				System.out.println(queue);
				int c = 0, w = 0;
				while (!queue.isEmpty()) {
					long[] temp = queue.poll();
//					System.out.println(temp[0]);
					c += cherries[(int) temp[0]];
					w += temp[1];
					if (temp[1] > max) {
						break;
					}
					for (long x[] : arr[(int) temp[0]]) {
						queue.addLast(new long[] { x[0], x[1] });
					}
				}
				if (c >= min && w <= max) {
					count++;
				}
			}
		}
		System.out.println(count);
	}

	static class Reader {
		final private int BUFFER_SIZE = 1 << 32;
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
			byte[] buf = new byte[128]; // line length
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