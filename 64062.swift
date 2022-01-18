import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var from = 0
    var to = 2000000000
    var mid = (from + to) / 2
    
    while from < to {
        var length = 0
        for stone in stones {
            guard length < k else { break }
            if stone - mid <= 0 {
                length += 1
            } else {
                length = 0
            }
        }
        
        if length >= k {
            to = mid
            mid = (from + to) / 2
        } else {
            from = mid + 1
            mid = (from + to) / 2
        }
    }
    
    return mid
}
