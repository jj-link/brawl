#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B5854(void* p, int a, int b, int c, int d);
void setFrameMatCol__8MuObjectFf(void* obj, float col);
}

extern const float lbl_10_rodata_6B8[1];

struct MuObject {
    u8 _[0xc0];
    void* f0c0;
    void* f0c4;
};

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setColor(float);
};

extern "C" void fn_10_17C18(MuObject* self) {
    fn_800B5854(self->f0c0, 1, 0x10, 1, 0);
    setFrameMatCol__8MuObjectFf(self->f0c4, lbl_10_rodata_6B8[0]);

    Base* inner = *(Base**)((char*)*(void**)((char*)self->f0c4 + 0x14) + 0x18);
    inner->setColor(lbl_10_rodata_6B8[0]);

    *(u8*)((char*)self + 0x1f9) = 1;
}
