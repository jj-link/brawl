#include <types.h>
#pragma force_active on

class soNullable {
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
    virtual void slot9(int, int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(int);
};

class Module {
public:
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21(int);
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual int f33(int);
};

struct Holder {
    char pad0[4];
    Module* module;
    char pad1[0x34];
    soNullable* first;
    char pad2[0x24];
    soNullable* second;
};
struct Object {
    char pad[0xd8];
    Holder* holder;
};
extern "C" void fn_27_178AD4(void*, Object* obj, int type) {
    if (type != 0x39) {
        obj->holder->first->slot9(0, 0);
    }
    if (!obj->holder->second->slot17(0x22000010)) {
        Module* module = obj->holder->module;
        module->f21(module->f33(0x130));
    }
}
