#pragma force_active on
namespace {
struct ModelModule {
    virtual void* f0() = 0;
    virtual void* f1() = 0;
    virtual void* f2() = 0;
    virtual void* f3() = 0;
    virtual void* f4() = 0;
    virtual void* f5() = 0;
    virtual void* f6() = 0;
    virtual void* f7() = 0;
    virtual void* f8() = 0;
    virtual void* f9() = 0;
    virtual void* f10() = 0;
    virtual void* f11() = 0;
    virtual void* f12() = 0;
    virtual void* f13() = 0;
    virtual void* f14() = 0;
    virtual void* f15() = 0;
    virtual void* f16() = 0;
};

struct EnumerationStart {
    unsigned char padding[0x70];
    ModelModule* modelModule;
};

struct Accesser {
    unsigned char padding[0xD8];
    EnumerationStart* enumerationStart;
};
}

extern "C" void fn_27_613AC(void*, void*);

extern "C" void fn_117_23CC0(void*, Accesser* accesser) {
    void* result = accesser->enumerationStart->modelModule->f16();
    fn_27_613AC(accesser, result);
}
