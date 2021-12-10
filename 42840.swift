import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var students = [
        (1, checkAnswer(answers, [1, 2, 3, 4, 5])), 
        (2, checkAnswer(answers, [2, 1, 2, 3, 2, 4, 2, 5])), 
        (3, checkAnswer(answers, [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]))
    ]
    
    let maxScore = students.max { $0.1 < $1.1 }!.1
    return students.filter { $0.1 == maxScore }.sorted { $0.0 < $1.0 }.map { $0.0 }
}

func checkAnswer(_ answers: [Int], _ pattern: [Int]) -> Int {
    return answers.enumerated().reduce(0, { $0 + ($1.1 == pattern[$1.0 % pattern.count] ? 1 : 0) })
}
