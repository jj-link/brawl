#pragma force_active on
typedef unsigned int u32;

struct Target {
    unsigned char reserved00[8];
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void apply(u32);
    virtual void slot1C();
    virtual void reset();
    virtual void slot24();
    virtual void slot28();
    virtual u32 state();
};

struct Context {
    unsigned char reserved00[0x38];
    Target* target;
    unsigned char reserved3C[0xC];
    u32 value;
};

extern "C" void fn_27_A42D0(Context* self) {
    if (self->target->state() == 1) {
        self->target->reset();
        self->target->apply(self->value);
    }
}
