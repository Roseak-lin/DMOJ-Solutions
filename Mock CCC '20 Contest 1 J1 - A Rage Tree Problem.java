import java.util.Arrays;
import java.util.Scanner;

public class J1_2020 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int arr[] = new int[4];
		for (int i = 0; i < 4; i++) {
			arr[i] = in.nextInt();
		}
		Arrays.sort(arr);
		System.out.println(arr[0] + "\n" + arr[3]);
	}

}