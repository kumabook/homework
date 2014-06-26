import scala.io._
import scala.actors._
import Actor._
import scala.xml.XML

object PageLoader {
  def getPageSize(url : String) = {
    val html = Source.fromURL(url).mkString
    val linkRegex = "<a.+href=\"(http.+)\".*>(.+)?</a>".r
    Map("length" -> html.length, "link" ->  linkRegex.findAllIn(html).size)
  }
}
val urls = List("http://www.amazon.com/",
                "http://www.twitter.com",
                "http://www.google.com",
                "http://www.cnn.com")

def timeMethod(method: () => Unit) = {
  val start = System.nanoTime
  method()
  val end = System.nanoTime
  println("Method took " + (end - start) / 1000000000.0 + " seconds.")
}

def getPageSizeSequentially() = {
  for (url <- urls) {
    val pageSize = PageLoader.getPageSize(url)
    println("Size for " + url + ": " + pageSize)
  }
}

def getPageSizeConcurrently() = {
  val caller = self

  for (url <- urls) {
    actor {
      caller ! (url, PageLoader.getPageSize(url))
    }
  }

  for (i <- 1 to urls.size) {
    receive {
      case (url, pageSize) =>
        println("Size for " + url + ": " + pageSize)
    }
  }
}

println("Sequential run:")
timeMethod { getPageSizeSequentially }

println("Concurrent run:")
timeMethod { getPageSizeConcurrently }
