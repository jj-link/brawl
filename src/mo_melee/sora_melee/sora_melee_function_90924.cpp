#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void invoke();
};

struct Wrapper {
    unsigned char padding[8];
    Target* target;
};

extern "C" void fn_27_90924(Wrapper* self) {
    self->target->invoke();
}
