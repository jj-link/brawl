#include <types.h>
#pragma force_active on

class fnInner {
public:
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
    virtual void vf18(u32 a, u32 b);
};

class fnOuter {
public:
    u8 pad[0x10];
    fnInner* child;
};

extern "C" {
void fn_801840FC(fnOuter* self, u32 a) {
    if (self->child != 0) {
        self->child->vf18(a, 1);
    }
}
}
