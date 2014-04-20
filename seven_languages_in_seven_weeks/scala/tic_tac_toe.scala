import scala.io._

class TicTacToeBoard(lines: Iterator[String]) {
  val points = Array.ofDim[Char](3, 3)
  lines.zipWithIndex.foreach { case(line:String, row:Int) =>
    for (col <- 0 until line.length) {
      points(row)(col) = line.charAt(col)
    }
  }
  def printBoard {
    for (row <- 0 until points.length) {
      for (col <- 0 until points.length) {
        print(points(row)(col))
      }
      print("\n")
    }
  }
  def result():Char = {
    Array[Char]('o', 'x').foreach { char:Char =>
      for (i <- 0 until points.length) {
        if (points(i).forall(_ == char)) {
          return char
        }
        if (points.forall(_(i) == char)) {
          return char
        }
        if (points.zipWithIndex.forall { case(row:Array[Char], index:Int) =>
          row(index) == char
        }) {
          return char
        }
      }
    }
    return ' '
  }
}


val in = Source.fromInputStream(System.in)

val lines = in.getLines
val board = new TicTacToeBoard(lines)
board.printBoard
val result = board.result
if (result != ' ') {
  println(board.result + " win.")
} else {
  println("No one win.")
}
