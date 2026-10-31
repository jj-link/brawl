#include <types.h>
#pragma force_active on

extern s32 fn_803A1678(u16, s32, s32);

typedef struct {
    u16 f0;
    u8 f2;
    u8 f3;
} S;

s32 fn_803A129C(void *arg0, const S *arg1) {
    u16 val0;
    u8 val2;
    s32 val3;
    u8 val4;
    u8 val6;
    s32 r4;
    s32 result;

    val3 = *(u8*)((const char*)arg1 + 3);
    val0 = arg1->f0;
    val2 = arg1->f2;
    result = fn_803A1678(val0, val2, val3);
    if (result == -1) {
        return -2;
    }
    val4 = *(u8*)((const char*)arg1 + 4);
    val6 = *(u8*)((const char*)arg1 + 6);
    if (val4 > 0x17 || val6 > 0x3b) {
        r4 = -1;
    } else {
        r4 = val6 + val4 * 0x3c;
    }
    if (r4 == -1 || *(u8*)((const char*)arg1 + 5) > 0x3c) {
        return -2;
    }
    *(s32*)arg0 = r4 + result * 0x5a0;
    return 0;
}
