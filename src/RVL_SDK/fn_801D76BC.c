#pragma schedule off
#pragma force_active on

asm void fn_801D76BC(register unsigned int address, register unsigned int length)
{
    nofralloc
    cmplwi r4, 0
    blelr
    clrlwi r5, r3, 27
    add r4, r4, r5
    addi r4, r4, 0x1f
    srwi r4, r4, 5
    mtctr r4
loop:
    dcbi r0, r3
    addi r3, r3, 0x20
    bdnz loop
    blr
}

#pragma force_active reset
#pragma schedule reset
