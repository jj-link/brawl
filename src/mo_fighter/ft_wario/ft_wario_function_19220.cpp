#include <so/so_module_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17();
};
struct SummedSpeed { float x, y; };
class KineticView : public soNullable {
public:
    virtual void activate(); virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int); virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int); virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll(); virtual void suspendEnergyAll(); virtual void resumeEnergyAll();
    virtual void unableEnergyAll(); virtual SummedSpeed getSumSpeed(const unsigned short&);
};
struct Params { char pad[0x64]; float step; char pad68[0x24]; float threshold; };
struct Fighter { char pad[0x2980]; Params* params; };
extern "C" {
extern const unsigned char lbl_110_data_5EF0[], lbl_110_data_212C[];
extern const float lbl_110_rodata_178;
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_110_19220(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    KineticView* kinetic = reinterpret_cast<KineticView*>(modules->m_kineticModule);
    soPostureModule* posture = modules->m_postureModule;
    soStatusModule* status = modules->m_statusModule;
    unsigned short attributes = 1;
    float speed = kinetic->getSumSpeed(attributes).x;
    bool trigger = false;
    bool left = work->isFlag(0x22000004);
    bool right = work->isFlag(0x22000005);
    bool center = work->isFlag(0x22000006);
    float angle = work->getFloat(0x21000000);
    float target = work->getFloat(0x21000002);
    Params* params = ((Fighter*)__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_110_data_5EF0, lbl_110_data_212C, 1))->params;
    if (lbl_110_rodata_178 == posture->getLr()) {
        if (speed <= params->threshold) trigger = true;
    } else {
        if (speed >= -params->threshold) trigger = true;
    }
    if (trigger && (center || left || right)) status->changeStatusRequest(0xb, accesser);
    if (center) {
        if (angle > target) {
            angle -= params->step;
            if (angle < target) angle = target;
        } else if (angle < target) {
            angle += params->step;
            if (angle > target) angle = target;
        }
    } else if (!left && right) {
        angle -= params->step;
        if (center && angle < target) angle = target;
    } else if (!right && left) {
        angle += params->step;
        if (center && angle > target) angle = target;
    } else {
        status->changeStatusRequest(0xd, accesser);
    }
    work->setFloat(angle, 0x21000000);
}
}