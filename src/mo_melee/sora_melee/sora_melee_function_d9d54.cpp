#pragma force_active on
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

extern "C" void fn_27_D9D54(void* p) {
    ((Inner*)((char*)p + 0x10))->f3();
}
