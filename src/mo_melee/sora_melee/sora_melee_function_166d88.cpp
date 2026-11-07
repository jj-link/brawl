#include <so/so_value_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(unsigned int); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual float slot12(unsigned int); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual unsigned int slot17(unsigned int); virtual void slot18(unsigned int);
 virtual void slot19(unsigned int);
};
class Kinetic {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual Vec2f slot13(short*);
};
extern "C" void fn_27_166D88(void*, soModuleAccesser* a) {
    if (a->m_enumerationStart->m_workManageModule->isFlag(0x22000010) == 1) {
        soValueAccesser::getConstantFloat(a, 0xc39, 0);
        if (!a->m_enumerationStart->m_workManageModule->isFlag(0x22000011)) {
            a->m_enumerationStart->m_motionModule->setRate(0.0f);
            a->m_enumerationStart->m_workManageModule->onFlag(0x22000011);
        } else {
            float v = a->m_enumerationStart->m_workManageModule->getFloat(0x21000005);
            short flag = 1;
            if ((v * ((Kinetic*)a->m_enumerationStart->m_kineticModule)->slot13(&flag).m_x <= 0.0f) != 0) {
                a->m_enumerationStart->m_motionModule->setRate(1.0f);
                a->m_enumerationStart->m_workManageModule->offFlag(0x22000010);
            } else if (a->m_enumerationStart->m_workManageModule->getInt(0x20000000) < 0 &&
                       a->m_enumerationStart->m_groundModule->getDownFriction(0) < 1.0f &&
                       a->m_enumerationStart->m_groundModule->isNearCliff(v, 0.01f, 0) == 1) {
                a->m_enumerationStart->m_motionModule->setRate(1.0f);
                a->m_enumerationStart->m_workManageModule->offFlag(0x22000010);
            }
        }
    }
}