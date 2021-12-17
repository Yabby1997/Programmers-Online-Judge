import Foundation

func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    var answer: [[Int]] = []
    var structures = Array(repeating: Array(repeating: Array(repeating: false, count: 2), count: n + 1), count: n + 1)
    structures.enumerated().forEach { structures[$0.0][0][1] = true }
    
    for command in build_frame {
        var tempStructures = structures
        tempStructures[command[0]][command[1]][command[2]] = command[3] == 0 ? false : true
        if isValid(&tempStructures) { structures = tempStructures }
    }
    
    for (rowIndex, eachRow) in structures.enumerated() {
        for (colIndex, each) in eachRow.enumerated() {
            if each[0] == true { answer.append([rowIndex, colIndex, 0]) }
            if each[1] == true && colIndex != 0 { answer.append([rowIndex, colIndex, 1]) }
        }
    }
    
    return answer
}

func isValid(_ structures: inout [[[Bool]]]) -> Bool {
    for (rowIndex, eachRow) in structures.enumerated() {
        for (colIndex, each) in eachRow.enumerated() {
            if each[0] == true {
                guard (rowIndex - 1 >= 0 && structures[rowIndex - 1][colIndex][1]) ||
                      (structures[rowIndex][colIndex][1]) ||
                      (colIndex - 1 >= 0 && structures[rowIndex][colIndex - 1][0]) else { return false }
            }
            if each[1] == true && colIndex != 0 {
                guard (rowIndex - 1 >= 0 && rowIndex + 1 <= structures.count && structures[rowIndex - 1][colIndex][1] && structures[rowIndex + 1][colIndex][1]) ||
                      (colIndex - 1 >= 0 && structures[rowIndex][colIndex - 1][0]) ||
                      (rowIndex + 1 <= structures.count && colIndex - 1 >= 0 && structures[rowIndex + 1][colIndex - 1][0]) else { return false }
            }
        }
    }
    
    return true
}
