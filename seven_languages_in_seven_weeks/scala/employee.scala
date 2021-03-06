class Person(val name: String) {
  def talk(message: String) = println(name + " says " + message)
  def id(): String = name
}

class Employee(override val name: String,
                        val number: Int) extends Person(name) {
  override def talk(message: String) {
    println(name + " with number " + number + " saya " + message)
  }
  override def id():String = number.toString
}

var employee = new Employee("Yoda", 4)
employee.talk("Extend or extend not. There is no try.")
