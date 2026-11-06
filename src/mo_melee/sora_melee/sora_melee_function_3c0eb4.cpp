#pragma force_active on
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
    virtual int slot17(int);
    virtual void slot18();
    virtual void slot19(int);
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
    virtual void slot39(int);
};
struct Modules {
    char pad0[0x64];
    Object_vptr_0* work;
    char pad1[0x20];
    Object_vptr_0* status;
};
struct Object {
    char pad[0xd8];
    Modules* modules;
};
extern "C" void fn_27_3C0EB4(void*, Object* object, int value) {
    switch (value) {
    case 0x119:
    case 0x11a:
        return;
    default:
        break;
    }
    if (object->modules->work->slot17(0x22000013)) {
        object->modules->status->slot39(0x23);
        object->modules->work->slot19(0x22000013);
    }
}
