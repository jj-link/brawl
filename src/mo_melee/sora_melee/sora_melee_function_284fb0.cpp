#pragma force_active on
struct IFoo {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int a, void* b);
    virtual void v4();
    virtual void v5();
};

extern "C" void fn_27_284FB0(char* self, int a) {
    IFoo* p = (IFoo*)(self + 0x2c34);
    p->v3(a, self + 0xcc);
}
