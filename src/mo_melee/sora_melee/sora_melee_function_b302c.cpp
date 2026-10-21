#include <types.h>
#pragma force_active on

extern "C" float* fn_27_B16C8(void* p);

class soCallbackBase {
public:
    virtual void f0();
    virtual void* f1(u32 arg);
};

struct soCallbackOwner {
    u8 pad[0x18];
    soCallbackBase* callback;
};

struct Vec4 { float x, y, z, w; };

extern "C" void fn_27_B302C(soCallbackOwner* __restrict self, Vec4* out, u32 arg) {
    float* work = (float*)fn_27_B16C8(self->callback->f1(arg));
    out->x = work[15];
    out->y = work[16];
    out->z = work[17];
    out->w = work[18];
}
