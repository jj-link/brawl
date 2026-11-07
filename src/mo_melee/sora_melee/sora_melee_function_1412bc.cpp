#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};
struct Modules {
    char pad[0x14];
    Object_vptr_0* object;
};
struct Access {
    char pad[0xd8];
    Modules* modules;
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_140624();
    virtual unsigned int fn_27_141358();
    virtual void fn_27_1412BC();
    char pad[0x28];
    Access* access;
    int unused;
    int id;
};
extern "C" void fn_27_140CC4(soNullable*, int);
extern "C" void fn_27_1412BC(soNullable* self) {
    if (self->id != -1 && self->fn_27_141358() == 1U) {
        if (self->id != self->access->modules->object->slot3()) {
            fn_27_140CC4(self, self->access->modules->object->slot3());
        }
    }
}