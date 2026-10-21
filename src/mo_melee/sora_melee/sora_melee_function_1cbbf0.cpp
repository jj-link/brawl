#pragma force_active on
struct Dispatch {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};

extern "C" void fn_27_1CBBF0(void* object) {
    reinterpret_cast<Dispatch*>(static_cast<char*>(object) + 0x10)->f8();
}
