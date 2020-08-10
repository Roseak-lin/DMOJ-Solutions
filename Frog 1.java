package other;

import java.util.Scanner;

public class Frog_1 {
	static int dp[];
	static int arr[];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		arr = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = in.nextInt();
		}
		dp = new int[n];
		dp[0] = 0;
		dp[1] = Math.abs(arr[0] - arr[1]);

//		 Bottom Up

		dp[1] = Math.abs(arr[1] - arr[0]);
		for (int i = 2; i < n; i++) {
			dp[i] = Math.abs(Math.min(dp[i - 1] + Math.abs(arr[i] - arr[i - 1]), dp[i - 2] + Math.abs(arr[i] - arr[i - 2])));
		}
		System.out.println(dp[n - 1]);
	}

}
