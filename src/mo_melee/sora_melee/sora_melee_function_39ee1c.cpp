#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5(int, int);
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
    virtual void slot20(int);
};
struct Modules {
    char pad0[0x64];
    Object_vptr_0* work;
    char pad1[0x20];
    Object_vptr_0* effect;
};
struct Owner {
    char pad[0xd8];
    Modules* modules;
};
struct Self {
    char pad[0x60];
    Owner* owner;
};
extern "C" void fn_27_39EE1C(Self* self) {
    Owner* owner = self->owner;
    Object_vptr_0* work = owner->modules->work;
    int handle = work->slot4(0x10000008);
    if (handle != 0) {
        owner->modules->effect->slot20(handle);
        work->slot5(0, 0x10000008);
    }
}