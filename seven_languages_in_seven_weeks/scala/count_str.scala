val list = List("hello", "world", "goodbye", "world")
val length = list.foldLeft(0)((sum, value) => {
  sum + value.length
})
println(length)
