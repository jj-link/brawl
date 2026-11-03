#include <so/so_value_accesser.h>
#pragma force_active on

class soNullableSlots {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(int, int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int);
};

struct Modules {
    char pad0[8];
    soNullableSlots* motion;
    char padc[0x34];
    soNullableSlots* capture;
};

extern "C" void fn_27_1876A8(void*, soModuleAccesser* accesser) {
    int value = soValueAccesser::getVariableInt(accesser, 0x4e23, 0);
    if (value == 0xe8 && value == 0xe9) {
        ((Modules*)accesser->m_enumerationStart)->capture->slot19(0);
        ((Modules*)accesser->m_enumerationStart)->capture->slot10(0, 0);
    } else {
        if (((Modules*)accesser->m_enumerationStart)->motion->slot16()) {
            ((Modules*)accesser->m_enumerationStart)->capture->slot19(0);
        }
        ((Modules*)accesser->m_enumerationStart)->capture->slot10(0, 0);
    }
}