// Runtime.PPCEABI.H/fn_803F6568.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F6568.s
// (MSL `__stdio_atexit`). Behavior recovered from the target disassembly:
// stores the address of __close_all into the __stdio_exit hook.

struct FILE;

extern int __close_all(struct FILE*);
extern int (*__stdio_exit)(struct FILE*);

void __stdio_atexit(void) {
    __stdio_exit = __close_all;
}
