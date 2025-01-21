li a7, 5
ecall
mv t0, a0

li a7, 5
ecall
mv t1, a0

li t2, 10

slti t0, t0, -5
slt t1, t2, t1

and s0, t0, t1

mv a0, s0
li a7, 1
ecall