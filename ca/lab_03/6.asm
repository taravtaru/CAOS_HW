main:
    li a7, 5
    ecall
    mv t0, a0
    
    li a7, 5
    ecall
    mv t1, a0
    
    slli s0, t0, 3
    sub s0, s0, t0
    sub s0, s0, t0
    
    slli s1, t1, 2
    sub s1, s1, t1
    
    sub a0, s0, s1
    li a7, 1
    ecall
