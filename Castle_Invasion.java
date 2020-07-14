package other;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;


public class Castle_Invasion {

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int s = in.nextInt();
		long x[] = new long[s];
		long y[] = new long[s];
		boolean bad = false;
		long max = 0;
		long lx = 0, ly = 0;
		for (int i = 0; i < s; i++) {
			x[i] = in.nextInt();
		}
		for (int i = 0; i < s; i++) {
			y[i] = in.nextInt();
			
		}
		
		sort(x);
		sort(y);
		if (x[s-1] != y[s-1]) {
			bad = true;
		}
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				if (bad) {
					break;
				}
				max += Math.min(x[i], y[j]);
			}
		}

		if (bad) {
			System.out.println(-1);
		} else {
			System.out.println(max);
		}

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
	
	static long[] sort(long[] x) {
		int n = x.length;
		if (n < 2) {
			return x;
		}
		long[] left = Arrays.copyOfRange(x, 0, n / 2);
		long[] right = Arrays.copyOfRange(x, n / 2, n);
		long[] sortedLeft = sort(left);
		long[] sortedRight = sort(right);
		return merge(sortedLeft, sortedRight, n);
	}

	static long[] merge(long[] sortedLeft, long[] sortedRight, int n) {
		long[] result = new long[n];
		int l = 0;
		int r = 0;

		for (int i = 0; i < n; i++) {
			if (l < sortedLeft.length && (r >= sortedRight.length || sortedLeft[l] < sortedRight[r])) {
				result[i] = (int) sortedLeft[l];
				l++;
			} else {
				result[i] = (int) sortedRight[r];
				r++;
			}
		}
		return result;
	}
}
