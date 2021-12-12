import Foundation


func solution(_ tickets:[[String]]) -> [String] {
    var adjacencyList: [String: [String]] = [:]
    var route: [String] = []
    
    tickets.forEach { ticket in 
        guard let _ = adjacencyList[ticket[0]] else { return adjacencyList[ticket[0]] = [ticket[1]] }
        adjacencyList[ticket[0]]?.append(ticket[1]) 
    }
    for (departure, destinations) in adjacencyList { adjacencyList[departure] = destinations.sorted() }
    
    dfs("ICN", &adjacencyList, &route, tickets.count)
    return route
}

func dfs(_ current: String, _ adjacencyList: inout [String: [String]], _ route: inout [String], _ remainingTickets: Int) -> Bool {
    route.append(current)
    if remainingTickets == 0 { return true }

    guard let candidates = adjacencyList[current] else { return false }    
    var tempCandidates = candidates
    for (index, candidate) in candidates.enumerated() {
        tempCandidates.remove(at: index)
        adjacencyList[current] = tempCandidates
        if dfs(candidate, &adjacencyList, &route, remainingTickets - 1) { return true }
        route.popLast()
        tempCandidates = candidates
        adjacencyList[current] = candidates
    }
    
    return false
}
