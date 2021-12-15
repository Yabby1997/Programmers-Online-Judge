import Foundation

struct Stack<T> {
    private var elements: [T]
    var isEmpty: Bool { self.elements.isEmpty }
    
    init(elements: [T]) {
        self.elements = elements
    }
    
    mutating func push(_ element: T) {
        self.elements.append(element)
    }
    
    mutating func pop() -> T? {
        return self.elements.popLast()
    }
}

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var totalCost = 0
    var connection = Array(repeating: 0, count: n)
    var group = 1
    var bridgeStack = Stack<[Int]>(elements: costs.sorted { $0[2] > $1[2] })
    
    while let currentBridge = bridgeStack.pop() {
        let from = currentBridge[0]
        let to = currentBridge[1]
        let cost = currentBridge[2]
        
        switch (connection[from], connection[to]) {
            case (0, 0):
            connection[from] = group
            connection[to] = group
            group += 1
            case (0, 1...):
            connection[from] = connection[to]
            case (1..., 0):
            connection[to] = connection[from]
            case let (fromGroup, toGroup) where fromGroup != toGroup:
            connection = connection.map { $0 == fromGroup ? toGroup : $0 }
            default:
            continue
        }
        totalCost += cost 
    }
    
    return totalCost
}
