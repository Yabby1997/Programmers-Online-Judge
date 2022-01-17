import Foundation

func solution(_ m:String, _ musicinfos:[String]) -> String {
    let inputNotes = sequenceToNoteArray(m)
    let musicNotes = infosToNoteArrays(musicinfos)
    
    for each in musicNotes {
        let played = each.2
        
        var from = 0
        while from + inputNotes.count <= played.count {
            if Array(played[from..<from + inputNotes.count]) == inputNotes { return each.1 }
            from += 1
        }
    }
    
    return "(None)"
}

func sequenceToNoteArray(_ sequence: String) -> [Character] {
    let sequenceArray = Array(sequence)
    var notes: [Character] = []
    
    var pointer: Int = 0
    while pointer < sequenceArray.count {
        if pointer + 1 < sequenceArray.count, sequenceArray[pointer + 1] == "#" {
            notes.append(Character(sequenceArray[pointer].lowercased()))
            pointer += 2
        } else {
            notes.append(Character(sequenceArray[pointer].uppercased()))
            pointer += 1
        }
    }
    
    return notes
}

func infosToNoteArrays(_ infos: [String]) -> [(Int, String, [Character])] {
    var result: [(Int, String, [Character])] = []
    
    for info in infos.enumerated() {
        let parsed = info.1.components(separatedBy: ",")
        let runningTime = timeToMinutes(parsed[1]) - timeToMinutes(parsed[0])
        let notes = sequenceToNoteArray(parsed[3])
        
        var played: [Character] = []
        for _ in 0..<runningTime / notes.count { played += notes }
        played += notes[0..<runningTime % notes.count]
        
        result.append((info.0, parsed[2], played))
    }
    
    return result.sorted { $0.2.count > $1.2.count || (($0.2.count == $1.2.count) && $0.0 < $1.0) }
}

func timeToMinutes(_ time: String) -> Int {
    let parsed = time.components(separatedBy: ":")
    return Int(parsed[0])! * 60 + Int(parsed[1])!
}
