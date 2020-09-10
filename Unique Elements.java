import java.io.*;
import java.util.*;

public class Main {
    static Set<String> s = new HashSet<String>();
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        
        while (n-- > 0) {
            s.add(in.readLine());
        }
        System.out.println(s.size());
    }
}