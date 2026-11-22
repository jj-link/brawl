#include <mu/mu_object.h>
#include <stdio.h>
#include <types.h>

#pragma force_active on
#pragma optimization_level 1

struct Self {
    char pad[0x40];
    MuObject* object;
};

extern "C" {
extern const float lbl_12_rodata_0[];
extern const char lbl_12_data_28[];

void fn_12_588(Self* self, int index) {
    char name[40];
    const float* ro = lbl_12_rodata_0;
    const u8* tbl = (const u8*)ro + 0x54;

    sprintf(name, lbl_12_data_28, tbl[index]);

    float rate;
    float frame;
    if (index == 5) {
        rate = ro[16];
        frame = ro[23];
    } else {
        rate = ro[24];
        frame = ro[16];
    }

    MuObject* obj = self->object;
    obj->changeNodeAnimN(name);
    obj->setFrameNode(frame);
    obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(rate);
    obj->changeVisAnimN(name);
    obj->setFrameVisible(frame);
    obj->m_modelAnim->m_anmObjVisRes->SetUpdateRate(rate);
    obj->changeClrAnimN(name);
    obj->setFrameMatCol(frame);
    obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(rate);
}
}
