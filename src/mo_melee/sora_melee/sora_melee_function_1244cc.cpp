#pragma force_active on

#include <types.h>

struct AiInput;

struct Slot {
    s32 value;
    s32 pad4;
};

struct Desc {
    u8 pad0[0x0A];
    u8 index;
    u8 pad0B[0x0D];
    s32 unk18;
    u8 pad1C[0x14];
    Slot slots[0x36];
};

struct Req {
    u8 pad0[0x4];
    Desc* desc;
    u8 pad8[0x4];
    AiInput* a;
    AiInput* b;
};

extern "C" {
extern s32 lbl_27_bss_31F8;
extern u8 lbl_27_rodata_1E18[];
s32 fn_27_144F24(s32 self, s32 id, s32 flags, s32 key, s32 a, s32 b, s32* c);
void fn_27_1F3664(AiInput* self, void* data, s32 size, s32 flag3, s32 flag4);
}

extern "C" void fn_27_1244CC(Req* arg0) {
    s32 spC;
    s32 sp8;
    s32 key;
    s32 res;
    s32 a7;
    Desc* desc = arg0->desc;

    key = desc->slots[desc->index].value;
    if (arg0->a != 0) {
        if (key >= 0x32 && key <= 0x35) {
            res = fn_27_144F24(lbl_27_bss_31F8, desc->unk18, 1, key, 0xA, -1, &spC);
        } else {
            a7 = 0xA;
            if (key == 0x31) {
                a7 = 0xB;
                key = 0x15;
            } else if (key == 0x30) {
                a7 = 0xB;
                key = 0xB;
            }
            if (lbl_27_rodata_1E18[key] & 0x10) {
                res = fn_27_144F24(lbl_27_bss_31F8, desc->unk18, 7, key, a7, 0, &spC);
            } else {
                res = fn_27_144F24(lbl_27_bss_31F8, desc->unk18, 5, key, a7, -1, &spC);
            }
        }
        fn_27_1F3664(arg0->a, (void*)res, spC, 0, 1);
    }
    if (arg0->b != 0) {
        if (lbl_27_rodata_1E18[key] & 0x10) {
            res = fn_27_144F24(lbl_27_bss_31F8, arg0->desc->unk18, 7, key, 0xB, 0, &sp8);
        } else {
            res = fn_27_144F24(lbl_27_bss_31F8, arg0->desc->unk18, 5, key, 0xB, -1, &sp8);
        }
        fn_27_1F3664(arg0->b, (void*)res, sp8, 0, 1);
    }
}
