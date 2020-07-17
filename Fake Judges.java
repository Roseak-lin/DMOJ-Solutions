package other;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;

public class Fake_Judges {
	static HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
	static LinkedList<Integer> query = new LinkedList<Integer>();
	static ArrayList<Integer> nums = new ArrayList<Integer>();
	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int n = in.nextInt(), q = in.nextInt();
		int arr[] = new int[n + 1], diff[] = new int[n + 2];
		long pre[] = new long[n + 2];
		for (int i = 0; i < n; i++) {
			nums.add(in.nextInt());
		}

		for (int i = 0; i < q; i++) {
			int b = in.nextInt(), e = in.nextInt();
			query.add(b);
			query.add(e);
			diff[b]++;
			diff[e + 1]--;
		}
		
		for (int i = 1; i <= n; i++) {
			arr[i] = diff[i] + arr[i - 1];
			map.put(i, arr[i]);
		}
		ArrayList<Integer> freq = new ArrayList<Integer>(map.keySet());
		Collections.sort(freq, new Comparator<Integer>() {
			public int compare (Integer o1, Integer o2) {
				return map.get(o1) - map.get(o2);
			}
		});
		Collections.sort(nums);
		for (int i = 1; i <= n; i++) {
			arr[freq.get(freq.size() - i)] = nums.get(i - 1);
		}
		pre[0] = 0;
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + arr[i];
		}
		long sum = 0;
		while (!query.isEmpty()) {
			int b = query.poll(), e = query.poll();
			sum += pre[e] - pre[b - 1];
		}
		System.out.println(sum);
		
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
			byte[] buf = new byte[100001];
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