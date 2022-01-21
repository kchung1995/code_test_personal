import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static List<Integer> parent = new LinkedList<>();
    static int n, m;

    static int get_parent(int x) {
        if (parent.get(x) != x) parent.set(x, get_parent(parent.get(x)));
        return parent.get(x);
    }

    static void make_union (int x, int y) {
        x = get_parent(x);
        y = get_parent(y);

        if (x < y) parent.set(y, x);
        else parent.set(x, y);
    }

    static void update_parent() {
        for (int i = 1; i <= n; i++) {
            parent.set(i, get_parent(i));
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        //크루스칼 알고리즘
        for (int i = 0; i <= n; i++) {
            parent.add(i);
        }

        //연결된 노드의 수
        m = sc.nextInt();
        int a, b;
        for (int i = 0; i < m; i++) {
            a = sc.nextInt();
            b = sc.nextInt();

            make_union(a, b);
        }

        //부모 노드 갱신
        update_parent();

        int node_count = 0;
        int first_parent = parent.get(1);
        for (int i = 2; i <= n; i++) {
            if (parent.get(i) == first_parent) node_count++;
        }

        System.out.println(node_count);
    }
}