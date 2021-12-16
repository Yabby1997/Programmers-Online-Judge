import Foundation

func union(_ parents: inout [Int], from: Int, to: Int) {
    let fromRoot = find(&parents, of: from)
    let toRoot = find(&parents, of: to) 
    parents[fromRoot] = toRoot
}

func find(_ parents: inout [Int], of index: Int) -> Int {
    if parents[index] == index { return index }
    parents[index] = find(&parents, of: parents[index])
    return parents[index]
}

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var totalCost = 0
    var sortedCosts = costs.sorted { $0[2] > $1[2] }
    var parents = Array(0..<n)
    
    while let currentBridge = sortedCosts.popLast() {
        let from = currentBridge[0]
        let to = currentBridge[1]
        let cost = currentBridge[2]
        
        if find(&parents, of: from) == find(&parents, of: to) {
            continue
        } else {
            union(&parents, from: from, to: to)
            totalCost += cost
        }
    }
    
    return totalCost
}
