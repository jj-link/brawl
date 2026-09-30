// Runtime.PPCEABI.H/fn_803F64E8.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F64E8.s
// (MSL double floating-point classifier `__fpsclassifyd`).
// Behavior recovered from the target disassembly:
//   1 = NaN, 2 = infinity, 3 = zero, 4 = normal, 5 = subnormal.

int fn_803F64E8(double value) {
    union {
        double d;
        struct {
            unsigned long high;
            unsigned long low;
        } words;
    } bits;

    int cls;
    bits.d = value;
    switch (bits.words.high & 0x7FF00000) {
        case 0x7FF00000:
            if ((bits.words.high & 0x000FFFFF) != 0 || bits.words.low != 0) {
                cls = 1; /* NaN */
            } else {
                cls = 2; /* infinity */
            }
            break;
        case 0:
            if ((bits.words.high & 0x000FFFFF) != 0 || bits.words.low != 0) {
                cls = 5; /* subnormal */
            } else {
                cls = 3; /* zero */
            }
            break;
        default:
            cls = 4; /* normal */
            break;
    }
    return cls;
}
