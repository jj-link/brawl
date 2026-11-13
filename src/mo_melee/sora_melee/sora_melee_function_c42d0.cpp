#include <types.h>
#pragma force_active on

struct IObj {
    virtual void f0();
    virtual void* get(s32 idx);
    virtual void f2();
    virtual s32 size();
    virtual void f4();
};

struct Outer {
    char pad[4];
    IObj iface;
};

struct Item {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
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
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual s32 s20();
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
    virtual float s33();
};

extern "C" void* fn_27_C42D0(void* arg0, u32 arg1) {
    Outer* outer = (Outer*)arg0;
    s32 count = outer->iface.size();
    Item* best = 0;
    for (s32 i = 0; i < count; i++) {
        if (((Item*)*(void**)outer->iface.get(i))->s20() == 0) {
            return *(void**)outer->iface.get(i);
        }
        if (best != 0) {
            void** p = (void**)outer->iface.get(i);
            float fb = best->s33();
            if (!(((Item*)*p)->s33() < fb)) {
                continue;
            }
        }
        best = (Item*)*(void**)outer->iface.get(i);
    }
    if (arg1 == 1 && best != 0) {
        best->s21();
        return best;
    }
    return 0;
}
