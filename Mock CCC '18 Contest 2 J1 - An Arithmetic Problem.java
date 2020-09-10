import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
		
		int a = in.nextInt();
		String fill = in.next();
		int b = in.nextInt();
		String fill1 = in.next();
		int c = in.nextInt();
		
		if ((a == 9 || b == 9) && c <= 9) System.out.println("False");
		else if (a + b == c) System.out.println("True");
		else System.out.println("False");
    }
}