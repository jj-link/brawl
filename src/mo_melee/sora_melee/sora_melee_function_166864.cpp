#pragma force_active on
#include <so/so_value_accesser.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, unsigned int);
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40(int);
};

extern "C" const float lbl_27_rodata_2058;

extern "C" void fn_27_166864(void*, soModuleAccesser* object) {
    if (((Object_vptr_0*)object->m_enumerationStart->m_statusModule)->slot16() == 7) {
        ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot13(lbl_27_rodata_2058, 0x21000005);
        ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot18(0x22000010);
    } else {
        float value = soValueAccesser::getConstantFloat(object, 0xBDF, 0);
        ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot13(value, 0x21000005);
        ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot19(0x22000010);
    }
    ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot19(0x22000012);
    Object_vptr_0* work = (Object_vptr_0*)object->m_enumerationStart->m_workManageModule;
    work->slot13(((Object_vptr_0*)object->m_enumerationStart->m_postureModule)->slot9(), 0x21000004);
    ((Object_vptr_0*)object->m_enumerationStart->m_postureModule)->slot11();
    ((Object_vptr_0*)object->m_enumerationStart->m_cameraModule)->slot40(0);
}
