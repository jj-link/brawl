#pragma force_active on
struct FnObj94 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

extern "C" void fn_94_CCFC(void* p) {
    reinterpret_cast<FnObj94*>(static_cast<char*>(p) + 0x2565c)->f2();
}
