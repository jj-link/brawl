#pragma force_active on

asm void fn_80405190(void) {
    nofralloc
    twi 31, r0, 0
    blr
}
