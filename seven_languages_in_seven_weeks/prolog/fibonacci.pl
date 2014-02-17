fibo(N, F) :-
    N > 1,
    N1 is N -1, fibo(N1, F1),
    N2 is N -2, fibo(N2, F2),
    F is F1 + F2.
fibo(0, 0).
fibo(1, 1).