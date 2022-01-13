import Foundation

func solution(_ key:[[Int]], _ lock:[[Int]]) -> Bool {
    var currentKey = key
    let wideLock = makeLockWider(key.count, lock)
    
    for _ in 0..<4 {
        if unlock(currentKey, wideLock) { return true }
        currentKey = rotate(currentKey)
    }
    
    return false
}

func rotate(_ key: [[Int]]) -> [[Int]] {
    var newKey: [[Int]] = key
    
    for row in 0..<newKey.count {
        for col in 0..<newKey.count {
            newKey[row][col] = key[col][newKey.count - 1 - row]
        }
    }
    
    return newKey
}

func makeLockWider(_ keyWidth: Int, _ lock: [[Int]]) -> [[Int]] {
    let newWidth = (keyWidth - 1) * 2 + lock.count
    var newLock: [[Int]] = Array(repeating: Array(repeating: 0, count: newWidth), count: newWidth)
    
    for row in 0..<lock.count {
        let newRow = row + keyWidth - 1
        for col in 0..<lock.count {
            let newCol = col + keyWidth - 1
            newLock[newRow][newCol] = lock[row][col]
        }
    }
    
    return newLock
}

func unlock(_ key: [[Int]], _ wideLock: [[Int]]) -> Bool {
    let tryWidth = wideLock.count - key.count + 1
    let lockFrom = key.count - 1
    let lockTo = wideLock.count - lockFrom
    let lockWidth = lockTo - lockFrom
    
    for tryRow in 0..<tryWidth {
        for tryCol in 0..<tryWidth {
            var currentLock = wideLock
            for keyRow in 0..<key.count {
                let lockRow = tryRow + keyRow
                for keyCol in 0..<key.count {
                    let lockCol = tryCol + keyCol
                    currentLock[lockRow][lockCol] += key[keyRow][keyCol]
                }
            }
            
            var count = 0
            for lockRow in lockFrom..<lockTo { count += currentLock[lockRow][lockFrom..<lockTo].filter { $0 == 1 }.count }
            if count == lockWidth * lockWidth { return true }
        }
    }
    
    return false
}

