import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node {
    int x, y, type, dist;

    //x, y는 좌표의 위치, type은 지훈이인지 불인지
    Node(int x, int y, int type, int dist) {
        this.x = x;
        this.y = y;
        this.type = type;
        this.dist = dist;
    }
}

class Main {

    //문제 해결을 위한 기본 변수
    static int r, c;
    static char board[][];
    static boolean visited[][];
    static Node jihun;
    static final int INF = 999999999;
    static int answer = INF;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static boolean inBoundary(int x, int y) {
        if (x >= 0 && x < r && y >= 0 && y < c) return true;
        else return false;
    }

    static boolean canEscape(int x, int y) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!inBoundary(nx, ny)) return true;
        }
        return false;
    }

    static void bfs(Queue<Node> q) {
        int x, y, dist;
        q.add(jihun); visited[jihun.x][jihun.y] = true;

        while(!q.isEmpty()) {
            Node next = q.poll();
            x = next.x;
            y = next.y;
            dist = next.dist;

            //탈출
            if (next.type == 0 && canEscape(x, y)) {
                answer = Math.min(answer, dist + 1); return;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (!inBoundary(nx, ny)) continue;
                if (board[nx][ny] == '#' || board[nx][ny] == 'F') continue;

                //지훈이인 경우
                if (next.type == 0 && !visited[nx][ny]) {
                    q.add(new Node(nx, ny, next.type, dist + 1));
                    visited[nx][ny] = true;
                }
                //불인 경우
                else if (next.type == 1) {
                    board[nx][ny] = 'F';
                    q.add(new Node(nx ,ny, next.type, dist + 1));
                }
            }
        }
    }

    public static void main(String[] args) {
        //문제에 주어지는 입력을 받는다.
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        board = new char[r][c];
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < r; i++) {
            String temp = sc.next();
            for (int j = 0; j < c; j++) {
                board[i][j] = temp.charAt(j);
                //지훈이의 위치
                if (board[i][j] == 'J') {
                    board[i][j] = '.';
                    jihun = new Node(i, j, 0, 0);
                }
                //불의 위치
                else if (board[i][j] == 'F') {
                    q.add(new Node(i, j, 1, 0));
                }
            }
        }

        visited = new boolean[r][c];

        bfs(q);
        if (answer == INF) System.out.println("IMPOSSIBLE");
        else System.out.println(answer);
    }

}