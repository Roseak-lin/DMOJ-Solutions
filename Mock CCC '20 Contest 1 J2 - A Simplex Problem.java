import java.util.Scanner;

public class J2_2020 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int c = in.nextInt();
		int m = in.nextInt();
		int max = in.nextInt();
		
		if (c > m) {
			System.out.println(c * max);
		} else {
			System.out.println(m * max);
		}
		

	}
}