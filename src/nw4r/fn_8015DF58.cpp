#pragma force_active on
typedef unsigned short u16;
typedef int s32;

extern "C" {
extern u16 lbl_8059E868;

s32 fn_8015DF58(void) {
    switch ((s32) lbl_8059E868) {
    case 0:
        return 3;
    case 1:
        return 2;
    default:
        return 3;
    }
}
}
