#pragma force_active on
extern int fn_8020CDB8(void);
extern int fn_8020D310(void*);
extern void fn_803D80C4(void*);
extern int lbl_805A127C;
extern char lbl_80598098[0x40];

int fn_803ECFB8(void* arg0) {
    if (arg0 == 0) {
        return -0x14;
    }
    if (lbl_805A127C == 0) {
        if (fn_8020CDB8() != 0) {
            return -0x15;
        }
        if (fn_8020D310(lbl_80598098) != 0) {
            return -0x15;
        }
        lbl_805A127C += 1;
    }
    fn_803D80C4(arg0);
    return 0;
}
