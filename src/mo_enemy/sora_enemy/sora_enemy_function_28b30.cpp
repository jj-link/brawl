#include <types.h>
#pragma force_active on

class Primary {
public:
    s32 m_a;
    s32 m_b;
};

class IFace {
public:
    virtual ~IFace();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual s16 f6();
};

class Combined : public Primary, public IFace {};

class Holder {
public:
    s32 m_data[32];
    Combined* m_combined;
};

class Arg1 {
public:
    s32 m_data[54];
    Holder* m_holder;
};

class Inner {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
};

struct Pair {
    s32 a;
    s32 b;
};

extern "C" {
    void fn_27_D40CC(void*, s16);
    void fn_27_D40EC(void*, s16, s8);
    void fn_27_D4B40(void*, s16);
    void fn_27_D4B60(void*, s16, s8);
    void fn_27_D2D74(void*, s32, Pair*, s32);
    extern char lbl_41_data_2510[];
    extern char lbl_41_data_944[];
    extern char lbl_41_data_3710[];
}

struct Self {
    void* m_vtable;
    s32 m_04;
    s32 m_08;
    void* m_vtable2;
    s32 m_10;
    s32 m_14;
    Arg1* m_arg1;
    s32 m_1C;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 m_2C;
    s32 m_30;
    u8 m_34;
    s32 m_38;
    Inner* m_innerPtr;
    Inner m_inner;
    s32 m_pad[6];
    s32 m_5C;
    s32 m_60;
};

extern "C" Self* fn_41_28B30(Self* self, Arg1* arg1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s16 r1 = arg1->m_holder->m_combined->f6();
    fn_27_D40CC(self, 5);
    self->m_vtable = (void*)lbl_41_data_2510;
    fn_27_D40EC(self, r1, -1);
    s16 r2 = arg1->m_holder->m_combined->f6();
    void* sub = &self->m_vtable2;
    fn_27_D4B40(sub, 1);
    *(void**)sub = (void*)lbl_41_data_944;
    fn_27_D4B60(sub, r2, -1);
    self->m_vtable = (void*)lbl_41_data_3710;
    self->m_vtable2 = (void*)(lbl_41_data_3710 + 0x14);
    self->m_arg1 = arg1;
    self->m_1C = a2;
    self->m_20 = a3;
    self->m_24 = a4;
    self->m_28 = a5;
    self->m_2C = a6;
    self->m_30 = 0;
    self->m_34 = 0;
    self->m_38 = -1;
    Pair p;
    p.a = -2;
    p.b = -1;
    self->m_innerPtr = &self->m_inner;
    fn_27_D2D74(&self->m_inner, 2, &p, 0);
    self->m_inner.g13();
    self->m_5C = -2;
    self->m_60 = -1;
    return self;
}
