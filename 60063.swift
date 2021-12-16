import Foundation

let infinity = 1000000

let colDirections = [-1, 1, 0, 0]
let rowDirections = [0, 0, -1, 1]

enum Directions: Int, CaseIterable {
    case left = 0, right, top, bottom
    
    var isHorizontal: Bool { return self == .left || self == .right }
    
    func flipped() -> Directions {
        switch self {
            case .left: return .right
            case .right: return .left
            case .top: return .bottom
            case .bottom: return .top
        }
    }
    
    func rotatableDirections() -> [Directions] {
        return self.isHorizontal ? [.top, .bottom] : [.left, .right]
    }
}

struct Position {
    let row: Int
    let col: Int
    let laidDirection: Directions
    let cost: Int
}

struct PriorityQueue<T> {
    var heap : [T] = []
    let getPriority : (T, T) ->  Bool
    
    init(elements: [T], getPriority: @escaping (T, T) -> Bool) {
        self.heap = elements
        self.getPriority = getPriority
        buildHeap()
    }
    
    func getLeftChildIndex(of index: Int) -> Int {
        return index * 2  + 1
    }
    
    func getRightChildIndex(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    func getParentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    mutating func enqueue(_ element: T) {
        heap.append(element)
        var currentIndex = heap.count - 1
        while currentIndex != 0 {
            let parentIndex = getParentIndex(of: currentIndex)
            if getPriority(heap[currentIndex], heap[parentIndex]) {
                heap.swapAt(currentIndex, parentIndex)
                currentIndex = parentIndex
            }
            else {
                break
            }
        }
    }
    
    mutating func dequeue() -> T? {
        if heap.count == 0 {
            return nil
        } else {
            let target = heap[0]
            let last = heap.popLast()
            if heap.count != 0 {
                heap[0] = last!
                heapify(at: 0)
            }
            return target
        }
    }
    
    mutating func heapify(at index: Int) {
        let left = getLeftChildIndex(of: index)
        let right = getRightChildIndex(of: index)
        var target = right
        if right < heap.count {
            if getPriority(heap[left], heap[right]) {
                target = left
            }
        } else if left < heap.count {
            target = left
        } else {
            return
        }
        if getPriority(heap[target], heap[index]) {
            heap.swapAt(index, target)
            heapify(at: target)
        } else {
            return
        }
    }
    
    mutating func buildHeap() {
        for eachParent in (0 ..< heap.count / 2).reversed() {
            heapify(at: eachParent)
        }
    }
}

func solution(_ board:[[Int]]) -> Int {
    let n = board[0].count
    let boardRange = 0..<n
    var costBoard = Array(repeating: Array(repeating: Array(repeating: infinity, count: 4), count: n), count: n)
    var positionQueue = PriorityQueue<Position>(elements: [Position(row: 0, col: 0, laidDirection: .right, cost: 0), Position(row: 0, col: 1, laidDirection: .left, cost: 0)]) {
        $0.cost < $1.cost
    }
    
    costBoard[0][0][1] = 0
    costBoard[0][1][0] = 0
    
    while let currentPosition = positionQueue.dequeue() {
        let currentCol = currentPosition.col
        let currentRow = currentPosition.row
        let currentDirection = currentPosition.laidDirection
        let laidCol = currentPosition.col + colDirections[currentDirection.rawValue]
        let laidRow = currentPosition.row + rowDirections[currentDirection.rawValue]
        let nextCost = currentPosition.cost + 1
        
        for moveDirection in Directions.allCases {
            let nextCol = currentCol + colDirections[moveDirection.rawValue]
            let nextRow = currentRow + rowDirections[moveDirection.rawValue]
            let nextLaidCol = laidCol + colDirections[moveDirection.rawValue]
            let nextLaidRow = laidRow + rowDirections[moveDirection.rawValue]
            
            guard boardRange.contains(nextCol),
                  boardRange.contains(nextRow),
                  boardRange.contains(nextLaidCol),
                  boardRange.contains(nextLaidRow),
                  board[nextRow][nextCol] == 0,
                  board[nextLaidRow][nextLaidCol] == 0 else { continue }
            
            if nextCost < costBoard[nextRow][nextCol][currentDirection.rawValue] {
                costBoard[nextRow][nextCol][currentPosition.laidDirection.rawValue] = nextCost
                positionQueue.enqueue(Position(row: nextRow, col: nextCol, laidDirection: currentPosition.laidDirection, cost: nextCost))
            }
            
            if nextCost < costBoard[nextLaidRow][nextLaidCol][currentDirection.flipped().rawValue] {
                costBoard[nextLaidRow][nextLaidCol][currentDirection.flipped().rawValue] = nextCost
                positionQueue.enqueue(Position(row: nextLaidRow, col: nextLaidCol, laidDirection: currentDirection.flipped(), cost: nextCost))
            }
        }
        
        for rotateDirection in currentDirection.rotatableDirections() {
            let nextLaidCol = currentCol + colDirections[rotateDirection.rawValue]
            let nextLaidRow = currentRow + rowDirections[rotateDirection.rawValue]
            let rotationCol = currentCol + colDirections[rotateDirection.isHorizontal ? rotateDirection.rawValue : currentDirection.rawValue]
            let rotationRow = currentRow + rowDirections[rotateDirection.isHorizontal ? currentDirection.rawValue : rotateDirection.rawValue]
            
            guard boardRange.contains(nextLaidCol),
                  boardRange.contains(nextLaidRow),
                  board[nextLaidRow][nextLaidCol] == 0,
                  board[rotationRow][rotationCol] == 0 else { continue }
            
            if nextCost < costBoard[currentRow][currentCol][rotateDirection.rawValue] {
                costBoard[currentRow][currentCol][rotateDirection.rawValue] = nextCost
                positionQueue.enqueue(Position(row: currentRow, col: currentCol, laidDirection: rotateDirection, cost: nextCost))
            }
            
            if nextCost < costBoard[nextLaidRow][nextLaidCol][rotateDirection.flipped().rawValue] {
                costBoard[nextLaidRow][nextLaidCol][rotateDirection.flipped().rawValue] = nextCost
                positionQueue.enqueue(Position(row: nextLaidRow, col: nextLaidCol, laidDirection: rotateDirection.flipped(), cost: nextCost))
            }
        }
    }
    
    return costBoard[n - 1][n - 1].min { $0 < $1 } ?? -1
}

