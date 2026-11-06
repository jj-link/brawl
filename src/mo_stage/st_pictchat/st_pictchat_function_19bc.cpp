#include <st/st_trigger.h>
#include <st/st_trigger_observe.h>
#pragma force_active on

extern "C" const float lbl_73_rodata_0[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);

struct Obj {
    u8 p0[0x428];
    stTrigger* trigger;
    grGimmickWindData* wind;
};

extern "C" void fn_73_19BC(Obj* self) {
    const float* rodata = lbl_73_rodata_0;
    grGimmickWindData* wind = (grGimmickWindData*)__nw__FUlQ25Heaps8HeapType(0x40, 0xf);
    self->wind = wind;
    if (wind != 0) {
        memset(wind, 0, 0x40);
        grGimmickWindData* w = self->wind;
        w->m_pos.m_x = rodata[0];
        w->m_pos.m_y = rodata[6];
        w->m_pos.m_z = rodata[0];
        self->wind->m_speed = rodata[7];
        self->wind->m_vector = rodata[8];
        w = self->wind;
        w->m_areaData.m_offsetPos.m_x = rodata[0];
        w->m_areaData.m_offsetPos.m_y = rodata[0];
        w->m_areaData.m_range.m_x = rodata[8];
        w->m_areaData.m_range.m_y = rodata[9];
        self->trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0xC, -1);
        self->trigger->setWindTrigger(self->wind);

        grGimmickWindData2nd sp8;
        memset(&sp8, 0, 0x4C);
        sp8.m_pos.m_x = rodata[0];
        sp8.m_pos.m_y = rodata[6];
        sp8.m_pos.m_z = rodata[0];
        sp8.m_speed = rodata[7];
        sp8.m_vector = rodata[10];
        sp8.m_60 = rodata[11];
        sp8.m_64 = rodata[12];
        sp8.m_72 = 0x50;
        sp8.m_68 = rodata[0];
        sp8.m_areaData.m_offsetPos.m_x = rodata[0];
        sp8.m_areaData.m_offsetPos.m_y = rodata[0];
        sp8.m_areaData.m_range.m_x = rodata[8];
        sp8.m_areaData.m_range.m_y = rodata[9];
        self->trigger->setWindParam(&sp8, 1);
        self->trigger->setAreaSleep(true);
    }
}
