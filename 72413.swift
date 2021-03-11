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
var adjacencyList: [[(Int, Int)]] = [[(Int, Int)]()]

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    numOfVertices = n
    startingVertex = s
    destinationA = a
    destinationB = b
    adjacencyList = Array(repeating: [(Int, Int)](), count: numOfVertices + 1)
    
    for fare in fares {
        adjacencyList[fare[0]].append((fare[1], fare[2]))
        adjacencyList[fare[1]].append((fare[0], fare[2]))
    }
    
    // 같이갈곳까지 Dijkstra 구하기
    var totalCost = dijkstra(starting: startingVertex)
    // 나눠서갈때 요금위해 Dijkstra
    for from in 1...numOfVertices {
        let cost = dijkstra(starting: from)
        totalCost[from] = totalCost[from] + cost[destinationA] + cost[destinationB]
    }
    // 더했을 때 가장 작은 값 찾아서 반환해주기
    let minCost = totalCost.min()!
    
    return minCost
}

func dijkstra(starting from: Int) -> [Int] {
    var costs = Array(repeating: INF, count: numOfVertices + 1)
    costs[from] = 0
    
    var edgeQueue = PriorityQueue<EdgeData>(heap: [], priority: <)
    edgeQueue.enqueue(EdgeData(to: from, cost: 0))
    
    while !edgeQueue.isEmpty() {
        let currentEdge = edgeQueue.dequeue()!
        let currentTo = currentEdge.to
        let crrentCost = currentEdge.cost
        
        if costs[currentTo] < crrentCost {
            continue
        }
        
        for next in adjacencyList[currentTo] {
            let nextCost = next.1  + costs[currentTo]
            if nextCost < costs[next.0]  {
                costs[next.0] = nextCost
                edgeQueue.enqueue(EdgeData(to: next.0, cost: nextCost))
            }
        }
    }
    return costs
}
