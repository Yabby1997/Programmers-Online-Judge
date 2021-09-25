import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    return DFS(numbers, target, 0, 0)
}

func DFS(_ numbers: [Int], _ target: Int, _ result: Int, _ index: Int) -> Int {
    if index >= numbers.count {
        return result == target ? 1 : 0
    } else {
        return DFS(numbers, target, result + numbers[index], index + 1) + DFS(numbers, target, result - numbers[index], index + 1)
    }
}
