#pragma force_active on
typedef unsigned int u32;

struct Work {
    u32 padding[2];

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual u32 call(u32);
};

struct WorkModule {
    char padding[0x1c];
    Work* work[16];
};

extern "C" u32 fn_27_A2088(WorkModule* module, u32 index) {
    return module->work[(index >> 28) & 0xf]->call(index & 0x00ffffff);
}
