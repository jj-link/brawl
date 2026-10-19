#pragma force_active on
extern "C" void fn_98_855C(void*, void*, int, void*, int, void*, int);

namespace {
struct Base {
    int a;
    int b;
};
class Obj : public Base {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void target() = 0;
};
}

extern "C" void* fn_98_8A5C(void* self) {
    char* base = static_cast<char*>(self);
    fn_98_855C(base + 0x1c0, self, 0x4d, base + 0x134, 0x20, base + 0x1b4, 3);
    reinterpret_cast<Obj*>(base + 0x1c0)->target();
    return self;
}
