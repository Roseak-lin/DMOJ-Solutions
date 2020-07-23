import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class DMOPC_13_C3P3 {
	static HashMap<Integer, String> m = new HashMap<Integer, String>();

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		while (n-- != 0) {
			String temp = in.next();
			int a = in.nextInt();
			if (m.containsKey(a))
				continue;
			m.put(a, temp);
		}

		ArrayList<Integer> val = new ArrayList<Integer>(m.keySet());
		Collections.sort(val);

		int q = in.nextInt();
		outer: while (q-- != 0) {
			int skill = in.nextInt(), diff = in.nextInt(), max = -1;
			String best = "";
			for (int i : val) {
				if (i <= skill + diff && i >= skill) {
					if (!best.equals("")) {
						if (Math.abs(i - skill) > Math.abs(max - skill)) {
							best = m.get(i);
							max = diff + i;
						}
					} else {
						best = m.get(i);
						max = diff + i;
					}
				}
				if (i > skill + diff) {
					break;
				}
			}
			if (best.equals("")) {
				System.out.println("No suitable teacher!");
			} else {
				System.out.println(best);
			}
		}

	}

}