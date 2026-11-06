#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int, float);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(int);
    virtual void slot19();
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
    virtual void slot40();
    virtual void slot41(int);
    virtual void slot42();
    virtual void slot43();
    virtual void slot44(int);
};
struct Modules {
    char pad0[8];
    Object_vptr_0* first;
    char pad1[0x58];
    Object_vptr_0* values;
    char pad2[0x40];
    Object_vptr_0* last;
};
struct Object {
    char pad[0xd8];
    Modules* modules;
};
extern "C" float lbl_27_rodata_23D0;
extern "C" void fn_27_17EFB4(Object* obj, int value) {
    int found = 0;
    if (value == obj->modules->values->slot4(0x20000001) ||
        value == obj->modules->values->slot4(0x20000002) ||
        value == obj->modules->values->slot4(0x20000004) ||
        value == obj->modules->values->slot4(0x20000003) ||
        value == obj->modules->values->slot4(0x20000005) ||
        value == obj->modules->values->slot4(0x20000006) ||
        value == obj->modules->values->slot4(0x20000007) ||
        value == obj->modules->values->slot4(0x2000000a) ||
        value == obj->modules->values->slot4(0x2000000b) ||
        value == obj->modules->values->slot4(0x20000008) ||
        value == obj->modules->values->slot4(0x20000009)) {
        found = 1;
    }
    if (found) {
        float f = lbl_27_rodata_23D0;
        obj->modules->values->slot13(0x21000006, f);
        obj->modules->values->slot18(0x2200000a);
    } else {
        obj->modules->first->slot41(1);
        obj->modules->last->slot44(0);
    }
}