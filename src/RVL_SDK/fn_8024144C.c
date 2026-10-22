#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u8 *fn_8023A038(u32);
extern u8 fn_80244B64(u32, s32);
extern u8 lbl_80529CF8[];

s32 fn_8024144C(u32 arg0, s32 arg1) {
    u8 *p;
    u8 saved;

    p = fn_8023A038(arg0);
    if (p == 0) {
        return 5;
    }
    if (p[0x81] & 0x40) {
        lbl_80529CF8[0x197E] = arg1;
        return 0;
    }
    saved = p[0x7F];
    if (saved == 5) {
        return 1;
    }
    p[0x7F] = 5;
    if (fn_80244B64(arg0, arg1) != 0) {
        return 1;
    }
    p[0x7F] = saved;
    return 3;
}
