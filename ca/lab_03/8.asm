li a7, 5
ecall
mv t0, a0

li a7, 5
ecall
mv t1, a0
mv s1, t1

addi t0, t0, 5
addi t1, t1, 10
addi s1, s1, -1

div t0, t0, t1
div t1, t0, s1

mv a0, t1
li a7, 1
ecall

