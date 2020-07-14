package other;

import java.io.DataInputStream;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Oversleep {
	static int sx, sy, ex, ey;
	static boolean visited[][];
	static char arr[][];

	public static void main(String[] args) throws Exception {
		DataInputStream in = new DataInputStream(System.in);
		StringTokenizer s = new StringTokenizer(in.readLine());
		int y = Integer.parseInt(s.nextToken()), x = Integer.parseInt(s.nextToken());

		arr = new char[y][x];
		visited = new boolean[y][x];
		for (int i = 0; i < y; i++) {
			arr[i] = in.readLine().toCharArray();
			for (int j = 0; j < x; j++) {
				if (arr[i][j] == 'e') {
					ex = j;
					ey = i;
				} else if (arr[i][j] == 's') {
					sx = j;
					sy = i;
				}
			}
		}
		in.close();
		LinkedList<Integer> q = new LinkedList<Integer>();

		q.add(sx + 1);
		q.add(sy);
		q.add(1);
		q.add(sx - 1);
		q.add(sy);
		q.add(1);
		q.add(sx);
		q.add(sy - 1);
		q.add(1);
		q.add(sx);
		q.add(sy + 1);
		q.add(1);

		while (!q.isEmpty()) {
			int cx = q.poll(), cy = q.poll(), d = q.poll();
			if (cx >= x || cy >= y || cx < 0 || cy < 0 || visited[cy][cx] || arr[cy][cx] == 'X') {
				continue;
			}
			visited[cy][cx] = true;
			if (cx == ex && cy == ey) {
				System.out.println(d - 1);
				System.exit(0);
			}

			q.add(cx + 1);
			q.add(cy);
			q.add(d + 1);

			q.add(cx - 1);
			q.add(cy);
			q.add(d + 1);

			q.add(cx);
			q.add(cy - 1);
			q.add(d + 1);

			q.add(cx);
			q.add(cy + 1);
			q.add(d + 1);
		}
		System.out.println(-1);
	}

}
