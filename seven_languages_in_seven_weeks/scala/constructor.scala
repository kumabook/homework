class Persion(firstName: String ){
  println("Outer constructor")
  def this(firstName: String, lastName: String) {
    this(firstName)
    println("Inner constructor")
  }
  def talk() = println("Hi")
}

var bob = new Persion("Bob")
var bobTate = new Persion("Bob", "Tate")
