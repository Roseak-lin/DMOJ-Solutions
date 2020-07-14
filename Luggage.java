package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Luggage {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s = new StringTokenizer(in.readLine());
		int l = Integer.parseInt(s.nextToken()), k = Integer.parseInt(s.nextToken());
		s = new StringTokenizer(in.readLine());
		int arr[] = new int[l];
		for (int i = 0; i < l; i++) {
			arr[i] = Integer.parseInt(s.nextToken());
		}
		Arrays.parallelSort(arr);
		int i = 0, j = l - 1;

		while (i < j) {
			if (arr[j] - arr[i] <= k) {
				System.out.println((j + 1) - i);
				System.exit(0);
			} else {
				if (arr[j] - arr[j - 1] > Math.abs(arr[i] - arr[i + 1])) {
					j--;
				} else {
					i++;
				}
			}
		}
		System.out.println((j + 1) - i);
	}
}