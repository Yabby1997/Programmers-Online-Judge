import Foundation

struct PriorityQueue<T> {
    private var elements : [T]
    private let compare : (T, T) ->  Bool
    var count: Int { self.elements.count }
    var isEmpty: Bool { self.elements.isEmpty }
    
    init(_ elements: [T] = [], compare: @escaping (T, T) -> Bool) {
        self.elements = elements
        self.compare = compare
        for index in (0 ..< self.count / 2).reversed() { self.heapify(at: index) }
    }
    
    private mutating func heapify(at index: Int) {
        let leftChildIndex = index * 2 + 1
        let rightChildIndex = index * 2 + 2
        var indexToBeSwapped = leftChildIndex
        
        guard leftChildIndex < self.count else { return }
        if rightChildIndex < self.count, self.compare(self.elements[rightChildIndex], self.elements[leftChildIndex]) {
            indexToBeSwapped = rightChildIndex
        }
        
        guard self.compare(self.elements[indexToBeSwapped], self.elements[index]) else { return }
        self.elements.swapAt(index, indexToBeSwapped)
        self.heapify(at: indexToBeSwapped)
    }
    
    mutating func enqueue(_ element: T) {
        self.elements.append(element)
        var currentIndex = self.count - 1
        var parentIndex = (currentIndex - 1) / 2
        while currentIndex != 0, self.compare(self.elements[currentIndex], self.elements[parentIndex]) {
            self.elements.swapAt(currentIndex, parentIndex)
            currentIndex = parentIndex
            parentIndex = (currentIndex - 1) / 2
        }
    }
    
    mutating func dequeue() -> T? {
        guard !self.isEmpty else { return nil }
        let target = self.elements[0]
        guard let last = self.elements.popLast() else { return nil }
        if !self.isEmpty {
            self.elements[0] = last
            self.heapify(at: 0)
        }
        return target
    }
}


func solution(_ jobs:[[Int]]) -> Int {
    var currentTime: Int = 0
    var answer = 0
    var sortedJobs = jobs.sorted { $0[0] > $1[0] }
    var jobQueue: PriorityQueue<(Int, Int)> = PriorityQueue { $0.1 < $1.1 }
    
    while true {
        if jobQueue.isEmpty, let current = sortedJobs.last, current[0] > currentTime {
            _ = sortedJobs.popLast()
            currentTime = current[0] + current[1]
            answer += current[1]
            continue
        }
        
        while true {
            guard let current = sortedJobs.last, current[0] <= currentTime else { break }
            _ = sortedJobs.popLast()
            jobQueue.enqueue((current[0], current[1]))
        }
        
        guard let currentJob = jobQueue.dequeue() else { break }
        currentTime += currentJob.1
        answer += currentTime - currentJob.0
    }
    
    return Int(answer / jobs.count)
}
