#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6B8;
extern const float lbl_10_rodata_6A8;
int fn_800B5854(void*, int, int, int, int);
void setFrameMatCol__8MuObjectFf(void*, float);
}

extern "C" void fn_10_17B8C(void* self, int arg) {
    unsigned char* p = static_cast<unsigned char*>(self);
    void* mu = *reinterpret_cast<void**>(p + 0xC0);

    if (p[0x1F9] == 0) {
        fn_800B5854(mu, 0, 0x10, 0, 0);
        float col = arg ? lbl_10_rodata_6B8 : lbl_10_rodata_6A8;
        setFrameMatCol__8MuObjectFf(mu, col);
    }

    p[0x1F8] = static_cast<unsigned char>(arg);
}
