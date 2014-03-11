class Tree
  attr_accessor :children, :node_name

  def initialize(opts={})
    @node_name = opts.first.first
    p opts.first.last
    @children = opts.first.last.inject({})  do |children, (key, val)|
      Tree.new key => val
      children
    end
  end

  def visit_all(&block)
    visit &block
    @children.each {|c| c.visit_all &block}
  end

  def visit(&block)
    block.call self
  end
end


tree_data = {
  'grandap' => {
    'dad' => {'child 1' => [], 'child 2' => []},
    'uncle' => {'child 3' => [], 'child 4' => []}
  }
}

#ruby_tree = Tree.new( "Ruby", [Tree.new("Reia"), Tree.new("MacRuby")])
ruby_tree = Tree.new(tree_data)

puts "Visiting a node"
ruby_tree.visit {|node| puts node.node_name}
puts

puts "Visiting entire tree"
ruby_tree.visit_all {|node| puts node.node_name}

[
 [1, 11, 111],
 [2, 22, 222],
 [3, 33, 333]
].each {|a, b, c| puts "#{a}, #{b}, #{c}"}
