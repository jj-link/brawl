#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int invoke();
};

struct Wrapper {
    unsigned int padding[2];
    Target* target;
};

extern "C" int fn_27_DA0D8(Wrapper* self) {
    return self->target->invoke();
}
