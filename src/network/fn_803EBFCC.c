#pragma force_active on

typedef unsigned int u32;
typedef int s32;

extern s32 fn_803D72BC(s32, s32);
extern s32 fn_803EB874(s32, s32);
extern s32 lbl_805A1268;
extern s32 lbl_805A126C;
extern s32 lbl_805A1270;

s32 fn_803EBFCC(s32 arg0) {
    if (lbl_805A126C == 1) {
        return -1;
    }
    lbl_805A126C = 1;
    if (lbl_805A1270 == 0) {
        s32 r = fn_803D72BC(0, 0);
        lbl_805A1270 = (r == 0);
        if (r != 0) {
            lbl_805A126C = 0;
            return -1;
        }
    }
    if (lbl_805A1268 == 0) {
        s32 r = fn_803EB874(arg0, 0);
        lbl_805A1268 = (r == 0);
        if (r == -1) {
            lbl_805A126C = 0;
            return -1;
        }
    }
    lbl_805A126C = 0;
    return 0;
}
