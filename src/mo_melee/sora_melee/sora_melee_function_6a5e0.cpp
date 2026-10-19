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
extern "C" bool fn_27_6F418(void*, void*, u32, void*);

extern "C" bool fn_27_6A5E0(SoOuter* self, void* arg1, u32 id) {
    void* link = self->inner->v1();
    return fn_27_6F418(lbl_27_bss_110, self, id, link);
}
