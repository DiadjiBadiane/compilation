
.data

start: .word 0
sum: .word 100
end: .word 50

.text

main:
    addiu $29, $29, -8
    ori   $8, $0, 0x5
    ori   $9, $0, 0x6
    addu  $8, $8, $9
    ori   $9, $0, 0x7
    ori   $10, $0, 0x8
    div   $9, $10
    teq $10, $0
    mfhi  $9
    addu  $8, $8, $9
    sw    $8, 0($29)
    lui   $8, 0x1001
    lw    $8, 0($8)
    lw    $9, 0($29)
    lui   $10, 0x1001
    lw    $10, 8($10)
    subu  $9, $9, $10
    ori   $10, $0, 0x4
    mult  $9, $10
    mflo  $9
    srlv  $8, $8, $9
    sw    $8, 4($29)
    addiu $29, $29, 8
    ori   $2, $0, 0xa
    syscall
