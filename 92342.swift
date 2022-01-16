import Foundation

struct Shot {
    let index: Int
    let count: Int
}

func getCombination(_ elements: [Shot], _ count: Int) -> [[Int]] {
    var results: [[Int]] = []
    
    func combinateRecursively(_ index: Int = 0, _ currentCombination: [Shot] = [], _ remaining: Int = count) {
        let currentCombinationShotCount = currentCombination.reduce(0) { $0 + $1.count + 1 }
        var currentResult = Array(repeating: 0, count: 11)
        currentCombination.forEach { currentResult[$0.index] = $0.count + 1 }
        
        if currentCombinationShotCount > count { currentResult[index - 1] = remaining }
        if currentCombinationShotCount >= count { return results.append(currentResult) }
        
        for i in index..<elements.count {
            combinateRecursively(i + 1, currentCombination + [elements[i]], count - currentCombination.reduce(0) { $0 + $1.count + 1 })
        }
    }
    
    combinateRecursively()
    return results
}

func calcScoreGap(_ a: [Int], _ r: [Int]) -> Int {
    return zip(a, r).enumerated().reduce(0) { $0 + ($1.1.0 >= $1.1.1 ? ($1.1.0 != 0 ? -(10 - $1.0) : 0) : (10 - $1.0))}
}

func solution(_ n:Int, _ info:[Int]) -> [Int] {
    let combined = getCombination(info.enumerated().map { Shot(index: $0.0, count: $0.1) }, n)
    
    let sorted = combined.sorted { leftCandidate, rightCandidate in
        let leftCandidateScoreGap = calcScoreGap(info, leftCandidate)
        let rightCandidateScoreGap = calcScoreGap(info, rightCandidate)
        let leftCandidateLowerScoreIndex = leftCandidate.enumerated().filter { $0.1 >= 1 }.min { $0.0 > $1.0 }!.0
        let rightCandidateLowerScoreIndex = rightCandidate.enumerated().filter { $0.1 >= 1 }.min { $0.0 > $1.0 }!.0
        return leftCandidateScoreGap > rightCandidateScoreGap || ((leftCandidateScoreGap == rightCandidateScoreGap) && (leftCandidateLowerScoreIndex > rightCandidateLowerScoreIndex))
    }

    if calcScoreGap(info, sorted[0]) <= 0 { return [-1] }
    return sorted[0]
}
