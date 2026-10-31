#include <types.h>
#pragma force_active on

class soVirt {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(s32 a, u32 b);
};

struct soData {
    u32 pad[3];
    u32 w;
};

extern "C" {
void fn_27_1DBEBC(soVirt* self, u32 a, u32 b, soData* obj, u32 d) {
    s32 r = (s32)(((obj->w >> 12) & 0x1FF) << 23) >> 24;
    if (r <= -1) {
        return;
    }
    self->vf23(r, d);
}
}
