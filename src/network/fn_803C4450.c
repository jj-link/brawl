#pragma force_active on
typedef unsigned int u32;
typedef int s32;

u32 fn_803C7DE4(void);
extern u32 lbl_805A1210;
extern s32 lbl_805A1220;

void* fn_803C4450(s32 arg0) {
    char* var_r3;
    u32 temp;

    if (arg0 != 0) {
        temp = fn_803C7DE4();
        if (temp < lbl_805A1210 && lbl_805A1220 != 0) {
            var_r3 = (char*) (lbl_805A1220 + temp * 0x140);
        } else {
            var_r3 = 0;
        }
        if (var_r3 != 0) {
            return var_r3 + 4;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
