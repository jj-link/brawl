#include <types.h>
#pragma force_active on

extern "C" s64 fn_803F1470(s64, s64);

struct Obj {
    char pad0[0x80];
    u8 unk80;
    u8 unk81;
    char pad82[0x2];
    u32 unk84;
    char pad88[0x4];
    u32 unk8C;
    u32 unk90;
    char pad94[0xC];
    u32 unkA0;
    char padA4[0x5C];
    s32 unk100;
    u32 unk104;
};

extern "C" s32 fn_801CF120(Obj* self, s32* out, u32* rem, s32* cnt) {
    u32 val;

    if (self->unkA0 == 0) {
        return 0;
    }
    if (self->unk100 == 0) {
        val = self->unk104;
    } else if (self->unk100 == 1) {
        val = (u32)fn_803F1470((s64)(s32)self->unk104 * (s32)self->unk84, 1000);
    }
    *cnt = 0;
    if (val >= self->unk90) {
        if (self->unk81 != 0) {
            u32 wrap = self->unk8C;
            s32 diff = (s32)(val - self->unk90);
            s32 d = (s32)(self->unk90 - wrap);
            *cnt = diff / d + 1;
            val = wrap + (u32)(diff % d);
        } else {
            return 0;
        }
    }
    *out = (s32)val / (s32)self->unkA0;
    if (self->unk80 == 2) {
        *rem = val % self->unkA0;
    }
    return 1;
}
