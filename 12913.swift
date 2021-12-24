import Foundation

func solution(_ land:[[Int]]) -> Int{
    var scores: [[Int]] = Array(repeating: Array(repeating: 0, count: 4), count: land.count)
    scores[0] = land[0]
    
    for i in 1..<land.count {
        for j in 0...3 {
            for k in 0...3 {
                if j == k { continue }
                let newScore = land[i][j] + scores[i - 1][k]
                if scores[i][j] < newScore { scores[i][j] = newScore }
            }
        }
    }
    
    guard let best = (scores[land.count - 1].max { $0 < $1 }) else { return -1 }
    return best
}
