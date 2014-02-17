reverse([], []).
reverse([X|Xs], Ys) :-
    reverse(Xs, Zs), append(Zs, [X], Ys).

min_list([X | Xs], M) :- min_list(Xs, X, M).
min_list([], M, M).
min_list([X | Xs], Y, M) :- X < Y, min_list(Xs, X, M).
min_list([X | Xs], Y, M) :- X >= Y, min_list(Xs, Y, M).

sort_list([X| Xs], Ys) :- sort_list(Xs, [X], Ys).
sort_list([], Ys, Ys).
sort_list([X|Xs], [Head|Tail], Ys) :-
    X < Head,
    sort_list(Xs, [X|[Head|Tail]], Ys).
sort_list([X|Xs], [Head|Tail], Ys) :-
    X >= Head,
    sort_list(Xs, Tail, Ys), append([Head], [X|Tail], Ys).
sort(Answer, [Head|[]]) :- sort_list(Answer, Head, []).
sort(Answer, [Head|Tail]) :- sort_list(SubAnswer, Tail), sort_list(Answer, Head, SubAnswer).

