#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

class Sub {
public:
    virtual void f0();
    virtual u32 f3(u32 idx);
    virtual void f4();
    virtual s32 count();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};

class Visitor {
public:
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
    virtual void visit(u32* p);
};

struct Outer {
    u8 pad[0x10];
    Sub m_sub;
};

extern "C" void fn_27_2EB538(Outer* self, Visitor* v) {
    s32 n = self->m_sub.count();
    for (s32 i = 0; i < n; i++) {
        u32 x = self->m_sub.f3(i);
        v->visit(&x);
    }
}
