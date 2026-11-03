#pragma force_active on
typedef unsigned int u32;
typedef int s32;
extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E4E7C(s32);
extern s32 fn_801E54E0(s32, s32, s32);
extern void fn_801E55DC(s32);

s32 fn_801E01C4(void) {
    u32 cmd;
    u32 data = 0;
    s32 err;
    if (fn_801E54E0(0, 1, 0) == 0) return 0;
    if (fn_801E4D4C(0, 1, 3) == 0) {
        fn_801E55DC(0);
        return 0;
    }
    cmd = 0xA1000800;
    err = fn_801E42E4(0, &cmd, 4, 1, 0) == 0;
    err |= fn_801E46FC(0) == 0;
    err |= fn_801E42E4(0, &data, 4, 1, 0) == 0;
    err |= fn_801E46FC(0) == 0;
    err |= fn_801E4E7C(0) == 0;
    fn_801E55DC(0);
    return !err;
}