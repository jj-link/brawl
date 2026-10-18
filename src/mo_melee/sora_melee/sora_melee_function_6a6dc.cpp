#include <types.h>
#pragma force_active on

class SoInner {
public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
};

class SoOuter {
public:
    u8 pad[0x48];
    SoInner* inner;
};

extern u8 lbl_27_bss_110[0x10];
extern "C" void fn_27_6F518(void* dst, void* src);

extern "C" void fn_27_6A6DC(SoOuter* self) {
    void* p = self->inner->v1();
    fn_27_6F518(lbl_27_bss_110, p);
}
