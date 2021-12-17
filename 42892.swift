import Foundation

class BinaryTree {
    class Node {
        let number: Int
        let x: Int
        let y: Int
        var leftChild: Node?
        var rightChild: Node?

        init(number: Int, x: Int, y: Int) {
            self.number = number
            self.x = x
            self.y = y
        }
    }
    
    var root: Node?
    
    init(nodeInfo: [[Int]]) {
        var nodes = nodeInfo.enumerated().map { Node(number: $0 + 1, x: $1[0], y: $1[1]) }.sorted { $0.y < $1.y || ($0.y == $1.y && $0.x > $1.x) }
        while let current = nodes.popLast() { self.appendNew(current, self.root) }
    }
    
    private func appendNew(_ node: Node, _ parent: Node? = nil) {
        guard let parentNode = parent else { return self.root = node }
        if node.x < parentNode.x {
            guard let leftChild = parentNode.leftChild else { return parentNode.leftChild = node }
            appendNew(node, leftChild)
        } else {
            guard let rightChild = parentNode.rightChild else { return parentNode.rightChild = node }
            appendNew(node, rightChild)
        }
    }
    
    func traversePreorder(result: inout [Int]) {
        self.traversePreorderRecursively(node: self.root, result: &result)
    }
    
    func traversePostorder(result: inout [Int]) {
        self.traversePostorderRecursively(node: self.root, result: &result)
    }

    private func traversePreorderRecursively(node: Node?, result: inout [Int]) {
        if let current = node {
            result.append(current.number)
            traversePreorderRecursively(node: current.leftChild, result: &result)
            traversePreorderRecursively(node: current.rightChild, result: &result)
        }
    }
    
    private func traversePostorderRecursively(node: Node?, result: inout [Int]) {
        if let current = node {
            traversePostorderRecursively(node: current.leftChild, result: &result)
            traversePostorderRecursively(node: current.rightChild, result: &result)
            result.append(current.number)
        }
    }
}

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    let tree = BinaryTree(nodeInfo: nodeinfo)
    var preorderResult: [Int] = []
    var postorderResult: [Int] = []
    
    tree.traversePreorder(result: &preorderResult)
    tree.traversePostorder(result: &postorderResult)
    
    return [preorderResult, postorderResult]
}
