#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6A8;
extern const float lbl_10_rodata_6B8;
void setFrameMatCol__8MuObjectFf(void* obj, float col);
}

class MuObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrameMatCol(float col);
    virtual float getFrameMatCol();
};

extern "C" void fn_10_18080(void* self, s32 arg) {
    void* mu = *(void**)((char*)self + 0xd8);
    MuObj* inner = (MuObj*)*(void**)((char*)*(void**)((char*)mu + 0x14) + 0x18);
    float col = inner->getFrameMatCol();
    if (arg >= 0) {
        if (lbl_10_rodata_6A8 == col) {
            MuObj* inner2 = (MuObj*)*(void**)((char*)*(void**)((char*)mu + 0x14) + 0x18);
            inner2->setFrameMatCol(lbl_10_rodata_6B8);
        }
    } else {
        if (lbl_10_rodata_6A8 != col) {
            setFrameMatCol__8MuObjectFf(mu, lbl_10_rodata_6A8);
            MuObj* inner2 = (MuObj*)*(void**)((char*)*(void**)((char*)mu + 0x14) + 0x18);
            inner2->setFrameMatCol(lbl_10_rodata_6A8);
        }
    }
}
