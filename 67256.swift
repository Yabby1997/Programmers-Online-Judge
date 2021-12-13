import Foundation

struct Coordinate {
    let row: Int
    let col: Int
    
    init(_ row: Int, _ col: Int) {
        self.row = row
        self.col = col
    }
    
    func distanceTo(_ another: Coordinate) -> Int {
        return abs(self.row - another.row) + abs(self.col - another.col)
    }
}

func solution(_ numbers:[Int], _ hand:String) -> String {
    let keyPad: [Int: Coordinate] = [
        1: Coordinate(0, 0), 2: Coordinate(0, 1), 3: Coordinate(0, 2),
        4: Coordinate(1, 0), 5: Coordinate(1, 1), 6: Coordinate(1, 2),
        7: Coordinate(2, 0), 8: Coordinate(2, 1), 9: Coordinate(2, 2),
        0: Coordinate(3, 1)
    ]
    
    var leftThumb = Coordinate(3, 0)
    var rightThumb = Coordinate(3, 2)
    
    return numbers.reduce("") {
        guard let coordinate = keyPad[$1] else { return $0 + "" }
        let leftThumbDistance = coordinate.distanceTo(leftThumb)
        let rightThumbDistance = coordinate.distanceTo(rightThumb)
        if coordinate.col == 0 || (coordinate.col == 1 && (leftThumbDistance < rightThumbDistance || (leftThumbDistance == rightThumbDistance && hand == "left"))) {
            leftThumb = coordinate
            return $0 + "L"
        } else {
            rightThumb = coordinate
            return $0 + "R"
        }
    }
}
