import java.io.*;
import java.util.*;

public class Sandwich {
	public static void main(String[] args) throws Exception {
		DataInputStream in = new DataInputStream(System.in);
		int layers = Integer.parseInt(in.readLine());
		String s = in.readLine();
		in.close();
		
		for (int i = layers - 1; i >= 0; i--) {
		    if (s.charAt(i) == '1') {
		        System.out.println(i + 1);
		    }
		}
		for (int i = 1; i <= layers; i++) {
		    if (s.charAt(i-1) == '0')
		        System.out.println(i);
		}
		
	}
}