import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var remainingDays = zip(progresses, speeds).map { ceil(Double(100 - $0) / Double($1)) }
    var answer: [Int] = []
    
    while true {
        if remainingDays.isEmpty { break }
        remainingDays = remainingDays.map { $0 - remainingDays[0] }
        var count = 0
        for each in remainingDays {
            if each <= 0 { 
                count += 1
                remainingDays.removeFirst() 
            } else {
                break
            }
        }
        answer.append(count)
    }
    
    return answer
}
