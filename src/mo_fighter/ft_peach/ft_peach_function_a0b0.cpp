#include <types.h>
#pragma force_active on

struct PeachObject {
    u8 padding[8];

    virtual void slot0();
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void apply(u32 arg1, u32 arg2);
    virtual void slot21();
    virtual u32 query();
};

extern "C" u32 fn_103_A0B0(PeachObject* object, u32 arg1, u32 arg2) {
    u32 result = object->query();
    if (result == 1) {
        object->apply(arg1, arg2);
    }
    return result;
}
