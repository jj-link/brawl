#pragma force_active on
struct Interface {
    virtual void first();
    virtual void invoke();
};

struct Object {
    unsigned char padding[0x10];
    Interface member;
};

extern "C" void fn_27_1CEE74(Object* self) {
    self->member.invoke();
}
