// Runtime.PPCEABI.H/fn_803FC8AC.c
// Debug-console output, with fallback to the normal sink.

extern int fn_801D536C(void);
extern int fn_802285C0(int);
extern int fn_80228608(void*, void*);
extern int fn_80405520(void*, void*, void*, void*);
extern int lbl_805A12E8;

int fn_803FC8AC(void* a, void* b, void** c, void* d) {
    int ret;

    if ((fn_801D536C() & 0x20000000) == 0) {
        ret = 0;
        if (lbl_805A12E8 == 0) {
            ret = fn_802285C0(57600);
            if (ret == 0) {
                lbl_805A12E8 = 1;
            }
        }
        if (ret != 0) {
            return 1;
        }
        if (fn_80228608(b, *c) != 0) {
            *c = 0;
            return 1;
        }
    }
    fn_80405520(a, b, c, d);
    return 0;
}
