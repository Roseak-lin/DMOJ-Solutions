import java.util.*;
import java.io.*;

public class Other_Coding_Contests {

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int acorns = in.nextInt();
		int ops = in.nextInt();
		int arr[] = new int[acorns];
		for (int i = 0; i < acorns; i++) {
			arr[i] = in.nextInt();
		}

		for (int i = 0; i < ops; i++) {
			int op = in.nextInt();
			int begin = in.nextInt() - 1;
			int end = in.nextInt() - 1;
			if (op == 1) {
				for (int j = begin; j < end; j++) {
					for (int x = begin; x < end; x++) {
						if (arr[x] > arr[x + 1]) {
							int temp = arr[x];
							arr[x] = arr[x + 1];
							arr[x + 1] = temp;
						}
					}
				}
			} else {
				for (int j = begin; j < end; j++) {
					for (int x = begin; x < end; x++) {
						if (arr[x] < arr[x + 1]) {
							int temp = arr[x];
							arr[x] = arr[x + 1];
							arr[x + 1] = temp;
						}
					}
				}
			}
		}
		for (int i = 0; i < arr.length; i++) {
			if (i != arr.length - 1)
			System.out.print(arr[i] + " ");
			else 
				System.out.println(arr[i]);
		}
	}

	static int[] sort(int[] arr) {
		int n = arr.length;
		if (n < 2) {
			return arr;
		}
		int left[] = Arrays.copyOfRange(arr, 0, n / 2);
		int right[] = Arrays.copyOfRange(arr, n / 2, n);
		int[] sortedLeft = sort(left);
		int[] sortedRight = sort(right);
		return merge(sortedLeft, sortedRight, n);
	}

	static int[] merge(int[] left, int right[], int n) {
		int result[] = new int[n];
		int l = 0;
		int r = 0;

		for (int i = 0; i < n; i++) {
			if (l < left.length && (r >= right.length || left[l] < right[r])) {
				result[i] = left[l];
				l++;
			} else {
				result[i] = right[r];
				r++;
			}
		}
		return result;
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