main:
    li a7, 5
    ecall
    mv t0, a0
    
    li a7, 5
    ecall
    mv t1, a0
    
    li t2, 6
    li t3, 3
    
    mul s0, t0, t2
    mul s1, t1, t3
    
    sub a0, s0, s1
    li a7, 1
    ecall
