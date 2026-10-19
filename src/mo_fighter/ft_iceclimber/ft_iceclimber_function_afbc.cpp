#pragma force_active on
extern "C" void* fn_105_B02C(void*);
extern "C" void fn_27_131CD0(void*, int, int, int);

struct ft_iceclimber_iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int, int);
};

extern "C" void fn_105_AFBC(void* self, int a, int b, int c) {
    ft_iceclimber_iface* iface = static_cast<ft_iceclimber_iface*>(fn_105_B02C(self));
    iface->f6(a, b, c);
    fn_27_131CD0(self, a, b, c);
}
