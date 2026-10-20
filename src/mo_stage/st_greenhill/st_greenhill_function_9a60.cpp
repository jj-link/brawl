#include <types.h>
#pragma force_active on

class Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual s32* vfunc26(s32* arg);
};

extern "C" void fn_72_9A60(s32* a, s32* b, s32* c) {
    s32* r1 = ((Base*)a)->vfunc26(b);
    s32* r2 = ((Base*)a)->vfunc26(c);
    r2[0] = r1[0];
    r2[1] = r1[1];
}
