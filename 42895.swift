import Foundation

func solution(_ N:Int, _ number:Int) -> Int {
    var neededOperationsForNumber: [Int] = Array(repeating: -1, count: 32000)
    var numbersByOperationCounts: [[Int]] = Array(repeating: [], count: 9)
    
    for repeatingCount in 1...5 {
        if let repeatingNumber = Int(String(repeating: "\(N)", count: repeatingCount)),
           repeatingNumber < 32000 {
            neededOperationsForNumber[repeatingNumber] = repeatingCount
            numbersByOperationCounts[repeatingCount].append(repeatingNumber)
        }
    }
    
    for totalOperationCounts in 2...8 {
        for subOperationCounts in 1...totalOperationCounts / 2 {
            let superOperationCounts = totalOperationCounts - subOperationCounts
            for subNumber in numbersByOperationCounts[subOperationCounts] {
                for superNumber in numbersByOperationCounts[superOperationCounts] {
                    guard superNumber > 0, subNumber > 0 else { continue }
                    calculate(subNumber + superNumber, totalOperationCounts, &neededOperationsForNumber, &numbersByOperationCounts)
                    calculate(subNumber - superNumber, totalOperationCounts, &neededOperationsForNumber, &numbersByOperationCounts)
                    calculate(superNumber - subNumber, totalOperationCounts, &neededOperationsForNumber, &numbersByOperationCounts)
                    calculate(subNumber * superNumber, totalOperationCounts, &neededOperationsForNumber, &numbersByOperationCounts)
                    calculate(subNumber / superNumber, totalOperationCounts, &neededOperationsForNumber, &numbersByOperationCounts)
                    calculate(superNumber / subNumber, totalOperationCounts, &neededOperationsForNumber, &numbersByOperationCounts)
                }
            }
        }
    }
    
    return neededOperationsForNumber[number]
}

func calculate(_ number: Int, _ operations: Int, _ neededOperationsForNumber: inout [Int], _ numbersByOperationCounts: inout [[Int]]) {
    guard number >= 0,
          number < 32000,
          neededOperationsForNumber[number] == -1 || neededOperationsForNumber[number] > operations else { return }
    neededOperationsForNumber[number] = operations
    numbersByOperationCounts[operations].append(number)
}
