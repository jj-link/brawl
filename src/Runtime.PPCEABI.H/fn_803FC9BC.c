// Runtime.PPCEABI.H/fn_803FC9BC.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803FC9BC.s
// (MSL `scalb`-style helper). Behavior recovered from the target disassembly:
// splits x into mantissa/exponent with fn_804006F0 (frexp-style), adds the
// caller's exponent bias, and recomposes through fn_80400778 (ldexp-style).

extern double fn_804006F0(double x, int* exp);
extern double fn_80400778(double x, int exp);

double fn_803FC9BC(double x, int exp) {
    int e;
    double m = fn_804006F0(x, &e);
    e += exp;
    return fn_80400778(m, e);
}
