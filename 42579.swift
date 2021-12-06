import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var mostPlayedGenre: [String: Int] = [:]
    var songsByGenre: [String: [Int]] = [:]
    
    for (index, (genre, play)) in zip(genres, plays).enumerated() {
        if let currentPlays = mostPlayedGenre[genre] {
            mostPlayedGenre[genre] = currentPlays + play
            songsByGenre[genre]?.append(index)
        } else {
            mostPlayedGenre[genre] = play
            songsByGenre[genre] = [index]
        }
    }
    
    let genreSortedByPlays = mostPlayedGenre.sorted { $0.1 > $1.1 }.map { $0.0 }
    var answer: [Int] = []
    for genre in genreSortedByPlays {
        guard var sortedSongsByGenre = (songsByGenre[genre]?.sorted { plays[$0] < plays[$1] ? true : plays[$0] == plays[$1] ? $0 > $1 : false }) else { continue }
        for _ in 1...2 { if let removed = sortedSongsByGenre.popLast() { answer.append(removed) } }
    }

    return answer
}
