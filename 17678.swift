func solution(_ n:Int, _ t:Int, _ m:Int, _ timetable:[String]) -> String {
    var time = 540
    var sortedTimes = timetable.map { toMinutes($0) }.sorted { $0 < $1 }
    
    for i in 0..<n - 1 {
        for j in 0..<m {
            guard let next = sortedTimes.first, next <= time else { break }
            sortedTimes.removeFirst()
        }
        time += t 
    }
    
    sortedTimes = sortedTimes.filter { $0 <= time }
    print(time, sortedTimes)
    if sortedTimes.count >= m {
        let currentMaximum = sortedTimes[m - 1]
        return toTime(currentMaximum - 1)
    } else {
        return toTime(time)
    }
}

func toMinutes(_ time: String) -> Int {
    let parsed = time.components(separatedBy: ":")
    guard let hours = Int(parsed[0]), let minutes = Int(parsed[1]) else { return -1 }
    return hours * 60 + minutes
}

func toTime(_ minutes: Int) -> String {
    let hours = minutes / 60
    return String(format: "%02d:%02d", hours, minutes - (hours * 60))
}
