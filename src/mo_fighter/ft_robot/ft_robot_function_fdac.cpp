#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_120_5CB0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(u32);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(float, u32);
    virtual int slot16();
};
extern float lbl_120_rodata_70;
extern "C" void fn_120_FDAC(void*, soModuleAccesser* accesser) {
    switch (((Object_vptr_0*)accesser->m_enumerationStart->m_statusModule)->slot16()) {
    case 0x11b: {
        Object_vptr_0* work = (Object_vptr_0*)accesser->m_enumerationStart->m_workManageModule;
        float c = soValueAccesser::getConstantFloat(accesser, 0xfcf, 0);
        if (work->slot12(0x11000014) < c) {
            ((Object_vptr_0*)accesser->m_enumerationStart->m_workManageModule)->slot15(lbl_120_rodata_70, 0x11000014);
            ((Object_vptr_0*)accesser->m_enumerationStart->m_workManageModule)->slot12(0x11000014);
        }
        break;
    }
    }
}