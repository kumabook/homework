fib := method(i,
     if (i == 0,
         0,
             if (i == 1,
                1,
                fib(i - 2) + fib(i - 1))));
fib(1) println
fib(2) println
fib(3) println
fib(4) println

"" println

fib_loop := method(i,
    value := 0;
    one_value := 0;
    second_value := 1;
    for (index, 1, i, 1,
        value = one_value + second_value;
        second_value = one_value;
        one_value = value);
    value);

fib_loop(1) println
fib_loop(2) println
fib_loop(3) println
fib_loop(4) println

"2 dim list sum" println

2dim_list := list(list(1,2,3,4), list(5,6,7,8), list(9, 10, nil))
2dim_list myAverage := method(
    sum := 0;
    count := 0;
    for(i, 0, 2dim_list size - 1,
        li := 2dim_list at(i);
        for(j, 0, li size - 1,
            val := li at(j)
            if (val proto == 0, IOException raise("not number"));
            sum = val + sum;
            count = count + 1;
            ))
    sum / count;
);
2dim_list mySum := method(
    sum := 0;
    for(i, 0, 2dim_list size - 1,
        li := 2dim_list at(i);
        for(j, 0, li size - 1,
            val := li at(j)
            sum = val + sum;
            ))
    sum println
    sum);