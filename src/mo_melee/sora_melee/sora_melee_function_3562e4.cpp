#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" float fn_27_192278(void*, unsigned long);
extern "C" void fn_27_3564A4(void*);
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern float lbl_27_rodata_7990;

class A {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int s4(u32 a);
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual int s17(u32 a);
    virtual void s18(u32 a);
};
class B {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual void* s6(int a);
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10();
    virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16();
    virtual void s17(void* a, void* b);
    virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(int a, void* b);
};
struct Inner { char pad0[0x64]; A* m64; char pad1[0x14]; B* m7c; };
struct Obj { char pad[0xd8]; Inner* d8; };

extern "C" void fn_27_3562E4(Obj* self) {
    Inner* in = self->d8;
    A* a = in->m64;
    B* b = in->m7c;
    void* r = b->s6(3);
    __dynamic_cast(r, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
    fn_27_3564A4(self);
    switch (a->s4(0x20000000)) {
    case 0:
        if (a->s17(0x22000014) == 0) {
            b->s21(10, self);
            a->s18(0x22000014);
        }
        break;
    case 1: {
        float f = fn_27_192278(self, 0xfa4);
        float v[3];
        v[0] = f; v[1] = f; v[2] = lbl_27_rodata_7990;
        short s = -1;
        b->s17(v, &s);
        break;
    }
    case 2:
        if (a->s17(0x22000015) == 0) {
            b->s21(0, self);
            a->s18(0x22000015);
        }
        break;
    }
}
