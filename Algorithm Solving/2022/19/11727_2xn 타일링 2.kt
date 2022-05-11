// 문제 링크: https://www.acmicpc.net/problem/11727
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val maxN = 1001
    // 입력을 위한 bufferReader
    val br = BufferedReader(InputStreamReader(System.`in`))

    // memoization을 위한 배열 및 1, 2번 원소값 초기화
    val dp = IntArray(maxN)
    dp[1] = 1
    dp[2] = 3

    // 입력
    val n: Int = br.readLine()!!.toInt()
    // 점화식을 이용하여 값을 구함
    for (i in 3..n) {
        dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007
    }

    // 정답 출력 
    println(dp[n])
}
