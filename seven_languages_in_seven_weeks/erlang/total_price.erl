-module(total_price).
-export([total_price_list/1]).

total_price_list(List) ->
  [{ Item, Quantity * Price} || { Item, Quantity, Price} <- List].