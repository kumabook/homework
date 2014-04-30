-module(translate_supervisor).
-behavior(supervisor).

-export([start_link/0, init/1]).

start_link() ->
  supervisor:start_link({local, translate_server}, translate_server, _Arg = []).

init(_Args) ->
    {ok, {{one_for_one, 1, 60},
          [{ translate_server,
             { translate_server, start_link, []},
               permanent, brutal_kill, worker, [translate_server]}]}}.
