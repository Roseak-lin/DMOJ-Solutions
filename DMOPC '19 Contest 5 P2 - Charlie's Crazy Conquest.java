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
		boolean def = false;
		for (int i = 0; i < turns; i++) {
			if (def && move[i] == 'A') {
				def = false;
				if (move1[i] == 'D') {
					def = true;
				} else {
					health -= arr2[i];
					if (health <= 0) {
						System.out.println("DEFEAT");
						return;
					}
				}
				continue;
			} else if (def && move[i] == 'D') {
				def = false;
				health1 -= arr2[i - 1];
				if (health1 <= 0) {
					System.out.println("VICTORY");
					return;
				}
				if (move1[i] == 'D') {
					def = true;
					health -= arr1[i];
					if (health <= 0) {
						System.out.println("DEFEAT");
						return;
					}
				}
				continue;
			}
			if (move[i] == 'A' && move1[i] == 'D') {
				def = true;
				health1 -= arr1[i];
			} else if (move[i] == 'D' && move1[i] == 'A') {
				continue;
			} else if (move[i] == 'A' && move1[i] == 'A') {
				health1 -= arr1[i];
				if (health1 <= 0) {
					System.out.println("VICTORY");
					return;
				}
				health -= arr2[i];
				if (health <= 0) {
					System.out.println("DEFEAT");
					return;
				}
			} else {
				def = true;
				health -= arr1[i];
			}
			if (health <= 0) {
				System.out.println("DEFEAT");
				return;
			} else if (health1 <= 0) {
				System.out.println("VICTORY");
				return;
			}
		}
		if (move1[turns - 1] == 'D') {
			health1 -= arr2[turns - 1];
		}
		if (health <= 0) {
			System.out.println("DEFEAT");
			return;
		} else if (health1 <= 0) {
			System.out.println("VICTORY");
			return;
		} else {
			System.out.println("TIE");
		}
	}
}