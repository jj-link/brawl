#pragma force_active on
typedef unsigned long u32;
typedef float f32;

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
f32 fn_27_192278(void* self, u32 arg);
}
extern f32 lbl_27_rodata_7E9C;

class W {
public:
    virtual ~W();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual f32 v14(u32 id);
    virtual void v15();
    virtual void v16();
    virtual void v17(u32 id, f32 value);
    virtual void v18();
    virtual u32 v19(u32 id);
};

class A {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual int s9();
};

struct CBase { char pad[0x8]; };
class C : public CBase {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual int c14();
};

class Sub {
public:
    char pad0[0x44];
    A* m_44;
    char pad1[0x64 - 0x48];
    W* m_64;
    char pad2[0xb8 - 0x68];
    C* m_b8;
};

class Self {
public:
    char pad[0xd8];
    Sub* m_d8;
};

extern "C" {
void fn_27_3A28D0(void* unused, Self* self) {
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) != 1) {
        return;
    }
    if (self->m_d8->m_44->s9() != 0) {
        return;
    }
    if (self->m_d8->m_b8->c14() != 0) {
        return;
    }
    if (self->m_d8->m_64->v19(0x12000047) == 1) {
        return;
    }
    W* w = self->m_d8->m_64;
    f32 f = fn_27_192278(self, 0xfa6);
    if (w->v14(0x11000013) < f) {
        self->m_d8->m_64->v17(0x11000013, lbl_27_rodata_7E9C);
    }
}
}
