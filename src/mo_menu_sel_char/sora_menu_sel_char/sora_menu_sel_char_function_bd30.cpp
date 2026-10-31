#pragma force_active on
struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void invoke();
};

struct Context {
    unsigned char padding[8];
    Target* target;
};

extern "C" void fn_10_BD30(Context* self) {
    if (self->target) {
        self->target->invoke();
    }
}
