#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern s32 fn_80334DE4(s32, s32, void*, s32);
extern s32 fn_80337350(s32, s32, void*);
extern s32 fn_80339410(void);
extern s32 lbl_805A0F70;

s32 fn_80336928(s32 arg0, s32 arg1) {
    u8 buf[256];
    s32 idx;

    if (lbl_805A0F70 == 0 || fn_80339410() == 0) {
        return 0;
    }
    idx = fn_80334DE4(arg0, arg1, buf, 0xFF);
    if (idx == -1) {
        return 0;
    }
    buf[idx] = 0;
    return fn_80337350(-1, 0, buf) == 0;
}
