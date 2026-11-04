#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" int fn_800B5854(void*, int, int, int, int);
extern "C" const float lbl_10_rodata_6A8;

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getFrameMatCol();
};

extern "C" void fn_10_17F98(void* self, s32 arg) {
    MuObject* mu = *(MuObject**)((char*)self + 0xd4);
    if (mu) {
        Inner* inner = (Inner*)*(void**)((char*)mu->m_modelAnim + 0x18);
        float col = inner->getFrameMatCol();
        if (arg >= 0) {
            if (lbl_10_rodata_6A8 == col) {
                fn_800B5854(mu, 1, 0x10, 1, 0);
            }
        } else if (lbl_10_rodata_6A8 != col) {
            fn_800B5854(mu, 0, 0x10, 0, 0);
            mu->setFrameMatCol((float)*(s32*)((char*)self + 0x1d0));
        }
    }
}