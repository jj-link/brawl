// Runtime.PPCEABI.H/fn_803FBBF8.c
// Provenance: MSL strtod wrapper over fn_803FA804 (MSL __strtold core),
// reconstructed from the Brawl target (build/RSBE01_02/asm/Runtime.PPCEABI.H/
// fn_803FBBF8.s); behavior matches Melee's MSL strtod family (MIT reference).
// Sets errno (lbl_805A12E0) to ERANGE (0x22) on parse error or range overflow.

typedef struct __InStrCtrl {
    unsigned char* NextChar;
    int NullCharDetected;
} __InStrCtrl;

extern double fn_803FA804(int max_width, int (*read_proc)(void*, int, int),
                          void* read_arg, unsigned char** endptr,
                          int* overflow);
extern int fn_803FA078(void* isc, int ch, int mode);

extern double lbl_805A4BE8; // 0.0
extern double lbl_805A4BF0; // DBL_MIN 2.2250738585072014e-308
extern double lbl_805A4BF8; // DBL_MAX 1.7976931348623157e308
extern int lbl_805A12E0;    // errno

double fn_803FBBF8(const char* str) {
    register double value;
    register double abs_value;
    __InStrCtrl isc;
    int overflow;
    unsigned char* endptr;

    isc.NextChar = (unsigned char*) str;
    isc.NullCharDetected = 0;
    value = fn_803FA804(0x7FFFFFFF, fn_803FA078, &isc, &endptr, &overflow);
    abs_value = __fabs(value);
    if (overflow != 0 ||
        (lbl_805A4BE8 != value &&
         (abs_value < lbl_805A4BF0 || abs_value > lbl_805A4BF8))) {
        lbl_805A12E0 = 0x22;
    }
    return value;
}
