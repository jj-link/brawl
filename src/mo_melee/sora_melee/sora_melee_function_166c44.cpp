#include <so/so_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int, int, int);
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
    virtual void slot16();
    virtual unsigned int slot17(unsigned int);
    virtual void slot18();
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
struct Modules {
    char pad0[0xc];
    Object_vptr_0* objC;
    char pad1[0x40];
    Object_vptr_0* obj50;
    char pad2[0xc];
    Object_vptr_0* obj60;
    Object_vptr_0* obj64;
};
struct Outer {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_166C44(void*, Outer* a) {
    Object_vptr_0* work = a->modules->obj64;
    work->slot13(a->modules->objC->slot9(), 0x21000005);
    a->modules->obj64->slot19(0x22000011);
    a->modules->obj64->slot13(soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xc3b, 0), 0x21000004);
    a->modules->obj64->slot19(0x22000010);
    if (a->modules->obj64->slot17(0x12000013) == 1)
        a->modules->obj50->slot5(0x1faa, 0, 0, 0);
    a->modules->obj60->slot40(0);
}
