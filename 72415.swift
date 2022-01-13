import Foundation

let rowDirection = [-1, 1, 0, 0]
let colDirection = [0, 0, -1, 1]
let rowEnd = [0, 3, -1, -1]
let colEnd = [-1, -1, 0, 3]

struct Position {
    let row: Int
    let col: Int
}

struct Pair {
    let first: Position
    let second: Position
}

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

func solution(_ board:[[Int]], _ r:Int, _ c:Int) -> Int {
    var totalCosts: [Int] = []
    let pairs = findPairs(board)
    let permutatedPairs = getPermutation(pairs, pairs.count)
    permutatedPairs.forEach { solveRecursively($0, 0, board, Position(row: r, col: c), 0, &totalCosts) }
    guard let minimumCost = totalCosts.min() else { return -1 }
    return minimumCost
}

func solveRecursively(_ permuted: [Pair], _ index: Int, _ currentBoard: [[Int]], _ currentPosition: Position, _ cost: Int, _ totalCosts: inout [Int]) {
    if index == permuted.count { return totalCosts.append(cost) }
    let currentPair = permuted[index]
    let firstCard = currentPair.first
    let secondCard = currentPair.second
    
    var nextBoard = currentBoard
    nextBoard[firstCard.row][firstCard.col] = 0
    nextBoard[secondCard.row][secondCard.col] = 0
    
    solveRecursively(permuted, index + 1, nextBoard, secondCard, cost + calcCostForRemoval(currentBoard, currentPosition, firstCard, secondCard), &totalCosts)
    solveRecursively(permuted, index + 1, nextBoard, firstCard, cost + calcCostForRemoval(currentBoard, currentPosition, secondCard, firstCard), &totalCosts)
}

func getPermutation<T>(_ elements: [T], _ count: Int) -> [[T]] {
    var result = [[T]]()
    var visited: [Bool] = Array(repeating: false, count: elements.count)
    
    func permutateRecursively(_ currentPermuted: [T] = []) {
        guard currentPermuted.count != count else { return result.append(currentPermuted) }
        for i in 0..<elements.count {
            guard !visited[i] else { continue }
            visited[i] = true
            permutateRecursively(currentPermuted + [elements[i]])
            visited[i] = false
        }
    }
    
    permutateRecursively()
    return result
}

func calcCostForRemoval(_ board: [[Int]], _ from: Position, _ first: Position, _ second: Position) -> Int {
    var costBoard = calcCostBoard(board, from)
    var cost = costBoard[first.row][first.col] + 1
    costBoard = calcCostBoard(board, first)
    cost += (costBoard[second.row][second.col] + 1)
    return cost
}

func findPairs(_ board: [[Int]]) -> [Pair] {
    var pairs: [Pair] = []
    for pair in 1...6 {
        let pairPositions = board.flatMap { $0 }.enumerated().filter { $0.1 == pair }.map { Position(row: $0.0 / 4, col: $0.0 % 4) }
        guard pairPositions.count == 2 else { continue }
        pairs.append(Pair(first: pairPositions[0], second: pairPositions[1]))
    }
    
    return pairs
}

func calcCostBoard(_ board: [[Int]], _ from: Position) -> [[Int]] {
    var costBoard = Array(repeating: Array(repeating: 1000, count: board.count), count: board.count)
    costBoard[from.row][from.col] = 0
    var positionQueue: Queue<Position> = Queue([from])
    
    while let currentPosition = positionQueue.dequeue() {
        let currentCost = costBoard[currentPosition.row][currentPosition.col]
        
        for i in 0..<4 {
            let nextRow = currentPosition.row + rowDirection[i]
            let nextCol = currentPosition.col + colDirection[i]
            
            guard nextRow >= 0, nextRow < board.count, nextCol >= 0, nextCol < board.count, costBoard[nextRow][nextCol] > currentCost + 1 else { continue }
            costBoard[nextRow][nextCol] = currentCost + 1
            positionQueue.enqueue(Position(row: nextRow, col: nextCol))
        }
        
        for i in 0..<4 {
            var nextRow = currentPosition.row
            var nextCol = currentPosition.col
            for _ in 0..<4 {
                nextRow = nextRow + rowDirection[i]
                nextCol = nextCol + colDirection[i]
                
                guard nextRow >= 0, nextRow < board.count, nextCol >= 0, nextCol < board.count else {
                    nextRow = rowEnd[i] == -1 ? currentPosition.row : rowEnd[i]
                    nextCol = colEnd[i] == -1 ? currentPosition.col : colEnd[i]
                    break
                }
                
                guard board[nextRow][nextCol] == 0 else { break }
            }
            
            guard costBoard[nextRow][nextCol] > currentCost + 1 else { continue }
            costBoard[nextRow][nextCol] = currentCost + 1
            positionQueue.enqueue(Position(row: nextRow, col: nextCol))
        }
    }
    
    return costBoard
}
