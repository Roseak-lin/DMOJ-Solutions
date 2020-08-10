package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class House_Of_Cards {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s = new StringTokenizer(in.readLine());
		int c = Integer.parseInt(s.nextToken()), w = Integer.parseInt(s.nextToken());
		s = new StringTokenizer(in.readLine());
		long arr[] = new long[c];
		for (int i = 0; i < c; i++) {
			arr[i] = Long.parseLong(s.nextToken());
		}
		Arrays.parallelSort(arr);
		Stack<Long> stack = new Stack<Long>();
		for (int i = arr.length - 1; i > -1; i--) {
			if (stack.size() == 0) {
				stack.push(arr[i]);
			} else {
				if (stack.peek() >= arr[i] + w) {
					stack.push(arr[i]);
				}
			}
		}

		System.out.println(stack.size());

	}
}