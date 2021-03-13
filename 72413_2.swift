import Foundation

let INF: Int = 2000000000

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var costs = Array(repeating: Array(repeating: INF, count: n + 1), count: n + 1)
    
    for fare in fares {
        let from = fare[0]
        let to = fare[1]
        let cost = fare[2]
        
        costs[from][to] = cost
        costs[to][from] = cost
    }
    
    for i in 1...n {
        costs[i][i] = 0
    }
    
    for intersection in 1...n {
        for from in 1...n {
            for to in from...n {
                if from == to {
                    continue
                }
                if costs[from][intersection] + costs[intersection][to] < costs[from][to] {
                    costs[from][to] = costs[from][intersection] + costs[intersection][to]
                    costs[to][from] = costs[from][intersection] + costs[intersection][to]
                }
            }
        }
    }
    
    var minCost = INF
    for intersection in 1...n {
        if costs[s][intersection] + costs[intersection][a] + costs[intersection][b] < minCost {
            minCost = costs[s][intersection] + costs[intersection][a] + costs[intersection][b]
        }
    }
    
    return minCost
}
