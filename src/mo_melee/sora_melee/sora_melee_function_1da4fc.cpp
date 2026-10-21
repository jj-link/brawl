#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void call();
};

struct Inner {
    unsigned char padding[8];
    Target* target;
};

struct Middle {
    unsigned char padding[0xD8];
    Inner* inner;
};

struct Outer {
    unsigned char padding[0x60];
    Middle* middle;
};

extern "C" void fn_27_1DA4FC(Outer* self) {
    self->middle->inner->target->call();
}
