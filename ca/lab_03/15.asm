main:
    li a7, 5
    ecall
    mv t0, a0

    li a7, 5
    ecall
    mv t1, a0

    addi t1, t1, 3
    
    beq t0, t1, equal
    
    li s0, 1
    j end

equal:
    li s0, 0

end:
    mv a0, s0
    li a7, 1
    ecall
