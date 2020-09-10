import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		
		char[][] c = new char[a][b];
		
		for (int i = 0; i < a; i++) {
		    char[] temp = in.next().toCharArray();
		    for (int j = 0; j < b; j++) {
		        c[i][j] = temp[j];
		    }
		}
		for (int x = 0; x < 100; x++) {
		for (int i = 0; i < a - 1; i++) {
		    for (int j = 0; j < b; j++) {
		        if (c[i][j] == 'o' && c[i + 1][j] == '.') {
		            c[i][j] = '.';
		            c[i + 1][j] = 'o';
		        }
		    }
		}
		}
		for (int i = 0; i < a; i++) {
		    for (int j = 0; j < b; j++) {
		        System.out.print(c[i][j]);
		    }
		    System.out.println("");
		}
    }
}