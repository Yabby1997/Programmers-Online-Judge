import Foundation

func solution(_ s:String) -> Int{
    var stack: [Character] = []
    
    s.forEach { char in
        if let last = stack.last, last == char {
            let _ = stack.removeLast()
        } else { 
            stack.append(char)
        } 
    }
    return stack.count == 0 ? 1 : 0
}
