li a7, 5
ecall
mv t0, a0

li a7, 5
ecall
mv t1, a0

div s0, t0, t1
mul s0, s0, t1

div s1, t0, t1
mul s1, s0, t1
sub s1, t0, s0

add s2, s0, s1

mv a0, s2
li a7, 1
ecall