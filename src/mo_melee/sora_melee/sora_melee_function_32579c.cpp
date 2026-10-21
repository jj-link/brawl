#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Base {
    void* m_v0;
    u8 m_flag;
};

struct fnSub : Base {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25();
    void* m_self;
    s32 m_6;
    void* m_p18;
    s32 m_one;
    void* m_p1c;
    s32 m_one2;
};

struct fnOuter {
    u8 pad[0x20];
    fnSub sub;
};

extern "C" {
extern char __vt__19soGeneralWorkSimple[];

void* fn_27_32579C(fnOuter* p) {
    fnSub* s = &p->sub;
    s->m_flag = 0;
    s->m_self = p;
    *(void**)((char*)s + 8) = __vt__19soGeneralWorkSimple;
    s->m_v0 = (char*)__vt__19soGeneralWorkSimple + 8;
    s->m_6 = 6;
    s->m_p18 = (char*)p + 0x18;
    s->m_one = 1;
    s->m_p1c = (char*)p + 0x1c;
    s->m_one2 = 1;
    s->f25();
    return p;
}
}
