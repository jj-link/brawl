#include <types.h>
#pragma force_active on

class soWorkBase {
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
    virtual u32* getWork(u32 index);
};

extern "C" void fn_27_766D8(soWorkBase* self, u32 srcIndex, u32 dstIndex) {
    u32* src = self->getWork(srcIndex);
    u32* dst = self->getWork(dstIndex);
    *dst = *src;
}
