#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#pragma force_active on

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

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
extern const float lbl_116_rodata_98;
void fn_116_2324C(void*, int, int, int, const Vec3f*, float, float, float);
}

extern "C" int fn_116_1FE44(void* object, soModuleAccesser* accesser) {
    Vec3f position = accesser->m_enumerationStart->m_postureModule->getPos();
    float lr = accesser->m_enumerationStart->m_postureModule->getLr();
    float angle = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa4, 0);
    float scale = accesser->m_enumerationStart->m_postureModule->getScale();
    Vec2f offset;
    if (accesser->m_enumerationStart->m_situationModule->getKind() == 2) {
        offset.m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa7, 0);
        offset.m_y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa8, 0);
    } else {
        offset.m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa5, 0);
        offset.m_y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa6, 0);
    }
    position.m_x += lr * (scale * offset.m_x);
    position.m_y += scale * offset.m_y;
    position.m_z = lbl_116_rodata_98;
    float value;
    if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x22000011))
        value = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa3, 0);
    else
        value = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa2, 0);
    Vec3f copy = position;
    soResourceModule* resource = accesser->m_enumerationStart->m_resourceModule;
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    TeamModule* team = static_cast<TeamModule*>(accesser->m_enumerationStart->m_teamModule);
    fn_116_2324C(object, taskId, resource->getResourceIdAccesser()->getEtcResId(), team->getValue()->getValue(), &copy, lr, value, angle);
    return 0;
}