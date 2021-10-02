import Foundation

var categoryCount: Dictionary<String, Int> = [:]

func solution(_ clothes:[[String]]) -> Int {
    var answer = 1
    clothes.forEach { if let count = categoryCount[$0[1]] { categoryCount[$0[1]] = count + 1 } else  { categoryCount[$0[1]] = 1 } }
    categoryCount.forEach { key, value in answer = answer * (value + 1) }
    
    return answer - 1
}
