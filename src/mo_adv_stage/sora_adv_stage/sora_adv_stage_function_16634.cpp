#pragma force_active on
#include <types.h>

struct Obj {
    char pad00[0x10];
    u32 unk10;
    u32 unk14;
    char pad18[0x6];
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    char pad21[0x8B];
    s32 unkAC;
};

struct Tbl {
    s32 v[10];
};

extern "C" Obj* fn_40_15694(Obj*, s32);
extern "C" Tbl lbl_40_data_3528;

extern "C" void fn_40_16634(Obj* self, s32 arg1, u32 arg2) {
    Obj* t;
    s32 i;
    s32 found;
    s32* p;
    Tbl tbl;

    if (self->unk10 == arg2) {
        self->unk1E = 1;
    }
    if (self->unk14 == arg2) {
        self->unk1F = 1;
    }

    tbl = lbl_40_data_3528;
    t = fn_40_15694(self, arg1);
    p = tbl.v;
    i = 0;
    while (i < 10) {
        if (t && *p == t->unkAC) {
            found = 1;
            goto end;
        }
        ++p;
        ++i;
    }
    found = 0;

end:
    if (found != 0) {
        t = fn_40_15694(self, arg1);
        if (t != 0 && t->unkAC == 0x2E) {
            self->unk1E = 1;
            self->unk1F = 1;
            return;
        }
        if (self->unk20 != 0 && t != 0 && t->unkAC == 0x3B) {
            self->unk1E = 1;
            return;
        }
        if (self->unk20 != 0 && t != 0 && t->unkAC == 0x3C) {
            self->unk1F = 1;
            return;
        }
        self->unk1E = 1;
    }
}
