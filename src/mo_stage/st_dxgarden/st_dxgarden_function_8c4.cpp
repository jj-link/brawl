#include <types.h>
#include <sr/sr_common.h>
#include <st/st_trigger.h>
#pragma force_active on

extern "C" {
extern const float lbl_77_rodata_0[];
void* memset(void*, int, unsigned long);
}

struct FnSelf {
    unsigned char pad0[0x9C];
    const float* unk9C;
    unsigned char pad1[0x1F4 - 0xA0];
    stTrigger* unk1F4;
    grGimmickWaterData* unk1F8;
};

extern "C" void fn_77_8C4(FnSelf* self) {
    const float* constants = lbl_77_rodata_0;
    const float* src = self->unk9C;
    if (src != 0) {
        grGimmickWaterData* water = (grGimmickWaterData*)operator new(sizeof(grGimmickWaterData), (Heaps::HeapType)0x11);
        self->unk1F8 = water;
        if (water != 0) {
            memset(water, 0, sizeof(grGimmickWaterData));
            self->unk1F8->m_swimHeight = src[0];
            self->unk1F8->m_canDrown = true;
            self->unk1F8->m_speed = src[1];
            grGimmickWaterData* area = self->unk1F8;
            area->m_areaData.m_offsetPos.m_x = constants[0];
            area->m_areaData.m_offsetPos.m_y = src[0] - constants[1];
            area->m_areaData.m_range.m_x = constants[2];
            area->m_areaData.m_range.m_y = constants[3];
            stTrigger* trig = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x11, -1);
            self->unk1F4 = trig;
            trig->setWaterTrigger(self->unk1F8);
        }
    }
}
