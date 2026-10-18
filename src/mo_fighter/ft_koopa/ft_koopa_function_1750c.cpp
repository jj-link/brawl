#pragma force_active on
class Mod {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual int f19(unsigned int id);
    virtual void f20();
    virtual void f21(unsigned int id);
    virtual void f22();
    virtual void f23();
    virtual void f24(int v);
};

extern "C" void fn_102_1750C(void* unused, char* p) {
    Mod* m = *(Mod**)(*(char**)(p + 0xd8) + 0x64);
    if (m->f19(0x1200003d)) {
        m->f24(2);
        m->f21(0x22000011);
        m->f21(0x1200003d);
    }
}
