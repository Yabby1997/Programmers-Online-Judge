import Foundation

class Node {
    let number: Int
    var prev: Node?
    var next: Node?
    
    init(_ number: Int, _ prev: Node? = nil, _ next: Node? = nil) {
        self.number = number
        self.prev = prev
        self.next = next
    }
}

class CircularLinkedList {
    var pointer: Node?
    var size: Int = 0
    
    func add(_ node: Node) {
        size += 1
        if self.pointer == nil { 
            self.pointer = node
            self.pointer?.next = node
            self.pointer?.prev = node
            return
        }
        
        self.pointer?.prev?.next = node
        node.prev = self.pointer?.prev
        node.next = self.pointer
        self.pointer?.prev = node
    }
    
    func remove() -> Node? {
        size -= 1
        var tempNode = self.pointer
        
        self.pointer?.prev?.next = self.pointer?.next
        self.pointer?.next?.prev = self.pointer?.prev
        if let current = self.pointer, let next = current.next, current.number < next.number {
            self.moveNext()
        } else {
            self.movePrev()
        }
        
        return tempNode
    }
    
    func movePrev() {
        self.pointer = self.pointer?.prev
    }
    
    func moveNext() {
        self.pointer = self.pointer?.next
    }
    
    func restore(_ node: Node) {
        size += 1
        node.prev?.next = node
        node.next?.prev = node
    }
}

struct Stack<T> {
    private var elements: [T] = []
    var isEmpty: Bool { self.elements.isEmpty }
    
    mutating func push(_ element: T) {
        self.elements.append(element)
    }
    
    mutating func pop() -> T? {
        return self.isEmpty ? nil : self.elements.popLast()
    }
}

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var table: [Bool] = Array(repeating: true, count: n)
    var dataList = CircularLinkedList()
    var deletedStack = Stack<Node>()
    
    for i in k..<n { dataList.add(Node(i)) }
    for i in 0..<k { dataList.add(Node(i)) }
    
    for command in cmd {
        let parsed = command.components(separatedBy: " ")
        if parsed[0] == "U" {
            guard let move = Int(parsed[1]) else { continue }
            for _ in 0..<move { dataList.movePrev() }
        } else if parsed[0] == "D" {
            guard let move = Int(parsed[1]) else { continue }
            for _ in 0..<move { dataList.moveNext() }
        } else if parsed[0] == "Z" {
            guard let restored = deletedStack.pop() else { continue }
            table[restored.number] = true
            dataList.restore(restored)
        } else if parsed[0] == "C" {
            guard let deleted = dataList.remove() else { continue }
            table[deleted.number] = false
            deletedStack.push(deleted)
        }
    }
    
    return String(table.map { $0 ? "O" : "X" })
}
