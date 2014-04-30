-module(tic_tac_toe).
-export([judge/1]).


judge(Board) ->
  case Board of
    [ X, X, X,
      _, _, _,
      _, _, _] when X /= n -> X;
    [ _, _, _,
      X, X, X,
      _, _, _] when X /= n -> X;
    [ _, _, _,
      _, _, _,
      X, X, X] when X /= n -> X;

    [ X, _, _,
      X, _, _,
      X, _, _] when X /= n -> X;
    [ _, X, _,
      _, X, _,
      _, X, _] when X /= n -> X;
    [ _, _, X,
      _, _, X,
      _, _, X] when X /= n -> X;

    [ X, _, _,
      _, X, _,
      _, _, X] when X /= n -> X;
    [ _, _, X,
      _, X, _,
      X, _, _] when X /= n -> X;

    _Else ->
      case [X || X <- Board, X==n] of
        [] -> no_winner;
        _ -> cat
      end
  end.
