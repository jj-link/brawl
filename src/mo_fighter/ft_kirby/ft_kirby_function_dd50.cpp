#pragma force_active on
extern "C" void fn_96_DC08(void* self);

namespace {
struct FinalClass {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual long getPtr(unsigned long id);
};

struct MidClass {
    char pad[0x64];
    FinalClass* final;
};

struct TopClass {
    char pad[0xd8];
    MidClass* mid;
};

struct SelfClass {
    char pad[0x60];
    TopClass* top;
};
}

extern "C" void fn_96_DD50(SelfClass* self, long p2, long p3) {
    if (self->top->mid->final->getPtr(0x10000049) == p2 &&
        self->top->mid->final->getPtr(0x10000048) == p3) {
        fn_96_DC08(self);
    }
}
