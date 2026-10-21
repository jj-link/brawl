#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C4020(s32 a, s32 b, u8 c);
extern "C" unsigned char lbl_27_bss_1CC[];

class Inner {
public:
    virtual u32 v0(void* a, s32 b) = 0;
};

struct Outer {
    u32 unk0;
    u32 unk4;
    s32 unk8;
    u32 unkC;
    Inner* unk10;
    u32 unk14;
    u8 unk18;
};

extern "C" void* fn_27_C3A40(Outer* self, s32 arg1, s32 arg2) {
    s32 v = self->unk8;
    if (v == 0 || self->unk10 == NULL) {
        return lbl_27_bss_1CC;
    }
    void* res = fn_27_C4020(v, arg1, self->unk18);
    if (res == NULL) {
        return lbl_27_bss_1CC;
    }
    if (self->unk10->v0(res, arg2) == 1) {
        return res;
    }
    return lbl_27_bss_1CC;
}
