#include <types.h>
#pragma force_active on

typedef struct {
    u16 unk0;
    u8 pad0[0x1E];
    u8 unk20;
    u8 pad1[0x15E3];
    s32 unk1604;
    u8 pad2[0x270];
    u16 unk1878;
} UnkObj;

typedef struct {
    u32 unk0;
    u32 unk4;
    s32 unk8;
    u32 unkC;
    u32 unk10;
    s32 unk14;
    s32 unk18;
} UnkSp8;

extern s32 fn_803AA4E8(void *arg0);
extern s32 fn_803AFF1C(void *arg0, s32 arg1, void **arg2, s32 arg3);
extern void fn_803A9644(void *a, void *b, s32 c);
extern s32 fn_803AFFAC(void *arg0, void *arg1, s32 arg2, u32 arg3, u32 *arg4);
extern void *fn_803B0134(void *arg0, s32 arg1);

s32 fn_803C0080(void *arg0, void *arg1, s32 arg2, s32 arg3, u32 arg4, u32 *arg5, s32 arg6) {
    UnkObj *self = (UnkObj *)arg0;
    void *spC;
    u32 sp8;
    u32 remaining;
    u32 rem;
    u32 diff;
    s32 result;
    UnkSp8 *node;
    u32 avail;

    *arg5 = 0;
    if (arg0 == 0) return 0xA;
    if (arg1 == 0) return 0xA;
    if ((self->unk1878 & 1) == 0 || fn_803AA4E8(arg0) == 0) return 9;

    if (arg3 != 0 || arg4 < self->unk0) {
        result = fn_803AFF1C(arg0, arg2, &spC, arg6);
        if (result != 0) return result;
        fn_803A9644(arg1, (void *)(((UnkSp8 *)spC)->unk8 + arg3), arg4);
        *arg5 = arg4;
        goto success;
    }
    if (arg3 == 0 && (arg4 & (self->unk0 - 1)) == 0) {
        result = fn_803AFFAC(arg0, arg1, arg2, arg4 >> self->unk20, &sp8);
        if (result != 0) return result;
        *arg5 += sp8 << self->unk20;
        if (sp8 != (arg4 >> self->unk20)) return 0x11;
        goto success;
    }
    if (arg3 == 0) {
        node = (UnkSp8 *)fn_803B0134(arg0, arg2);
        spC = node;
        if (node != 0) {
            avail = node->unk18 + node->unk14 - arg2;
            if (avail <= (arg4 >> self->unk20)) {
                fn_803A9644(arg1, (void *)node->unk8, avail << self->unk20);
                arg2 += avail;
                *arg5 += avail << self->unk20;
                arg4 -= avail << self->unk20;
            } else if (avail > (arg4 >> self->unk20)) {
                fn_803A9644(arg1, (void *)node->unk8, arg4);
                *arg5 += arg4;
                arg4 = 0;
            }
        }
        if (arg4 == 0) goto success;
        remaining = arg4 >> self->unk20;
        rem = (arg2 + remaining) % self->unk1604;
        if (remaining > rem) {
            diff = remaining - rem;
            result = fn_803AFFAC(arg0, (void *)((char *)arg1 + *arg5), arg2, diff, &sp8);
            if (result != 0) return result;
            *arg5 += sp8 << self->unk20;
            if (sp8 != diff) return 0x11;
            arg2 += diff;
            remaining -= diff;
        }
        if (remaining == 0) goto success;
        result = fn_803AFF1C(arg0, arg2, &spC, arg6);
        if (result != 0) return result;
        fn_803A9644((void *)((char *)arg1 + *arg5), (void *)((UnkSp8 *)spC)->unk8, remaining << self->unk20);
        *arg5 += remaining << self->unk20;
        goto success;
    }
    return 0xA;
success:
    return 0;
}
