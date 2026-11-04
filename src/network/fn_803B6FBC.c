#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Ctx {
    u8 pad0[0x2];
    u16 unk2;
    u8 pad4[0x8];
    u32 unkC;
    u8 pad10[0x12];
    u8 unk22;
} Ctx;

extern s32 fn_803AAA04(void *, u32, u32, u32, u32 *);

s32 fn_803B6FBC(Ctx *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 sp8;
    s32 ret;
    s32 result;
    u32 idx;
    u32 diff;
    u32 q;

    diff = arg2 - arg0->unk2;
    q = diff / arg0->unkC;
    result = 0;
    if (q != 0) {
        idx = 0;
        arg2 = diff - q * arg0->unkC;
    } else {
        arg2 = arg2 + arg0->unkC;
        idx = 1;
    }
    while (idx < arg0->unk22) {
        ret = fn_803AAA04(arg0, arg1, arg2, arg3, &sp8);
        if (ret != 0 && result == 0) {
            result = ret;
        }
        if (sp8 != arg3) {
            result = 0x11;
        }
        idx++;
        arg2 += arg0->unkC;
    }
    return result;
}
