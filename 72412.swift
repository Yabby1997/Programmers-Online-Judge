import Foundation

func solution(_ info:[String], _ query:[String]) -> [Int] {
    var answer: [Int] = []
    var candidates: [String: [Int]] = [:]

    for each in info.enumerated() {
        var parsed = each.1.components(separatedBy: " ")
        guard let last = parsed.popLast(), let score = Int(last) else { return [] }
        makeUpCandidates(parsed, score, 0, &candidates)
    }
    
    for (query, scores) in candidates { candidates[query] = scores.sorted { $0 < $1 } }
    
    for each in query {
        var parsed = each.components(separatedBy: " ").filter { $0 != "and" }
        guard let last = parsed.popLast(), let score = Int(last) else { return [] }
        let query = parsed.joined()
        if let candidate = candidates[query] {
            answer.append(binarySearch(candidate, score))
        } else {
            answer.append(0)
        }
    }

    return answer
}

func makeUpCandidates(_ parsed: [String], _ score: Int, _ index: Int, _ candidates: inout [String: [Int]]) {
    if index == 4 {
        let joined = parsed.joined()
        if candidates[joined] != nil {
            candidates[joined]?.append(score)
        } else {
            candidates[joined] = [score]
        }
        return
    }
    
    makeUpCandidates(parsed, score, index + 1, &candidates)
    var temp = parsed
    temp[index] = "-"
    makeUpCandidates(temp, score, index + 1, &candidates)
}

func binarySearch(_ candidates: [Int], _ target: Int) -> Int {
    var from = 0
    var to = candidates.count
    var mid = (from + to) / 2
    
    while to > from {
        if candidates[mid] < target {
            from = mid + 1
            mid = (from + to) / 2
        } else {
            to = mid
            mid = (from + to) / 2
        }
    }
    
    return candidates.count - from
}
