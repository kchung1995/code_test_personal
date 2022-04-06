// 문제 링크: https://www.acmicpc.net/problem/10999
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Tree {
    long long value, lazy;
}Tree;

vector<long long> numbers;
long long n, m, k;

long long closest_squre(vector<long long>& input) {
    long long i = 1;
    long long n = (long long)input.size();
    while (1) {
        if (pow(2, i) >= n) break;
        i++;
    }
    return pow(2, i) * 2;
}

long long segment_tree(vector<Tree>& tree, long long start, long long end, long long node) {
    if (start == end) return tree[node].value = numbers[start];
    long long mid = (start + end) / 2;
    return tree[node].value = segment_tree(tree, start, mid, node * 2) + segment_tree(tree, mid + 1, end, node * 2 + 1);
}

long long get_sum(vector<Tree>& tree, long long start, long long end, long long left, long long right, long long node) {
    //lazy가 남아있는 경우
    if (tree[node].lazy != 0) {
        tree[node].value += (end - start + 1) * tree[node].lazy;
        if (start != end) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node].value;
    long long mid = (start + end) / 2;
    return get_sum(tree, start, mid, left, right, node * 2) + get_sum(tree, mid + 1, end, left, right, node * 2 + 1);
}

void update_range(vector<Tree>& tree, long long start, long long end, long long node, long long left, long long right, long long value) {
    //lazy가 남아있는 경우
    if (tree[node].lazy != 0) {
        tree[node].value += (end - start + 1) * tree[node].lazy;
        if (start != end) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if (right < start || left > end) return;

    //대표 구간을 찾았을 때
    if (left <= start && right >= end) {
        tree[node].value += (end - start + 1) * value;
        if (start != end) {
            tree[node * 2].lazy += value;
            tree[node * 2 + 1].lazy += value;
        }
        return;
    }

    long long mid = (start + end) / 2;
    update_range(tree, start, mid, node * 2, left, right, value);
    update_range(tree, mid + 1, end, node * 2 + 1, left, right, value);
    tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        long long temp; cin >> temp; numbers.push_back(temp);
    }

    long long num_size = closest_squre(numbers);
    long long size = (long long)numbers.size() - 1;
    vector<Tree> tree(num_size);
    segment_tree(tree, 0, size, 1);

    for (int i = 0; i < m + k; i++) {
        long long a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_range(tree, 0, size, 1, b - 1, c - 1, d);
        }
        else if (a == 2) {
            cin >> b >> c;
            cout << get_sum(tree, 0, size, b - 1, c - 1, 1) << '\n';;
        }
    }
    return 0;
}

