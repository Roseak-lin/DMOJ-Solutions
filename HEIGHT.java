package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HEIGHT {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}
		int dp[] = new int[n];
		for (int i = 0; i < n; i++) {
			dp[i] = arr[i];
		}
		int max = Integer.MIN_VALUE;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (arr[i] > arr[j]) {
//					System.out.println(arr[i] + " " + arr[j]);
					dp[i] = Math.max(dp[i], dp[j] + arr[i]);
				}
			}
			max = Math.max(dp[i], max);
		}
		System.out.println(max);
	}

}