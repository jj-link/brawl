#include <types.h>
#pragma force_active on

struct muSelCharPlayerArea {
    char pad[0x1E8];
    s32 unk1E8;
    s32 unk1EC;
    s32 unk1F0;
};

extern "C" u8 lbl_10_rodata_568[];

extern "C" s32 fn_10_12010(muSelCharPlayerArea* self, s32 kind) {
    u8* tbl = lbl_10_rodata_568;
    s32 res = kind;
    switch (kind) {
    case 0xE:
        tbl = (u8*)((unsigned int)tbl + 0x18);
        res = tbl[self->unk1E8];
        break;
    case 0x3:
        tbl = (u8*)((unsigned int)tbl + 0x1C);
        res = tbl[self->unk1EC];
        break;
    case 0x1B:
        tbl = (u8*)((unsigned int)tbl + 0x20);
        res = tbl[self->unk1F0];
        break;
    }
    return res;
}
