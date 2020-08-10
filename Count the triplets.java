import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

public class Triplets {
	static ArrayList<Integer> arr = new ArrayList<Integer>();
	static byte[] occ = new byte[10000001];
	static int size = 0;

	public static void main(String[] args) throws Exception {
		Reader in = new Reader();
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int t = in.nextInt();
			if (occ[t] == 0) {
				occ[t]++;
				arr.add(t);
				size++;
			} else if (occ[t] == 1) {
				occ[t]++;
			}
		}
		short trip = 0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i != j) {
					if (arr.get(i) + arr.get(j) < 1000001 && occ[arr.get(i) + arr.get(j)] != 0) {
						trip++;
					}
				}
				if (arr.get(i) * 2 < 100001 && occ[arr.get(i)] == 2 && occ[2 * arr.get(i)] != 0) {
					trip++;
				}
			}
		}
		System.out.println(trip == 0 ? -1 : trip / 2);
	}
	static class Reader {
		final private int BUFFER_SIZE = 100000;
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