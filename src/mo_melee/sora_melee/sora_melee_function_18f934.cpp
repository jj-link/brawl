#pragma force_active on
struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void f10(int);
    virtual int f11(int);
};

extern "C" void fn_27_18F934(void* unused, char* self) {
    SubObj* sub = *(SubObj**)(*(char**)(self + 0xd8) + 0x54);
    if (sub->f11(4) != 0) {
        sub = *(SubObj**)(*(char**)(self + 0xd8) + 0x54);
        sub->f10(4);
    }
}
