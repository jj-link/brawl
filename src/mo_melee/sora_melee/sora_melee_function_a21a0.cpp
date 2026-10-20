#pragma force_active on
typedef unsigned int u32;

struct WorkBase {
    u32 padding[2];
};

struct Work : WorkBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void call(u32);
};

struct WorkModule {
    unsigned char padding[0x1c];
    Work* works[16];
};

extern "C" void fn_27_A21A0(WorkModule* module, u32 index) {
    module->works[index >> 28]->call(index & 0x00ffffff);
}
