li a7, 5
ecall
mv t0, a0

li a7, 5
ecall
mv t1, a0

slt s0, t1, t0
xori s0, s0, 1

mv a0, s0
li a7, 1
ecall