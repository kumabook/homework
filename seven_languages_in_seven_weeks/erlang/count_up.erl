-module(count_up).
-export([count_up/0]).

count_up() -> count_up(1).
count_up(10) -> 10;
count_up(N) ->
            io:write(N),
            io:nl(),
            count_up(N+1).
