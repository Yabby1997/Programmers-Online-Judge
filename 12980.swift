import Foundation

func solution(_ n:Int) -> Int {
    var answer = 1
    var current = n
    
    while current > 1 {
        if current % 2 == 0 { 
            current = current / 2
        } else {
            current = current - 1
            answer += 1
        }
    }
    
    return answer
}
