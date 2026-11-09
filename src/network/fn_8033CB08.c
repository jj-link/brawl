#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern u8 fn_8033A77C(void);
extern s32 fn_8033A7DC(void);
extern s32 fn_8033AA6C(void);
extern int lbl_805A0FA8;

s32 fn_8033CB08(void) {
    s32 var_r31 = -1;
    s32 var_r30;
    s32 var_r0;

    if (lbl_805A0FA8 == 0) {
        return 0;
    }
    var_r30 = *(s32 *)(lbl_805A0FA8 + 0x1C);
    var_r30 &= fn_8033A7DC();
    if (fn_8033AA6C() != 0) {
        if (*(s32 *)(lbl_805A0FA8 + 0x1B4) == 0xF) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
    } else {
        var_r0 = 1;
    }
    if (var_r0 == 0) {
        var_r30 &= ~(1 << fn_8033A77C());
    }
    if ((var_r30 ^ fn_8033A7DC()) == 0) {
        var_r31 = 1;
    } else if ((var_r30 & fn_8033A7DC()) == 0) {
        var_r31 = 0;
    }
    if (var_r31 != -1) {
        *(s32 *)(lbl_805A0FA8 + 0x28) = (var_r31 - 1) == 0;
    }
    return *(s32 *)(lbl_805A0FA8 + 0x28);
}
