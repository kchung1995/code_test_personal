import java.util.*;

public class Main {

    public static class Node {
        private int x;
        private int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return this.x;
        }

        public int getY() {
            return this.y;
        }
    }

    public static int MAX_N = 301;
    public static Boolean cannot_divide = false;
    public static int area[][] = new int[MAX_N][MAX_N];
    public static int candidate[][] = new int[MAX_N][MAX_N];
    public static int n, m;
    public static int dx[] = {-1, 0, 1, 0};
    public static int dy[] = {0, 1, 0, -1};

    public static Queue<Node> q = new LinkedList<>();
    public static int year_count = 0;

    public static Boolean in_boundary(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m) return true;
        else return false;
    }

    public static void melt() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                candidate[i][j] = 0;

                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (!in_boundary(ni, nj)) continue;
                    if (area[ni][nj] == 0) candidate[i][j] += 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] < candidate[i][j]) area[i][j] = 0;
                else area[i][j] -= candidate[i][j];
            }
        }
        year_count++;
    }

    public static Boolean has_divided() {
        int iceberg_count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                candidate[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] != 0 && candidate[i][j] == 0) {
                    candidate[i][j] = 1;
                    while(!q.isEmpty()) q.remove();
                    q.add(new Node(i, j));
                    while(!q.isEmpty()) {
                        Node node = q.poll();
                        int cx = node.getX();
                        int cy = node.getY();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cx + dx[dir];
                            int ny = cy + dy[dir];
                            if (!in_boundary(nx, ny)) continue;
                            if (area[nx][ny] == 0) continue;
                            if (candidate[nx][ny] == 1) continue;
                            candidate[nx][ny] = 1;
                            q.add(new Node(nx, ny));
                        }
                    }
                    iceberg_count++;
                }
            }
        }

        if (iceberg_count == 1) return false;
        else if (iceberg_count == 0) {
            cannot_divide = true;
            return true;
        }
        else return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int temp = sc.nextInt();
                area[i][j] = temp;
            }
        }
        sc.nextLine();

        while(true) {
            if(has_divided()) break;
            melt();

        }

        if (cannot_divide) System.out.println(0);
        else System.out.println(year_count);
    }
}
