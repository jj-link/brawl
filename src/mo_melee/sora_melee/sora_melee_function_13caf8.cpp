#pragma force_active on
#include <types.h>
#include <so/so_value_accesser.h>
#include <so/slow/so_slow_module_simple.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int id, const soModuleEnumeration* e);
    virtual void slot5(int value, unsigned int id);
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
    virtual int slot16(int arg);
    virtual unsigned int slot17(unsigned int id, const soModuleEnumeration* e);
    virtual void slot18(int value, const soModuleEnumeration* e);
    virtual int slot19();
};

class SlowLike : public soNull, public soNullable {
public:
    virtual void slot3();
    virtual void slot4();
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
    virtual void slot17();
    virtual void slot18(int value, const soModuleEnumeration* e);
    virtual int slot19();
};

struct Holder {
    char pad[0x60];
    soModuleAccesser* object;
};

extern "C" void fn_27_13CAF8(Holder* holder) {
    soModuleAccesser* object = holder->object;
    if (((Object_vptr_0*)object->m_enumerationStart->m_itemManageModule)->slot16(0) == 0x1B) {
        int value = ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot4(0x1000001B, object->m_enumerationStart);
        if (value > 0) {
            int diff = value - soValueAccesser::getConstantInt(object, 0x5A73, 0);
            if (diff < 0) {
                diff = 0;
            }
            ((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot5(diff, 0x1000001B);
        }
    }
    if (((Object_vptr_0*)object->m_enumerationStart->m_workManageModule)->slot17(0x12000028, object->m_enumerationStart) == 1U) {
        int value = ((SlowLike*)object->m_enumerationStart->m_slowModule)->slot19();
        ((SlowLike*)object->m_enumerationStart->m_slowModule)->slot18(value - soValueAccesser::getConstantInt(object, 0x5A81, 0), object->m_enumerationStart);
    }
}
