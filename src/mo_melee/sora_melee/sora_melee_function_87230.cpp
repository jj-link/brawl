#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual unsigned int method();
};

struct Wrapper {
    char padding[0x14];
    Target* target;
};

extern "C" unsigned int fn_27_87230(Wrapper* self) {
    return self->target->method();
}
