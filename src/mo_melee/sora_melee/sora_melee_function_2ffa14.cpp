#pragma force_active on
#pragma optimization_level 2
#pragma scheduling off
#pragma opt_propagation off

struct Owner;
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
    virtual void slot13(unsigned int, Owner*);
};
struct Middle {
    char pad[0x64];
    Object_vptr_0* target;
};
struct Owner {
    char pad[0xD8];
    Middle* middle;
};
struct Object {
    char pad[0x60];
    Owner* owner;
};
extern "C" void fn_27_2FFA14(Object* self) {
    Owner* owner = self->owner;
    int value = 0x11000001;
    owner->middle->target->slot13(value, owner);
}