#pragma force_active on

asm void fn_801D7AE4(void)
{
    nofralloc
loop:
    mfspr r4, 920
    rlwinm r4,r4,8,28,31
    cmpw r4,r3
    bgt loop
    blr
}
