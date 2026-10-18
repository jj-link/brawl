#pragma force_active on
extern void *lbl_113_bss_F4;

class Obj
{
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};

extern "C" void fn_113_12C1C()
{
    ((Obj *)&lbl_113_bss_F4)->f7();
}
