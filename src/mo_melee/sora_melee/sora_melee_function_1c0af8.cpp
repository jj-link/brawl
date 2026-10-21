#pragma force_active on
struct Interface {
    virtual void first();
    virtual void target();
};

struct Object {
    char padding[16];
    Interface member;
};

extern "C" void fn_27_1C0AF8(Object* self) {
    self->member.target();
}
