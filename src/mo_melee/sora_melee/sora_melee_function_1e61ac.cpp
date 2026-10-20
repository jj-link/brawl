#pragma force_active on
struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

extern "C" {
void fn_27_1E61AC(void* self) {
    ((B*)((char*)self + 0x10))->f3();
}
}
