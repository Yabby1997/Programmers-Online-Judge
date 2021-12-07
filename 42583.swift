import Foundation

struct Queue {
    var queue: [Int] = []
    var isEmpty: Bool { self.queue.isEmpty }
    var front: Int? { self.queue.first }
    
    mutating func enqueue(_ element: Int) {
        self.queue.append(element)
    }
    
    mutating func dequeue() -> Int? {
        return self.queue.isEmpty ? nil : self.queue.removeFirst()
    }
}

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var deque: [Int] = Array(1...bridge_length).map { _ in 0 }
    var truckQueue: Queue = Queue(queue: truck_weights)
    var sumOfTruckWeights = 0
    var answer = 0
    
    while !(truckQueue.isEmpty && sumOfTruckWeights == 0) {
        sumOfTruckWeights -= deque.removeFirst()
        
        if !truckQueue.isEmpty, let nextTruck = truckQueue.front, sumOfTruckWeights + nextTruck <= weight {
            let _ = truckQueue.dequeue()
            deque.append(nextTruck)
            sumOfTruckWeights += nextTruck
        } else { 
            deque.append(0)
        }
        answer += 1
    }
    
    return answer
}
