#pragma force_active on
struct soBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

extern "C" void fn_27_293250(void* p) {
    ((soBase*)((char*)p + 0x10))->f3();
}
