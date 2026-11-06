#include <types.h>
#pragma force_active on

struct Pair {
    u32 a;
    u32 b;
};

struct Data {
    Pair p0;
    u32 u8;
    Pair p12;
    u32 u20;
    Pair p24;
    u32 u32_;
    Pair p36;
    u32 u44;
    u32 u48;
    u32 u52;
    float f56;
};

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
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual Data* slot26(u32 index);
};

extern "C" void fn_27_391154(Object_vptr_0* self, u32 from, u32 to) {
    Data* src = self->slot26(from);
    Data* dst = self->slot26(to);
    *dst = *src;
}
