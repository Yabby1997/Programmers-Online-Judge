import Foundation

func solution(_ numbers:[Int]) -> Int {
    return Set(0...9).subtracting(Set(numbers)).reduce(0) { $0 + $1 }
}
