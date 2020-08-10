package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Setnja {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in), 1 << 16);
		String s = in.readLine();
		in.close();

		BigInteger a = BigInteger.ONE;
		BigInteger b = BigInteger.ZERO;

		for (int i = s.length() - 1; i > -1; i--) {
			BigInteger n1 = BigInteger.ZERO, n2 = BigInteger.ZERO;
			if (s.charAt(i) == '*' || s.charAt(i) == 'L') {
				n1 = n1.add(a);
				n1 = n1.add(a);
				n2 = n2.add(b);
			}
			if (s.charAt(i) == '*' || s.charAt(i) == 'R') {
				n1 = n1.add(a);
				n1 = n1.add(a);
				n2 = n2.add(a);
				n2 = n2.add(b);
			}
			if (s.charAt(i) == '*' || s.charAt(i) == 'P') {
				n1 = n1.add(a);
				n2 = n2.add(b);
			}
			a = n1;
			b = n2;
		}

		System.out.println(a.add(b));
	}

}
