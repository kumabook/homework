valid([]).
valid([Head|Tail]) :-
    fd_all_different(Head),
    valid(Tail).

sublist_length([], _).
sublist_length([Head | Tail], Length) :-
    length(Head, Length),
    sublist_length(Tail, Length).
position_at_index(Width, Index, X, Y) :-
    X is Index // Width,
    Y is Index mod Width.

rows(Puzzle, Rows, Width) :- rows(Puzzle, Rows, Width, 0).
rows(_, Rows, Width, Index) :-
    Index is Width * Width, length(Rows, Width),
    sublist_length(Rows, Width).
rows([Head | Tail], Rows, Width, Index) :-
    position_at_index(Width, Index, X, Y),
    nth0(X, Rows, Row),
    nth0(Y, Row, Head),
    Index_ is Index + 1,
    rows(Tail, Rows, Width, Index_).

cols(Puzzle, Cols, Width) :- cols(Puzzle, Cols, Width, 0).
cols(_, Cols, Width, Index) :-
    Index is Width * Width, length(Cols, Width),
    sublist_length(Cols, Width).
cols([Head | Tail], Cols, Width, Index) :-
    position_at_index(Width, Index, X, Y),
    nth0(Y, Cols, Col),
    nth0(X, Col, Head),
    Index_ is Index + 1,
    cols(Tail, Cols, Width, Index_).

squares(Puzzle, Squares, Width) :- squares(Puzzle, Squares, Width, 0).
squares(_, Squares, Width, Index) :-
    Index is Width * Width, length(Squares, Width),
    sublist_length(Squares, Width).
squares([Head | Tail], Squares, Width, Index) :-
    position_at_index(Width, Index, X, Y),
    Square_Width is floor(sqrt(Width)),

    Square_X is (X mod Width // Square_Width),
    Square_Y is (Y mod Width // Square_Width),
    Square_Num is (Square_X + Square_Y * Square_Width),

    Index_X is (Index mod Square_Width),
    Index_Y is (Square_Width * ((Index mod (Width * Square_Width)) // Width)),
    Square_Index is (Index_X + Index_Y),

    nth0(Square_Num, Squares, Square),
    nth0(Square_Index , Square, Head),
    Index_ is Index + 1,
    squares(Tail, Squares, Width, Index_).

sudoku(Puzzle, Solution) :-
    Solution = Puzzle,
    length(Puzzle, L),
    member(L , [4, 9, 16]),
    W is floor(sqrt(L)),

    fd_domain(Puzzle, 1, W),

    rows(Puzzle, Rows, W),
    cols(Puzzle, Cols, W),
    squares(Puzzle, Squares, W),

    valid(Rows),
    valid(Cols),
    valid(Squares).

/*
  Puzzle = [S11, S12, S13, S14,
              S21, S22, S23, S24,
              S31, S32, S33, S34,
              S41, S42, S43, S44],

    Row1 = [S11, S12, S13, S14],
    Row2 = [S21, S22, S23, S24],
    Row3 = [S31, S32, S33, S34],
    Row4 = [S41, S42, S43, S44],

    Col1 = [S11, S21, S31, S41],
    Col2 = [S12, S22, S32, S42],
    Col3 = [S13, S23, S33, S43],
    Col4 = [S14, S24, S34, S44],

    Square1 = [S11, S12, S21, S22],
    Square2 = [S13, S14, S23, S24],
    Square3 = [S31, S32, S41, S42],
    Square4 = [S33, S34, S43, S44].*/