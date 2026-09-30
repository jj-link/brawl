// Runtime.PPCEABI.H/fn_803F64D0.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F64D0.s
// (MSL `__signbitd`-style helper). Behavior recovered from the target
// disassembly: returns the raw sign bit (0x80000000 mask) of a double.

int fn_803F64D0(double value) {
    union {
        double d;
        struct {
            unsigned long high;
            unsigned long low;
        } words;
    } bits;

    bits.d = value;
    return bits.words.high & 0x80000000;
}
