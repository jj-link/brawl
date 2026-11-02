#pragma force_active on
#include <gm/gm_global.h>
#include <types.h>

struct S {
    int v[10];
};

struct O {
    char pad[0xAC];
    int id;
};

struct Self {
    char pad00[0x6];
    u8 unk6;
    char pad07;
    int unk8;
    char pad0C[0xC];
    int unk18;
    char pad1C[0x4];
    u8 unk20;
};

extern "C" O* fn_40_15694(int, int);
extern "C" S lbl_40_data_3528;

extern "C" void fn_40_15DA0(Self* self, int arg1) {
    S local = lbl_40_data_3528;
    O* p = fn_40_15694((int)self, arg1);
    int found;
    int i;
    int* arr = (int*)&local;

    i = 0;
    while (i < 10) {
        if (p && *arr == p->id) {
            found = 1;
            goto end;
        }
        ++arr;
        ++i;
    }
    found = 0;

end:
    if (found != 0) {
        u8 flag = (((u8*)g_GameGlobal->m_advData)[0x4924] >> 6) & 1;
        self->unk20 = flag != 0;
        if (self->unk20 != 0) {
            O* p2 = fn_40_15694((int)self, arg1);
            int ok;
            if (p2 && p2->id == 0x3C) {
                ok = 1;
            } else {
                ok = 0;
            }
            if (ok != 0) {
                self->unk18 = arg1;
                return;
            }
        }
        self->unk8 = arg1;
        self->unk6 = 1;
    }
}
