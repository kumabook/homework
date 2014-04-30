-module(print_result).
-export([print/1]).

print(success) ->
         io:put_chars("success"),
         io:nl();
print({ error, Message}) ->
         io:put_chars("error: " ++ Message),
         io:nl().
