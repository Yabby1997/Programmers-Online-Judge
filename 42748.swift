import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {    
    return commands.map { command in return Array(array[command[0] - 1..<command[1]]).sorted()[command[2] - 1] }
}
