#pragma force_active on
extern int fn_801D6E1C(void);
extern void fn_8021AEC4(int p1, int p2, void *p3);
extern void fn_8027B2C8(void);

void fn_8027B298(void) {
    fn_8021AEC4(fn_801D6E1C(), 4, &fn_8027B2C8);
}
