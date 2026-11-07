#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <types.h>

#pragma force_active on

#define DUM(n) virtual void d##n();

class WorkView {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5)
    DUM(6) DUM(7) DUM(8) DUM(9) DUM(10) DUM(11)
    virtual float getFloat(u32);        // 0x38
    virtual void setFloat(float, u32);  // 0x3c
};

class SituationView {
public:
    DUM(0) DUM(1) DUM(2)
    virtual int f3();                   // 0x14
};

class StatusView {
public:
    DUM(0) DUM(1) DUM(2)
    virtual void f3(int, soModuleAccesser*); // 0x14
};

class StopView {
public:
    DUM(0) DUM(1) DUM(2) DUM(3)
    virtual void f4(int, const soModuleEnumeration*, float); // 0x18
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, u32, u32);
extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_104C;

static WorkView* workOf(soModuleAccesser* m) {
    return reinterpret_cast<WorkView*>(m->m_enumerationStart->m_workManageModule);
}
static StatusView* statusOf(soModuleAccesser* m) {
    return reinterpret_cast<StatusView*>(m->m_enumerationStart->m_statusModule);
}
static SituationView* situationOf(soModuleAccesser* m) {
    return reinterpret_cast<SituationView*>(m->m_enumerationStart->m_situationModule);
}
static StopView* stopOf(soModuleAccesser* m) {
    return reinterpret_cast<StopView*>(m->m_enumerationStart->m_stopModule);
}

extern "C" int fn_27_135A70(StageObject* self) {
    if (*(float*)((char*)self + 0x120) > lbl_27_rodata_1048) {
        float f30 = workOf(self->m_moduleAccesser)->getFloat(0x11000003);
        if (*(float*)((char*)self + 0x11C) > lbl_27_rodata_1048) {
            soModuleAccesser* mod = self->m_moduleAccesser;
            float ca8 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0xCA8, 0);
            float cb0 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0xCB0, 0);
            float k = *(float*)((char*)self + 0x11C) * (lbl_27_rodata_104C - cb0);
            float t = k * ca8;
            float ca9 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0xCA9, 0);
            f30 -= ca9 + t;
            float m = workOf(self->m_moduleAccesser)->getFloat(0x11000004);
            if (f30 < m) {
                f30 = m;
            }
        }
        if (f30 < lbl_27_rodata_1048) {
            statusOf(self->m_moduleAccesser)->f3(0x56, self->m_moduleAccesser);
        } else {
            if (situationOf(self->m_moduleAccesser)->f3() != 0) {
                return 0;
            }
            workOf(self->m_moduleAccesser)->setFloat(f30, 0x11000003);
            workOf(self->m_moduleAccesser)->setFloat(*(float*)((char*)self + 0x120), 0x21000008);
            workOf(self->m_moduleAccesser)->setFloat(*(float*)((char*)self + 0x124), 0x21000009);
            statusOf(self->m_moduleAccesser)->f3(0x1D, self->m_moduleAccesser);
        }
        stopOf(self->m_moduleAccesser)->f4(0, self->m_moduleAccesser->m_enumerationStart, (float)(s32)*(float*)((char*)self + 0x120));
        return 1;
    }
    return 0;
}
