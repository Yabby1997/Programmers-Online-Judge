import Foundation

func solution(_ numbers:[Int]) -> String {
    let answer = numbers.sorted { Int64("\($0)\($1)")! > Int64("\($1)\($0)")! }.reduce("", { $0 + "\($1)" })
    return Int64(answer) == 0 ? "0" : answer
}
