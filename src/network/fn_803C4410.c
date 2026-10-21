#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 lbl_805A1210;
extern s32 lbl_805A1220;

void* fn_803C4410(u32 arg0) {
    char* var_r3;

    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
        var_r3 = (char*) (lbl_805A1220 + arg0 * 0x140);
    } else {
        var_r3 = 0;
    }
    if (var_r3 != 0) {
        return var_r3 + 4;
    }
    return 0;
}
