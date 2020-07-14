package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TicTacMoe {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		char grid[][] = new char[3][];
		for (int i = 0; i < 3; ++i) {
			grid[i] = in.readLine().toCharArray();
		}
		int t = 0, g = 0;
		for (int i = 0; i < 3; i++) {
			if (grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X') {
				t++;
			} else if (grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O') {
				g++;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X') {
				t++;
			} else if (grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O') {
				g++;
			}
		}

		if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') {
			System.out.println("Timothy");
			System.exit(0);
		} else if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') {
			System.out.println("Griffy");
			System.exit(0);
		}

		if (grid[0][2] == 'X' && grid[2][0] == 'X' && grid[1][1] == 'X') {
			System.out.println("Timothy");
			System.exit(0);
		} else if (grid[0][2] == 'O' && grid[2][0] == 'O' && grid[1][1] == 'O') {
			System.out.println("Griffy");
			System.exit(0);
		}
		if (t == 0 && g == 0) {
			System.out.println("Tie");
		} else if (g > 0 && t > 0) {
			System.out.println("Error, redo");
		} else if (t > g) {
			System.out.println("Timothy");
		} else if (t < g) {
			System.out.println("Griffy");
		}

	}

}
