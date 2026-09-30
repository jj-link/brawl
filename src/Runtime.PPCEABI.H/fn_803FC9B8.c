// Runtime.PPCEABI.H/fn_803FC9B8.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803FC9B8.s
// (MSL `atexit`, a tail call to `__register_atexit`).
// Behavior recovered from the target disassembly.

typedef void (*atexit_func_t)(void);

extern int __register_atexit(atexit_func_t func);

int fn_803FC9B8(atexit_func_t func) {
    return __register_atexit(func);
}
