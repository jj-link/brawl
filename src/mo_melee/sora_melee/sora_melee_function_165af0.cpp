#include <types.h>
#pragma force_active on

struct VT {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(u32, u32, u32, u32);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual u32 s17(u32);
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40(u32);
};

extern "C" void fn_27_165AF0(void* unused, u8* obj) {
    VT* b = *(VT**)(*(u8**)(obj + 0xd8) + 0x64);
    u32 r = b->s17(0x12000013);
    if (r == 1) {
        VT* c = *(VT**)(*(u8**)(obj + 0xd8) + 0x50);
        c->s5(0x1fa9, 0, 0, 0);
    }
    VT* d = *(VT**)(*(u8**)(obj + 0xd8) + 0x60);
    d->s40(0);
}
