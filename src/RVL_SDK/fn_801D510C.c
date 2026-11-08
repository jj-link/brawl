#pragma force_active on

asm void fn_801D510C(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    stfd f31, 0x18(r1)
    li r4, 0x0
    stw r3, 0xc(r1)
    stw r4, 0x8(r1)
    lfd f31, 0x8(r1)
    mtfsf 255, f31
    lfd f31, 0x18(r1)
    addi r1, r1, 0x20
    blr
}
