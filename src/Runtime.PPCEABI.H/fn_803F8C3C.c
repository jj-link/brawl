// Runtime.PPCEABI.H/fn_803F8C3C.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F8C3C.s
// (MSL `rand`/`srand` pair over the shared rand-state word lbl_8059FF58 in
// .sdata, initialized to 1 by its owning data unit).
// Behavior recovered from the target disassembly.

extern unsigned long lbl_8059FF58;

int rand(void) {
    lbl_8059FF58 = lbl_8059FF58 * 0x41C64E6D + 0x3039;
    return (int)((lbl_8059FF58 >> 16) & 0x7FFF);
}

void fn_803F8C5C(int seed) {
    lbl_8059FF58 = seed;
}
