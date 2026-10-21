#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void invoke();
};

struct Context {
    unsigned char padding[0x8C];
    Target* target;
};

extern "C" void fn_27_1CB6C(Context* self) {
    self->target->invoke();
}
