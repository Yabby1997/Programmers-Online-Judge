import Foundation

func toSeconds(_ time: String) -> Int {
    let splited = time.components(separatedBy: ":")
    guard let hours = Int(splited[0]), let minutes = Int(splited[1]), let seconds = Int(splited[2]) else { return 0 }
    return hours * 3600 + minutes * 60 + seconds
}

func toString(_ time: Int) -> String {
    let hours = time / 3600
    let minutes = (time - hours * 3600) / 60
    let seconds = time - hours * 3600 - minutes * 60
    return String(format: "%02d:%02d:%02d", hours < 0 ? 0 : hours, minutes < 0 ? 0 : minutes, seconds < 0 ? 0 : seconds)
}

func solution(_ play_time:String, _ adv_time:String, _ logs:[String]) -> String {
    let playTime = toSeconds(play_time)
    var adTime = toSeconds(adv_time)
    var accumulatedViews = Array(repeating: 0, count: playTime + 1)
    var candidatePoints: [Int] = []
    
    for log in logs {
        let splited = log.components(separatedBy: "-")
        let from = toSeconds(splited[0])
        let to = toSeconds(splited[1])
        
        accumulatedViews[from] += 1
        accumulatedViews[to] -= 1
        
        candidatePoints.append(from)
        candidatePoints.append(to - adTime)
    }

    for i in 1..<playTime { accumulatedViews[i] += accumulatedViews[i - 1] }
    for i in 1..<playTime { accumulatedViews[i] += accumulatedViews[i - 1] }
    
    var bestTime = 0 
    var bestViews = accumulatedViews[adTime - 1]
    
    for candidate in candidatePoints {
        let currentViews = accumulatedViews[min(candidate + adTime - 1, accumulatedViews.count - 1)] - (candidate - 1 > 0 ? accumulatedViews[candidate - 1] : 0)
        if currentViews > bestViews || (currentViews == bestViews && bestTime > candidate) {
            bestViews = currentViews
            bestTime = candidate
        }
    }
    
    return toString(bestTime)
}
