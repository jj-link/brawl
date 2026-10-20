#include <types.h>
#include <gr/gr_yakumono.h>
#pragma force_active on

extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" const float lbl_70_rodata_28;
extern "C" char lbl_70_data_A68[];

class grVillageObjBase : public grYakumono {
public:
    virtual void setupMelee();

    u8 unk150;
    f32 unk154;
    s32 unk158;
    u8 unk15c;
    s32 unk160;
    s32 unk164;
};

extern "C" grYakumono* fn_70_2088(grYakumono* self, const char* taskName) {
    grVillageObjBase* obj = (grVillageObjBase*)self;
    __ct__10grYakumonoFPCc(self, taskName);
    obj->unk150 = 0;
    *(void**)((char*)self + 0x3c) = lbl_70_data_A68;
    obj->unk154 = lbl_70_rodata_28;
    obj->unk158 = 0;
    obj->unk15c = 0;
    obj->unk160 = 0;
    obj->unk164 = 0;
    obj->setupMelee();
    return self;
}
