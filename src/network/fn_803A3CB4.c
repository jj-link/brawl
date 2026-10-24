#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern s32 fn_803A58C8(u16 *);
extern u8 *lbl_805A1170;

int fn_803A3CB4(u16 *arg0) {
    s32 result;
    u16 value;
    u8 *context;
    s32 one;

    if (lbl_805A1170 != 0) {
        context = lbl_805A1170 + 0x3600;
    } else {
        context = 0;
    }

    if (arg0 == 0) {
        result = -3;
    } else if (context == 0) {
        result = -9;
    } else {
        value = *arg0;
        if ((value != 0xFFFF) && (value >= *(u16 *)(context + 0x14))) {
            result = -3;
        } else {
            result = 0;
        }
    }

    if (result != 0) {
        return result;
    }

    result = fn_803A58C8(arg0);
    if (result < 0) {
        return result;
    }

    one = 0x10000;
    *arg0 = one - 1;
    return result;
}
