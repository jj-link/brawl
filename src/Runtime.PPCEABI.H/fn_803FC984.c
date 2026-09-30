// Runtime.PPCEABI.H/fn_803FC984.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803FC984.s
// (MSL `abort`). Behavior recovered from the target disassembly: raises the
// abort signal, marks the abort flag, and terminates through `exit`.

typedef void (*__signal_func_ptr)(int);

extern int fn_803FA1D0(int signum);
extern void exit(int status);
extern unsigned long lbl_805A12F0;

void fn_803FC984(void) {
    fn_803FA1D0(1);
    lbl_805A12F0 = 1;
    exit(1);
}
