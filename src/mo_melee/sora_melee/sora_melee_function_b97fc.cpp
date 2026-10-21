#pragma force_active on
struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void call();
};

struct Object {
    char padding[0x40];
    Target* target;
};

extern "C" void fn_27_B97FC(Object* self) {
    self->target->call();
}
