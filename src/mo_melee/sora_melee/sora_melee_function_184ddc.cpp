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
    virtual void slot7(int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(int, int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int);
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
    virtual void slot26(int);
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33(int);
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40(int);
};
struct Modules {
    char pad0[0x20];
    Object_vptr_0* at20;
    char pad1[0x1C];
    Object_vptr_0* at40;
    char pad2[0x10];
    Object_vptr_0* at54;
    Object_vptr_0* at58;
    char pad3[8];
    Object_vptr_0* at64;
    char pad4[0x20];
    Object_vptr_0* at88;
};
struct Object {
    char pad[0xD8];
    Modules* modules;
};
extern "C" void fn_27_184DDC(void*, Object* object, int kind) {
    switch (kind) {
    case 0xD3: {
        Modules* modules = object->modules;
        Object_vptr_0* other = modules->at54;
        Object_vptr_0* work = modules->at64;
        other->slot40(0);
        work->slot13(0x21000009);
        object->modules->at40->slot10(1, 0);
        return;
    }
    case 0xD5:
        return;
    default:
    case 0x40:
        object->modules->at40->slot10(1, 0);
        object->modules->at20->slot26(0);
        object->modules->at58->slot7(1);
        object->modules->at88->slot33(1);
        break;
    }
}
