#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

namespace {
class TeamValue {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual int getValue();
};

class TeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual TeamValue* getValue();
};
}

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
float randf__Fv();
extern const float lbl_112_rodata_B0;
void fn_112_10D08(
    Weapon*, unsigned int, unsigned int, int, Vec3f*, float, float);
}

extern "C" bool fn_112_15CA8(Weapon* article, soModuleAccesser* accesser) {
    Vec3f position = accesser->m_enumerationStart->m_postureModule->getPos();
    float radius = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfa1, 0);
    float angle = lbl_112_rodata_B0 * randf__Fv();

    position.m_x = radius * (float)cos(angle);
    position.m_y = radius * (float)sin(angle);
    position.m_z *= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfa2, 0);

    TeamModule* team =
        static_cast<TeamModule*>(accesser->m_enumerationStart->m_teamModule);
    soResourceModule* resource =
        accesser->m_enumerationStart->m_resourceModule;
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    float value =
        accesser->m_enumerationStart->m_workManageModule->getFloat(0x11000001);
    int teamValue = team->getValue()->getValue();
    unsigned int res = resource->getResourceIdAccesser()->getBinResId();

    fn_112_10D08(article, taskId, res, teamValue, &position, angle, value);
    return false;
}
