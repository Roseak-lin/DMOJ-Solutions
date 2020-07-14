package other;

import java.util.Scanner;

public class Deforestation {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int pre[] = new int[t + 1];
		pre[1] = in.nextInt();
		for (int i = 2; i < pre.length; i++) {
			pre[i] = in.nextInt() + pre[i - 1];
		}
		in.close();
		int q = in.nextInt();
		for (int i = 0; i < q; i++) {
			int b = in.nextInt(), e = in.nextInt();
			System.out.println(pre[e + 1] - pre[b]);
		}

	}

}
