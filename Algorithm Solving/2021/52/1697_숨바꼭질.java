import java.util.*;

public class Main {

    static int n, k;
    static int MAX_N = 100001;
    static int INF = 100000000;

    static int visited[] = new int[MAX_N];

    static void init() {
        for (int i = 0; i < MAX_N; i++) {
            visited[i] = INF;
        }
        visited[n] = 0;
    }

    static boolean in_boundary(int input) {
        if (input < 0 || input >= MAX_N) return false;
        else return true;
    }

    static int move(int input, int mode) {
        if (mode == 0) return input - 1;
        else if (mode == 1) return input + 1;
        else if (mode == 2) return input * 2;
        else return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        init();

        Queue<Integer> q = new LinkedList<>();
        q.add(n);

        while(!q.isEmpty()) {
            int now = q.poll();

            for (int i = 0; i < 3; i++) {
                int next = move(now, i);
                if (!in_boundary(next)) continue;

                if (visited[now] + 1 < visited[next]) {
                    visited[next] = visited[now] + 1;
                    q.add(next);
                }
            }
        }
        System.out.println(visited[k]);
    }
}