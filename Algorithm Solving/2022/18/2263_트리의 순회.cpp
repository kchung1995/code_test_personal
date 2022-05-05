// 문제 링크: https://www.acmicpc.net/problem/2263
#include <iostream>
using namespace std;
#define MAX_N 100001

int n;
int inorder[MAX_N];
int postorder[MAX_N];
int location[MAX_N];

void getPreorder (int inStart, int inEnd, int postStart, int postEnd){
    // 범위를 벗어나면 탐색 종료
    if (inStart > inEnd || postStart > postEnd) return;
    int root = postorder[postEnd];
    int inorderRootIndex = location[root];
    cout << root << ' ';
    
    // 노드 구간의 시작과 끝을 두 구간으로 나누어 진행
    int left = inorderRootIndex - inStart;
    getPreorder(inStart, inorderRootIndex - 1, postStart, postStart + left - 1);
    getPreorder(inorderRootIndex + 1, inEnd, postStart + left, postEnd - 1);
}

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }
    
    // memo 배열에 inorder 값의 위치를 기록
    for (int i = 1; i <= n; i++) {
        location[inorder[i]] = i;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어지는 입력을 받는다.
    init();
    
    // 재귀 탐색 진행
    getPreorder(1, n, 1, n);
    
    return 0;
}

