#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Ctx {
    s32 pad[7];
    s32 unk1C;
    s32 pad2[5];
    s32 unk34;
};

extern s32 fn_803B5650(void *, void **, u32);
extern s32 fn_803B8708(void *, u16, s32 *, void **);
extern s32 fn_803B9170(void *, u32, s32 *, void **);
extern s32 fn_803B96F8(void *, u32, s32 *, void **);

s32 fn_803B5780(void *arg0, u32 arg1, u32 arg2, u32 arg3, s32 *arg4, s32 *arg5) {
    u32 limit;
    u32 r30;
    s32 r29;
    u32 r28;
    s32 r27;
    u32 r26;
    s32 spC;
    void *sp8;
    s32 ret;
    struct Ctx *ctx = (struct Ctx *)arg0;

    *arg4 = -1;
    *arg5 = -1;
    r27 = 0;
    r30 = 0;
    r29 = -1;
    limit = ctx->unk34 + 2;
    r28 = 0;
    if (arg1 < 2 || arg1 >= limit) {
        arg1 = 2;
    }
    if (arg2 < 2 || arg2 >= limit) {
        arg2 = limit - 1;
    }
    r26 = arg1;
    ret = fn_803B5650(arg0, &sp8, arg1);
    if (ret != 0) {
        return ret;
    }
    *(u16 *)((u8 *)sp8 + 2) = 0;

    while (arg1 <= arg2) {
        if (limit <= arg1) {
            arg1 = 2;
        }
        switch (ctx->unk1C) {
        case 0:
            ret = fn_803B8708(arg0, (u16)arg1, &spC, &sp8);
            break;
        case 1:
            ret = fn_803B9170(arg0, arg1, &spC, &sp8);
            break;
        case 2:
            ret = fn_803B96F8(arg0, arg1, &spC, &sp8);
            break;
        default:
            ret = 0xF;
            break;
        }
        if (ret != 0) {
            return ret;
        }
        if (spC == 0) {
            if ((u32)(*arg4 + 0x10000) == 0xFFFF) {
                *arg4 = (s32)arg1;
            }
            r30++;
            if (r30 >= arg3) {
                *arg5 = (s32)arg1;
                return 0;
            }
        } else {
            if (r28 < r30) {
                r29 = *arg4;
                r28 = r30;
            }
            *arg4 = -1;
            r30 = 0;
        }
        arg1++;
        if (r27 == 0 && r30 == 0 && arg1 > 2 && arg1 == arg2) {
            arg2 = r26;
            arg1 = 2;
            r27 = 1;
        }
    }

    if (r28 < r30) {
        r29 = *arg4;
        r28 = r30;
    }
    if (r28 != 0) {
        *arg4 = r29;
        *arg5 = (s32)(r28 + r29) - 1;
    }
    return 0;
}
