DimList := Object clone
DimList dim := method(x, y,
    self dim_list := List clone
    for (i, 1, x,
        li := List clone
        for (j, 1, y,
            li append(nil))
        self dim_list append(li))
    self dim_list;
)
DimList set := method(x, y, value,
    (self dim_list at(x)) atPut(y, value))
DimList get := method(x, y,
    (self dim_list at(x)) at(y))

test := DimList clone
test dim(2, 2)
test set(0, 0, 1)
test get(0, 0) println