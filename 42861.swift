import Foundation

var connection: [Int] = []

func union(_ from: Int, _ to: Int) {
    if to == connection[to] {
        connection[to] = from
    } else {
        union(from, connection[to])
    }
}

func find(_ index: Int) -> Int {
    if index == connection[index] {
        return index
    } else {
        connection[index] = find(connection[index])
        return connection[index]
    }
}

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var totalCost = 0
    var sortedCosts = costs.sorted { $0[2] > $1[2] }
    
    connection = Array(0..<n)
    
    while let currentBridge = sortedCosts.popLast() {
        let from = currentBridge[0]
        let to = currentBridge[1]
        let cost = currentBridge[2]
        
        if find(from) == find(to) {
            continue
        } else {
            union(from, to)
            totalCost += cost
        }
    }
    
    return totalCost
}
