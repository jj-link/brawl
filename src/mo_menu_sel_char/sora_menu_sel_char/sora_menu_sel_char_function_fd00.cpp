#include <types.h>
#pragma force_active on

class MuObject;
extern "C" void setFrameVisible__8MuObjectFf(MuObject*, float);
extern "C" void setFrameNode__8MuObjectFf(MuObject*, float);
extern float lbl_10_rodata_450;

class VObj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(void* a, u32 b);
    virtual void v14();
    virtual void v15(u32 a);
};

extern "C" void fn_10_FD00(char* self, s32 arg1) {
    MuObject* obj = *(MuObject**)(self + 0x3FC);
    u32 r30 = *(u32*)(self + 0x508);
    VObj* q = *(VObj**)(self + 0x6C);
    q->v15(r30);
    if (arg1 != 0) {
        f32 f = (f32)arg1 - lbl_10_rodata_450;
        setFrameVisible__8MuObjectFf(obj, f);
        setFrameNode__8MuObjectFf(obj, f);
        q = *(VObj**)(self + 0x6C);
        q->v13(*(void**)((char*)q + 0xE4), r30);
    }
}
