import Foundation

func solution(_ record:[String]) -> [String] {
    var users: Dictionary<String, String> = [:]
    var logs: [(Bool, String)] = []
    
    for eachRecord in record {
        let input = eachRecord.split(separator: " ").map { String($0) }
        
        switch input[0] {
            case "Enter": enter(uid: input[1], name: input[2], users: &users, logs: &logs)
            case "Leave": leave(uid: input[1], logs: &logs)
            case "Change": setName(uid: input[1], name: input[2], users: &users)
            default: break 
        }
    }
    
    return logs.compactMap { 
        guard let name = users[$0.1] else { return nil }
        return $0.0 ? "\(name)님이 들어왔습니다." : "\(name)님이 나갔습니다."
    }
}

func enter(uid: String, name: String, users: inout [String: String], logs: inout [(Bool, String)]) {
    setName(uid: uid, name: name, users: &users)
    logs.append((true, uid))
}

func leave(uid: String, logs: inout [(Bool, String)]) {
    logs.append((false, uid))
}

func setName(uid: String, name: String, users: inout [String: String]) {
    users[uid] = name
}
