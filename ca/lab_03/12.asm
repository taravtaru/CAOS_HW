li a7, 5
ecall
mv t0, a0

li a7, 5
ecall
mv t1, a0

li s0, 1

sll t1, s0, t1

or t0, t0, t1

mv a0, t0
li a7, 1
ecall