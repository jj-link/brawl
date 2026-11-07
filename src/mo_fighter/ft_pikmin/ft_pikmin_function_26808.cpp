#include <so/so_module_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void fn_113_80F4();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual bool slot17(unsigned int);
};
extern "C" void fn_113_26808(void*, soModuleAccesser* accesser) {
    if (!accesser->getWorkManageModule().isFlag(0x12000003)) {
        if (accesser->getWorkManageModule().getInt(0x10000011) & 0x40) {
            accesser->getGroundModule().setCorrect(soGroundShapeImpl::Correct_Ground_Cliff_Stop, 0);
        } else {
            accesser->getGroundModule().setCorrect(soGroundShapeImpl::Correct_Ground, 0);
        }
    } else {
        accesser->getGroundModule().setCorrect(soGroundShapeImpl::Correct_Ground, 0);
    }
}