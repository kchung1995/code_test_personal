// 문제 링크: https://www.acmicpc.net/problem/2293
import java.util.*

val MAX_N = 110
val MAX_K = 10010
val coin = IntArray(MAX_N)
val dp = IntArray(MAX_K)

fun main() {

    // 입력을 위한 scanner
    val sc = Scanner(System.`in`)

    // 입력 받기
    val n: Int = sc.nextInt()
    val k: Int = sc.nextInt()
    for (i in 1..n) {
        coin[i] = sc.nextInt()
    }

    // dp 점화식
    dp[0] = 1
    for (i in 1..n) {
        for (j in coin[i]..k) {
            dp[j] = dp[j] + dp[j - coin[i]]
        }
    }

    // 정답 출력
    println(dp[k])
}
