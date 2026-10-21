#include <types.h>
#pragma force_active on

typedef signed char s8;
typedef short s16;
typedef unsigned char u8;

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

extern "C" {
    void fn_27_693F4(void*, void*);
    void fn_27_D40CC(void*, s16);
    void fn_27_D40EC(void*, s16, s8);
    extern char lbl_41_data_2510[];
    extern char lbl_41_data_3780[];
}

struct Self {
    void* m_vtable;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    void* m_p10;
    void* m_p14;
    void* m_p18;
    void* m_p1C;
    void* m_p20;
    void* m_p24;
    void* m_p28;
    void* m_p2C;
    void* m_p30;
    void* m_p34;
    void* m_innerVtable;
    void* m_p3C;
    void* m_p40;
    s32 m_val44;
    s32 m_val48;
};

extern "C" Self* fn_41_2A724(Self* self, Arg1* arg1) {
    fn_27_693F4(self, arg1);
    s16 result = arg1->m_holder->m_combined->f6();
    void* inner = &self->m_innerVtable;
    fn_27_D40CC(inner, 5);
    *(void**)inner = (void*)lbl_41_data_2510;
    fn_27_D40EC(inner, result, -1);
    self->m_vtable = (void*)lbl_41_data_3780;
    self->m_p04 = (void*)(lbl_41_data_3780 + 0x34);
    self->m_p10 = (void*)(lbl_41_data_3780 + 0x48);
    self->m_innerVtable = (void*)(lbl_41_data_3780 + 0x5c);
    self->m_val44 = -1;
    self->m_val48 = 0;
    return self;
}
