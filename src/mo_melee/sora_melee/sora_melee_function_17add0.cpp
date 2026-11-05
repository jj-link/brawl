#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(u32, u32, u32, u32);
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
    virtual int slot16(int);
    virtual int slot17(u32);
    virtual void slot18(u32);
    virtual void slot19();
    virtual void slot20();
    virtual int slot21();
};

struct Modules {
    char pad0[8];
    soNullable* posture;
    char padC[0x44];
    soNullable* sound;
    char pad54[0x10];
    soNullable* work;
    char pad68[0x40];
    soNullable* status;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_17ADD0(void*, Object* obj) {
    if (obj->modules->work->slot17(0x22000011) == 0) {
        if (obj->modules->status->slot16(0) == 0x48) {
            if (obj->modules->posture->slot21() != 0xFE) {
                obj->modules->sound->slot5(0x2293, 0, 0, 0);
            }
        }
        obj->modules->work->slot18(0x22000011);
    }
}
