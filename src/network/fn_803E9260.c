#include <types.h>
#pragma force_active on

typedef struct {
    u16 unk0;
    u8 pad2[6];
    u32 unk8;
    u8 pad0C[0x14];
    u8 unk20;
    u8 pad21[0x161F];
    u32 unk1640;
    u8 pad1644[0x948];
    u16 unk1F8C;
} UnkStruct;

typedef struct {
    u32 unk0;
    u32 unk4;
    u8 *unk8;
} UnkSp8;

extern s32 fn_803D6D64(void *a);
extern void fn_803D6224(void *a, void *b, s32 c);
extern s32 fn_803DA674(void *a, u32 b, void **c, s32 d);
extern s32 fn_803DA758(void *a, void *b, s32 c);
extern s32 fn_803DA7E4(void *a, void *b, u32 c, u32 d, u32 *e);

s32 PFSEC_WriteData(void *arg0, void *arg1, u32 arg2, u32 arg3, u32 arg4, u32 *arg5, s32 arg6) {
    UnkStruct *self = (UnkStruct *)arg0;
    void *spC;
    u32 sp8;
    u32 remaining;
    u32 rem;
    u32 diff;
    s32 result;

    *arg5 = 0;
    if (!(self->unk1F8C & 1) || fn_803D6D64(arg0) == 0 || (self->unk1F8C & 2)) {
        return 9;
    }
    if (!(arg2 < self->unk8 && arg3 < self->unk0 && arg3 + arg4 <= self->unk0)) {
        if (arg3 != 0) return 0xA;
    }
    if (arg3 != 0 || arg4 < self->unk0) {
        result = fn_803DA674(arg0, arg2, &spC, arg6);
        if (result != 0) return result;
        fn_803D6224((void *)(((UnkSp8 *)spC)->unk8 + arg3), arg1, arg4);
        result = fn_803DA758(arg0, spC, arg6);
        if (result != 0) return result;
        *arg5 = arg4;
        goto success;
    }
    if (arg3 == 0 && (arg4 & (self->unk0 - 1)) == 0) {
        result = fn_803DA7E4(arg0, arg1, arg2, arg4 >> self->unk20, &sp8);
        if (result != 0) return result;
        *arg5 = sp8 << self->unk20;
        if (sp8 != (arg4 >> self->unk20)) return 0x11;
        goto success;
    }
    if (arg3 == 0) {
        remaining = arg4 >> self->unk20;
        rem = (arg2 + remaining) % self->unk1640;
        if (remaining > rem) {
            diff = remaining - rem;
            result = fn_803DA7E4(arg0, arg1, arg2, diff, &sp8);
            if (result != 0) return result;
            *arg5 = sp8 << self->unk20;
            if (sp8 != diff) return 0x11;
            arg2 += diff;
            remaining -= diff;
        }
        if (remaining == 0) goto success;
        result = fn_803DA674(arg0, arg2, &spC, arg6);
        if (result != 0) return result;
        fn_803D6224(((UnkSp8 *)spC)->unk8, (u8 *)arg1 + *arg5, remaining << self->unk20);
        result = fn_803DA758(arg0, spC, arg6);
        if (result != 0) return result;
        *arg5 += remaining << self->unk20;
        goto success;
    }
    return 0xA;
success:
    return 0;
}
