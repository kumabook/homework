def doChore(chore: String) : String = chore match {
  case "clean dishes" => "scrub, dry"
  case "cook dinner" => "chop, sizzle"
  case _ => "whine comlain"
}

println(doChore("clean dishes"))
println(doChore("now lawn"))
