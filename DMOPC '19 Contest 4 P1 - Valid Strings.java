import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class DMOPC_19_P1 {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(in.readLine());

		outer: for (int i = 0; i < num; i++) {
			Stack<Character> stack = new Stack();
			String s = in.readLine();
			for (int j = 0; j < s.length(); j++) {
				if (s.charAt(j) == '(') {
					stack.push('(');
				} else if (s.charAt(j) == ')') {
					if (stack.size() == 0) {
						stack.push('0');
						System.out.println("NO");
						continue outer;
					} else {
						stack.pop();
					}

				}

			}
			if (stack.size() == 0)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}

}