#include <types.h>
#pragma force_active on

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
float fn_113_23CA0(void*, s32);
u32 fn_113_23B54();
void fn_113_23B84(void*);
}

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void notifyEvent(u32, void*);
    virtual void v6(u32);
};

struct Inner {
    char pad0[0x64];
    Module* m64;
    char pad1[0x70 - 0x68];
    Module* m70;
};

struct Accesser {
    char pad0[0xD8];
    Inner* unkD8;
};

extern "C" void fn_113_25D40(void*, void* arg) {
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg, 0xfa4, 0);
    float r = fn_113_23CA0(arg, 3);
    if (r >= c) {
        return;
    }
    Accesser* acc = (Accesser*)arg;
    acc->unkD8->m64->v6(0x1000000F);
    if (fn_113_23B54() == 1) {
        fn_113_23B84(arg);
    } else {
        acc->unkD8->m70->notifyEvent(8, arg);
    }
}
