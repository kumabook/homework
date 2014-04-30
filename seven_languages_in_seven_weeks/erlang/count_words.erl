-module(count_words).
-export([count_words/1]).

count_words(String) ->
  count_words(String, 1).
count_words([], Num) ->
  Num;
count_words([32|Tail], Num) ->
  count_words(Tail, Num+1);
count_words([_|Tail], Num) ->
  count_words(Tail, Num).
