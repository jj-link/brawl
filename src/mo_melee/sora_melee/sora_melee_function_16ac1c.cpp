#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned int slot2();
};

struct Wrapper {
    unsigned int padding;
    Target* target;
};

extern "C" unsigned int fn_27_16AC1C(Wrapper* self) {
    return self->target->slot2();
}
