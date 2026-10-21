#include <types.h>
#pragma force_active on

struct fn_8018CD30_obj {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
};

extern "C" void fn_8018CD30(fn_8018CD30_obj* p, u32 arg1) {
    u32 v = (u32)p->unk1 << 24;
    v = v | ((u32)p->unk2 << 16);
    v = v | ((u32)p->unk3 << 8);
    v = v | p->unk4;

    p->unk0 = 0x61;

    u32 result = v | arg1 | 0xFE000000;
    p->unk4 = (u8)result;
    p->unk1 = (u8)(result >> 24);
    p->unk2 = (u8)(result >> 16);
    p->unk3 = (u8)(result >> 8);
}
