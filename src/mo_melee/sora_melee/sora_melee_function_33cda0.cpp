#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(u32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(u32);
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
    virtual void slot18(u32);
};

struct ModuleTable {
    char pad[0x64];
    soNullable* work;
};

struct Object {
    char pad[0xD8];
    ModuleTable* modules;
};

extern "C" void fn_27_33CDA0(void*, Object* object) {
    soNullable* work = object->modules->work;
    if (work->slot4(0x20000000) % 3 == 2) {
        work->slot18(0x22000011);
    }
    work->slot7(0x20000000);
}
