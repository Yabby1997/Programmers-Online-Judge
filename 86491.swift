import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var widths: [Int] = []
    var heights: [Int] = []
    
    for size in sizes {
        if size[0] > size[1] {
            widths.append(size[0])
            heights.append(size[1])
        } else {
            widths.append(size[1])
            heights.append(size[0])
        }
    }
    
    let maxWidth = widths.max()!
    let maxHeight = heights.max()!
    
    return maxWidth * maxHeight
}
