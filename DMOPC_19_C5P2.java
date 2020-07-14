package other;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DMOPC_19_Contest_5_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int turns = in.nextInt();
		int health = in.nextInt();
		int health1 = health;
		boolean run = false;
		char move[] = new char[turns];
		char move1[] = new char[turns];
		int arr1[] = new int[turns];
		int arr2[] = new int[turns];

		for (int i = 0; i < turns; i++) {
			move[i] = in.next().charAt(0);
			arr1[i] = in.nextInt();
		}

		for (int i = 0; i < turns; i++) {
			move1[i] = in.next().charAt(0);
			arr2[i] = in.nextInt();
		}

		for (int i = 0; i < arr1.length; i++) {
			if (i != arr1.length - 1 && move1[i] == 'D' && move[i + 1] == 'A') {
				continue;
			}
			if (move[i] == move1[i]) {
				health1 -= arr1[i];
				health -= arr2[i];
			}

			if (i == arr1.length - 1 && move1[i] == 'D') {
				health -= arr2[i];
			}

			if (health <= 0) {
				run = true;
				System.out.println("VICTORY");
				break;
			} else if (health1 <= 0) {
				run = true;
				System.out.println("DEFEAT");
				break;
			}
		}
		if (!run) {
			System.out.println("TIE");
		}
	}
}
