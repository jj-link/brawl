#pragma force_active on
extern int fn_803B9BC4(void);
extern void fn_803C2E90(void);
extern void fn_803C290C(int);

void fn_803C2D74(void) {
    int temp_r3;

    temp_r3 = fn_803B9BC4();
    if (temp_r3 == 0) {
        fn_803C2E90();
    }
    fn_803C290C(temp_r3);
}
