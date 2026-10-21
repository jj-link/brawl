#pragma force_active on
extern int fn_801D6E1C(void);
extern void fn_8021AEC4(int, int, void (*)(void));
extern void fn_8027B1D4(void);

void fn_8027B1A4(void) {
    fn_8021AEC4(fn_801D6E1C(), 1, fn_8027B1D4);
}
