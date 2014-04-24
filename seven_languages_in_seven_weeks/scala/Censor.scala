import scala.io.Source
trait Censor {
  def censor(str :String, words :Map[String, String]) = {
    words.foldLeft(str)((_str, word) => _str.replaceAll(word._1, word._2))
  }
}

class Book(val contents:String, words:Map[String, String]) extends Censor {
  def raw = contents
  def censored_contents = censor(contents, words)
}

var source = Source.fromFile("censor.txt")
var words = Map[String, String]()
val lines = source.getLines
lines.foreach((line) => {
  val l = line.split(" ")
  words += l(0) -> l(1)
})
source.close

// words = Map("Shoot" -> "Pucky","Darn" -> "Beans")
val book = new Book("Shoot is Darn", words);
println(book.raw)
println(book.censored_contents)
