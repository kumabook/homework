-module(translate_server).
-behavior(gen_server).
-export([translate/1, start_link/0, init/1, handle_call/3]).
-export([handle_cast/2, code_change/3, handle_info/2, terminate/2]).

start_link() ->
  gen_server:start_link({ local, translate_server}, translate_server, [], []).

translate(Word) ->
  gen_server:call(translate_server, {trans, Word}, 1000).

init(_Args) ->
  process_flag(trap_exit, true),
  io:format("~p starting~n", [translate_server]),
  {ok, 0}.

handle_call({trans, Word}, _From, Chs) ->
  io:format("~p", [Word]),
  {reply, Word, Chs + 1}.

handle_cast(_Msg, Chs) -> {noreply, Chs}.
handle_info(_Info, N) -> {noreply, N}.
code_change(_OldVsn, N, _Extra) -> {ok, N}.

terminate(_Reason, _N) ->
  error_logger:error_msg("~p terminate~n", [translate_server]),
  ok.
 
