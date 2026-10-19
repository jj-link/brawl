#pragma force_active on
struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(unsigned int a, unsigned int b);
};

extern "C" void fn_113_180A4(char *self)
{
    Obj *p = *(Obj **)(*(char **)(*(char **)(self + 0x60) + 0xd8) + 0x64);
    unsigned int unused;
    p->f5(unused, 0x10000010);
}
