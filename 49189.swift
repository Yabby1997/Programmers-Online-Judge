import Foundation

struct Queue<T> {
    private var elements: [T]
    var isEmpty: Bool { self.elements.isEmpty }
    
    init(elements: [T]) {
        self.elements = elements
    }
    
    mutating func enqueue(_ element: T) {
        elements.append(element)
    }
    
    mutating func dequeue() -> T? {
        return self.isEmpty ? nil : self.elements.removeFirst()
    }
}

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var distance: [Int] = Array(repeating: -1, count: n + 1)
    var adjacencyList: [[Int]] = Array(repeating: [], count: n + 1)
    distance[1] = 0
    edge.forEach { each in 
        adjacencyList[each[0]].append(each[1])
        adjacencyList[each[1]].append(each[0])
    }
 
    var queue = Queue<Int>(elements: [1])
    
    while !queue.isEmpty {
        guard let current = queue.dequeue() else { continue }
        
        for next in adjacencyList[current] {
            if distance[next] == -1 || distance[next] > distance[current] + 1 {
                distance[next] = distance[current] + 1
                queue.enqueue(next)
            }
        }
    }
    
    let farthestDistance = distance.max { $0 < $1 }
    return distance.filter { $0 == farthestDistance }.count
}
