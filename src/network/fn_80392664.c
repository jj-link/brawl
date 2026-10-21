#pragma force_active on
typedef int s32;

extern void fn_8039094C(void);
extern void fn_80390950(s32);
extern void fn_803A7784(s32, s32);

void fn_80392664(s32 arg0, s32 arg1, s32 arg2) {
    fn_8039094C();
    if (arg2 >= 0) {
        fn_803A7784(arg2, 2);
    }
    fn_80390950(arg0);
}
