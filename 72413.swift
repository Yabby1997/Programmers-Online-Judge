import Foundation

struct EdgeData: Comparable {
    static func < (lhs: EdgeData, rhs: EdgeData) -> Bool {
        lhs.cost < rhs.cost
    }
    
    let to: Int
    let cost: Int
}

struct PriorityQueue<T> {
    var heap: [T]
    var priority: (T, T) -> Bool
    
    init(heap: [T], priority: @escaping (T, T) -> Bool) {
        self.heap = heap
        self.priority = priority
        buildHeap()
    }
    
    func leftChild(of index: Int) -> Int {
        return index * 2 + 1    
    }   
    
    func rightChild(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    func parent(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    func size() -> Int {
        return heap.count
    }
    
    func isEmpty() -> Bool {
        return size() == 0
    }
    
    mutating func enqueue(_ element: T) {
        let currentIndex = heap.count
        heap.append(element)
        
        while currentIndex > 0 {
            let parentIndex = parent(of: currentIndex)
            if priority(heap[currentIndex], heap[parentIndex]) {
                heap.swapAt(currentIndex, parentIndex)
            } else {
                break
            }
        }
    }
    
    mutating func dequeue() -> T? {
        if isEmpty() {
            return nil
        } else {
            heap.swapAt(0, heap.count - 1)
            let target = heap.removeLast()
            heapify(at: 0)
            return target
        }
    }
    
    mutating func heapify(at index: Int) {
        let leftChildIndex = leftChild(of: index)
        var targetIndex = rightChild(of: index)
        
        if targetIndex < heap.count {
            if priority(heap[leftChildIndex], heap[targetIndex]) {
                targetIndex = leftChildIndex
            }
        } else if leftChildIndex < heap.count {
            targetIndex = leftChildIndex
        } else {
            return
        }
        if priority(heap[targetIndex], heap[index]) {
            heap.swapAt(targetIndex, index)
            heapify(at: targetIndex)
        } else {
            return
        }
    }
    
    mutating func buildHeap() {
        for index in (0..<(heap.count / 2)).reversed() {
            heapify(at: index)
        }
    }
}

let INF: Int = 2000000000
var numOfVertices: Int = 0
var startingVertex: Int = 0
var destinationA: Int = 0
var destinationB: Int = 0
var adjacencyList = Array(repeating: [(Int, Int)](), count: 201)
var costs = Array(repeating: Array(repeating: INF, count: 201), count: 3)

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    numOfVertices = n
    startingVertex = s
    destinationA = a
    destinationB = b
    
    for fare in fares {
        adjacencyList[fare[0]].append((fare[1], fare[2]))
        adjacencyList[fare[1]].append((fare[0], fare[2]))
    }
    
    dijkstra(indexForCosts: 0, starting: startingVertex)
    dijkstra(indexForCosts: 1, starting: destinationA)
    dijkstra(indexForCosts: 2, starting: destinationB)
    
    var minCost = INF
    for i in 1...numOfVertices {
        if costs[0][i] + costs[1][i] + costs[2][i] < minCost {
            minCost = costs[0][i] + costs[1][i] + costs[2][i]
        }
    }
    
    return minCost
}

func dijkstra(indexForCosts: Int, starting from: Int) {
    costs[indexForCosts][from] = 0
    
    var edgeQueue = PriorityQueue<EdgeData>(heap: [], priority: <)
    edgeQueue.enqueue(EdgeData(to: from, cost: 0))
    
    while !edgeQueue.isEmpty() {
        let currentEdge = edgeQueue.dequeue()!
        let currentTo = currentEdge.to
        let crrentCost = currentEdge.cost
        
        if costs[indexForCosts][currentTo] < crrentCost {
            continue
        }
        
        for next in adjacencyList[currentTo] {
            let nextCost = next.1  + costs[indexForCosts][currentTo]
            if nextCost < costs[indexForCosts][next.0]  {
                costs[indexForCosts][next.0] = nextCost
                edgeQueue.enqueue(EdgeData(to: next.0, cost: nextCost))
            }
        }
    }
}
