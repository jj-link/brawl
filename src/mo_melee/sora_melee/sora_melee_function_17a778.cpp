#pragma force_active on
struct SoVirtualObj {
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
    virtual void f17();
};

struct SoMidObj {
    char pad[0x40];
    SoVirtualObj* m_obj;
};

struct SoOuterObj {
    char pad[0xd8];
    SoMidObj* m_mid;
};

extern "C" void fn_27_17A778(void* unused, SoOuterObj* p) {
    p->m_mid->m_obj->f15();
}
