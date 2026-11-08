#pragma force_active on

extern "C" void fn_801AC7C0(void*);
extern "C" void fn_801A12AC(unsigned int);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(void*);
};

struct Owner {
    char pad[0xE8];
    Object_vptr_0* object;
    int unkEC;
    int unkF0;
};

extern "C" void fn_801ACDB0(Owner* self) {
    fn_801AC7C0(self);
    if (self->unkF0 & 1) {
        self->object->slot6(&self->unkEC);
    } else {
        self->object->slot6(0);
    }
    fn_801A12AC(4);
}
