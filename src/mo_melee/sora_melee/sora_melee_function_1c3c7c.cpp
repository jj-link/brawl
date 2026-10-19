#pragma force_active on
typedef unsigned int u32;

struct fn_27_1C3C7C_Base {
    virtual void f0();
    virtual u32* f1(u32 x);
    virtual void f2();
    virtual void f3();
};

extern "C" {
void fn_27_1C3C7C(fn_27_1C3C7C_Base* self, u32* src, u32 x) {
    u32* p = self->f1(x);
    *p = *src;
}
}
