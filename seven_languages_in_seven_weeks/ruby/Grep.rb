File.open("Tree.rb") do |f|
  p f.class
  f.each do |l|
    puts "#{f.lineno} #{l}"if /tree/ =~ l
  end
end
