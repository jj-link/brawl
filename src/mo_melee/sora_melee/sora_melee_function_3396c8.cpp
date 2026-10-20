#include <types.h>
#pragma force_active on

class soInner {
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
    virtual void vf15(u32, u32, u32);
};

struct soMid {
    u8 pad[0x28];
    soInner* inner;
};

struct soOuter {
    u8 pad[0xd8];
    soMid* mid;
};

extern "C" {
void fn_27_3396C8(void*, soOuter* p) {
    p->mid->inner->vf15(0, 0, 2);
}
}
