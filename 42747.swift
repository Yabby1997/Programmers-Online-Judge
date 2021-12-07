import Foundation

func solution(_ citations:[Int]) -> Int {
    var answer = 0
    for (index, citation) in citations.sorted { $0 > $1 }.enumerated() { if index < citation { answer = index + 1 }}
    return answer
}
