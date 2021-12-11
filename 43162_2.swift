import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var numberOfNetworks = 0
    var networks = Array(repeating: 0, count: n)
    for computer in 0..<n { dfs(computer, &numberOfNetworks, &networks, n, computers) }
    return numberOfNetworks
}

func dfs(_ currentComputer: Int, _ numberOfNetworks: inout Int, _ networks: inout [Int], _ n: Int, _ computers: [[Int]]) {
    if networks[currentComputer] == 0 {
        numberOfNetworks += 1
        networks[currentComputer] = numberOfNetworks
    }
    
    for nextComputer in 0..<n {
        if computers[currentComputer][nextComputer] == 1 && networks[nextComputer] == 0{ 
            networks[nextComputer] = networks[currentComputer]
            dfs(nextComputer, &numberOfNetworks, &networks, n, computers)
        }
    }
}
