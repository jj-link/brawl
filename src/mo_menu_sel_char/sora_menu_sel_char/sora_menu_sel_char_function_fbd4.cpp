#include <types.h>
#include <mu/menu.h>
#include <mu/mu_object.h>
#include <stdio.h>
#pragma force_active on

struct Self {
    unsigned char pad0[0x64];
    u32 unk64;
    unsigned char pad1[0x3dc - 0x68];
    MuObject* objs[5];
};
extern "C" {
void fn_800B7224(void*, u32, char*, u32);
extern signed char lbl_10_data_6FC;
extern char lbl_10_data_6F0[];
extern float lbl_10_rodata_450;
extern double lbl_10_rodata_458;
extern float lbl_10_rodata_2F0;
}
extern "C" void fn_10_FBD4(Self* self, int kind, int arg2) {
    char buf[16];
    float f31;
    u32 unk;
    const char* name;
    MuObject* obj;
    Self* current;
    int j;
    if ((u32)(kind - 0x28) <= 1) {
        f31 = (double)lbl_10_rodata_450;
    } else {
        name = (const char*)&lbl_10_data_6FC;
        current = self;
        int i;
        f31 = lbl_10_rodata_458;
        for (i = 0; i < 5; i++, current = (Self*)((char*)current + 4)) {
            int fileKind = muMenu::exchangeGmCharacterKind2Something(muMenu::exchangeMuSelchkind2MuStockchkind(kind));
            int value = arg2 + (int)(float)(fileKind * 10 + 1);
            sprintf(buf, lbl_10_data_6F0, value);
            obj = current->objs[0];
            unk = self->unk64;
            nw4r::g3d::ResMat mat = obj->m_resMdl.GetResMat(name);
            fn_800B7224(obj, mat.ptr()->m_id, buf, unk);
        }
        f31 = (double)lbl_10_rodata_2F0;
    }
    for (j = 0; j < 5; j++) {
        self->objs[j]->setFrameVisible(f31);
    }
}