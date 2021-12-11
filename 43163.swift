import Foundation

struct Queue<T> {
    private var elements: [T]
    var isEmpty: Bool { self.elements.isEmpty }
    
    init(_ elements: [T] = []) {
        self.elements = elements    
    }
    
    mutating func enqueue(_ element: T) {
        self.elements.append(element)
    }
    
    mutating func dequeue() -> T? {
        return self.isEmpty ? nil : self.elements.removeFirst() 
    }
}

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    let lengthOfWord = words[0].count
    var neededMutations: [String: Int] = [begin: 0]
    words.forEach { neededMutations[$0] = 0 }
    
    var wordQueue: Queue<String> = Queue<String>([begin])
    
    while !wordQueue.isEmpty {
        guard let currentWord = wordQueue.dequeue() else { return 0 }
        
        for candidateWord in words {
            var numberOfMismatches = 0
            for (currentWordLetter, candidateWordLetter) in zip(currentWord, candidateWord) {
                numberOfMismatches = currentWordLetter != candidateWordLetter ? numberOfMismatches + 1 : numberOfMismatches
            }
            
            if numberOfMismatches == 1, 
               let currentWordMutations = neededMutations[currentWord], 
               let candidateWordMutations = neededMutations[candidateWord], 
               candidateWordMutations == 0 || currentWordMutations + 1 < candidateWordMutations {
                neededMutations[candidateWord] = currentWordMutations + 1
                wordQueue.enqueue(candidateWord)
            }
        }
    }
    
    guard let result = neededMutations[target] else { return 0}
    return result
}
