#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, unsigned long);
};

struct Mid {
    char pad[0x64];
    Inner* inner;
};

struct Acc {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_17496C(void);

extern "C" void fn_27_1769A4(void* unused, Acc* b) {
    fn_27_17496C();
    b->mid->inner->v5(8, 0x1000000f);
}
