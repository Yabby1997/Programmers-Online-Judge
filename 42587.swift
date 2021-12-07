import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var sortedPriorities = priorities.sorted { $0 > $1 }
    var printQueue = priorities
    var target = priorities.enumerated().map { $0.0 == location }
    var answer = 1
    
    var currentMaximumPriority = sortedPriorities.removeFirst()
    while true {
        let priority = printQueue.removeFirst()
        let isTarget = target.removeFirst()
        
        if currentMaximumPriority == priority {
            if isTarget { 
                return answer
            } else { 
                answer += 1
                currentMaximumPriority = sortedPriorities.removeFirst()
            }
        } else {
            printQueue.append(priority)
            target.append(isTarget)
        }
    } 
}
