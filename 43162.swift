import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var numOfNetworks = 0
    var networks = Array(repeating: -1, count: n)
    var stack = Array(0..<n)
    
    while !stack.isEmpty {
        var currentNode = stack.removeLast()
        
        if networks[currentNode] == -1 { 
            networks[currentNode] = numOfNetworks
            numOfNetworks += 1
        }
            
        for opponentNode in 0..<n {
            if computers[currentNode][opponentNode] == 1 && networks[opponentNode] == -1 { 
                networks[opponentNode] = networks[currentNode]
                stack.append(opponentNode) 
            }
        }
    }
    
    return numOfNetworks
}
