// Runtime.PPCEABI.H/fn_803F646C.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F646C.s
// (MSL float floating-point classifier `__fpsclassifyfloat`).
// Behavior recovered from the target disassembly:
//   1 = NaN, 2 = infinity, 3 = zero, 4 = normal, 5 = subnormal.

int fn_803F646C(float value) {
    union {
        float f;
        unsigned long bits;
    } u;

    u.f = value;
    switch (u.bits & 0x7F800000) {
        case 0x7F800000:
            return (u.bits & 0x007FFFFF) != 0 ? 1 : 2;
        case 0:
            return (u.bits & 0x007FFFFF) != 0 ? 5 : 3;
        default:
            return 4;
    }
}
