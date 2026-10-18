#pragma force_active on
class VInner {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
};

struct Mid {
    char pad[0x3c];
    VInner* inner;
};

struct Actor {
    char pad[0xd8];
    Mid* mid;
};

extern "C" int fn_109_CC3C(void* unused, Actor* a) {
    return a->mid->inner->f13();
}
