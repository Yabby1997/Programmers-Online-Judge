import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    return binarySearch(times, n, 0, 1000000000000000000)
}

func binarySearch(_ times: [Int], _ n: Int, _ from: Int64, _ to: Int64) -> Int64 {
    let mid = (from + to) / 2
    var current: Int64 = 0
    
    if from == to { return mid }
    
    for time in times {
        current += mid / Int64(time) 
    }
    
    if current < n {
        return binarySearch(times, n, mid + 1, to)
    } else {
        return binarySearch(times, n, from, mid)
    }
}
