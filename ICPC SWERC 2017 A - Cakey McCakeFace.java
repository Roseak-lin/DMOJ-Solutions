import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class ICPC_2017_A {
	static HashMap<Long, Long> map = new HashMap<Long, Long>();
	static long t1[] = new long[2001], t2[] = new long[2001], max = -1, index = Long.MAX_VALUE;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(in.readLine()), m = Integer.parseInt(in.readLine());
		StringTokenizer s = new StringTokenizer(in.readLine());
		for (int i = 0; i < n; ++i) {
			t1[i] = Integer.parseInt(s.nextToken());
		}
		s = new StringTokenizer(in.readLine());
		for (int i = 0; i < m; ++i) {
			t2[i] = Integer.parseInt(s.nextToken());
			for (int j = 0; j < n; j++) {
				long k = t2[i] - t1[j];
				if (k < 0) {
					continue;
				}
				if (map.containsKey(k)) {
					map.put(k, map.get(k) + 1);
				} else {
					map.put(k, (long) 1);
				}
			}

		}
		for (long i : map.keySet()) {
			if (map.get(i) > max) {
				index = i;
				max = map.get(i);
			}
			if (map.get(i) == max && i < index) {
				index = i;
				max = map.get(i);
			}
		}
		System.out.println(index == Long.MAX_VALUE ? 0 : index);
	}

}