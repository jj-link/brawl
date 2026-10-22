#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 fn_8020CAD4(void);
extern s32 fn_8020B8A8(s32, s32, s32, s32, s32);
extern s32 fn_8020CAEC(s32);

s32 fn_8020BA48(s32 arg0, u8 *arg1, s32 arg2) {
    s32 result;

    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    result = fn_8020B8A8(arg0, arg2, 0, 0, 1);
    if (result >= 0) {
        *(s32 *)arg1 = result;
        arg1[0x8A] = 1;
        return 0;
    }
    return fn_8020CAEC(result);
}
