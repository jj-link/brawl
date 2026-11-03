#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_20_data_AE8[];
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
void* fn_20_2D50(void*, int);
}

struct Sub {
    void* unk0;
    u8 unk4;
    u8 pad5[3];
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
};

struct Owner {
    void* unk0;
    u8 pad4[0x14];
    void* unk18;
    void* unk1C;
    u8 pad20[0x1C];
    Sub** unk3C;
};

extern "C" Owner* fn_20_D748(Owner* self, int flag) {
    if (self != 0) {
        u8* base = (u8*)lbl_20_data_AE8;
        self->unk0 = base;
        self->unk18 = base + 0x18;
        self->unk1C = base + 0x34;
        Sub* sub = self->unk3C[0];
        if (sub != 0) {
            if (sub->unkC != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(sub->unkC);
            }
            if (sub->unk8 != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(sub->unk8);
            }
            if (sub->unk10 != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(sub->unk10);
            }
            if (sub->unk14 != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(sub->unk14);
            }
            if (sub->unk18 != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(sub->unk18);
            }
            if (sub->unk1C != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(sub->unk1C);
            }
            if (sub->unk0 != 0 && sub->unk4 != 0) {
                free__13gfHeapManagerFPv(sub->unk0);
                sub->unk0 = 0;
            }
            sub->unkC = 0;
            sub->unk8 = 0;
            sub->unk10 = 0;
            sub->unk14 = 0;
            sub->unk18 = 0;
            sub->unk1C = 0;
            __dl__FPv(sub);
        }
        __dl__FPv(self->unk3C);
        fn_20_2D50(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
