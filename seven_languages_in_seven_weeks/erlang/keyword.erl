-module(keyword).
-export([get/2]).

get(List, Keyword) ->
  lists:foldl(fun(Pair, Value) ->
    { Key, Val} = Pair,
    if
      Key == Keyword -> Val;
      true -> Value
    end
  end,
  "Not Found",
  List).
