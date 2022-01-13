import Foundation

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int{
    var answer = 0
    var current = 0

    let newStations = stations + [n + w + 1]
    
    for station in newStations {
        guard current < station - w else { 
            current = station + w
            continue
        }
        answer += Int(ceil(Double(station - w - current - 1) / Double(2 * w + 1)))
        current = station + w
    }
    
    return answer
}
