import Foundation

let rowDirection = [-1, 0, 1, 0]
let colDirection = [0, -1, 0, 1]
let inf = 200000000

struct Queue<T> {
    private var elements: [T]
    var isEmpty: Bool { self.elements.isEmpty }
    
    init(_ elements: [T] = []) {
        self.elements = elements
    }
    
    mutating func enqueue(_ element: T) {
        self.elements.append(element)
    }
    
    mutating func dequeue() -> T? {
        return self.isEmpty ? nil : self.elements.removeFirst()
    }
}

func solution(_ board:[[Int]]) -> Int {
    var priceBoard = Array(repeating: Array(repeating: Array(repeating: inf, count: 4), count: board.count), count: board.count)
    var queue: Queue<(Int, Int, Int)> = Queue([(0, 0, 0), (0, 0, 1), (0, 0, 2), (0, 0, 3)])
    priceBoard[0][0] = [0, 0, 0, 0]
    
    for i in 0..<board.count {
        for j in 0..<board[i].count {
            if board[i][j] == 1 {
                priceBoard[i][j] = [-1, -1, -1, -1]
            }
        }
    }
    
    while let current = queue.dequeue() {
        let currentCost = priceBoard[current.0][current.1][current.2]
        
        for i in 0..<4 {
            let nextRow = current.0 + rowDirection[i]
            let nextCol = current.1 + colDirection[i]
            let nextPrice = currentCost + (((current.2 + i) % 2) == 0 ? 100 : 600)
            guard nextRow >= 0, nextRow < board.count, nextCol >= 0, nextCol < board.count, nextPrice < priceBoard[nextRow][nextCol][i] else { continue }
            priceBoard[nextRow][nextCol][i] = nextPrice
            queue.enqueue((nextRow, nextCol, i))
        }
    }
    
    guard let minimumCost = priceBoard[board.count - 1][board.count - 1].min() else { return -1 }
    return minimumCost
}
