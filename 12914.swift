func solution(_ n:Int) -> Int {
    var dp: [Int] = Array(repeating: 0, count: 2001)
    dp[1] = 1
    dp[2] = 2
    
    for i in 3...2000 { dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567 }
    
    return dp[n]
}
