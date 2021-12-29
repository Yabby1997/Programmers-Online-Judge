import Foundation

let englishNumberToInt = [
    "zer": ("0", 4),
    "one": ("1", 3),
    "two": ("2", 3),
    "thr": ("3", 5),
    "fou": ("4", 4),
    "fiv": ("5", 4),
    "six": ("6", 3),
    "sev": ("7", 5),
    "eig": ("8", 5),
    "nin": ("9", 4)
]

func solution(_ s:String) -> Int {
    var pointer = 0
    var resultString: String = ""
    var inputCharacters = Array(s)
    
    while pointer < inputCharacters.count, let current = inputCharacters[pointer].asciiValue {
        if (48...57) ~= current {
            resultString += String(inputCharacters[pointer])
            pointer += 1
        } else {
            guard let lookUp = englishNumberToInt[String(inputCharacters[pointer...pointer + 2])] else { return -1 }
            resultString += lookUp.0
            pointer += lookUp.1
        }
    }
    
    guard let result = Int(resultString) else { return -1 }
    return result
}
