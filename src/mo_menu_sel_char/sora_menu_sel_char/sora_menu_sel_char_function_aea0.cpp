#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6C;
extern const u8 lbl_10_rodata_118[];
u32 fn_10_14618(void*);
}

struct Obj6C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void f34(void*, void*);
    virtual void v14();
    virtual void f3c(void*);
};

extern "C" int fn_10_AEA0(char* self) {
    float f = lbl_10_rodata_6C;
    int best = -1;
    int max = 0;
    int n = *(int*)(self + 0x648);
    char* p = self;

    for (int i = 0; i < n; i++) {
        int v = *(int*)(*(char**)(*(char**)(p + 0x44) + 0x1a8) + 0xc8);
        if (v > max) {
            max = v;
            best = i;
        }
        p += 4;
    }

    if (best >= 0) {
        int k = fn_10_14618(*(void**)(self + 0x44 + best * 4));
        if (k < 4) {
            f = (float)lbl_10_rodata_118[k];
        }
    }

    Obj6C* o = *(Obj6C**)(self + 0x6c);
    MuObject* mu = *(MuObject**)(self + 0x148);
    o->f3c(*(void**)((char*)mu + 0x10));

    if (max > 0) {
        o = *(Obj6C**)(self + 0x6c);
        o->f34(*(void**)((char*)o + 0xe4), *(void**)((char*)mu + 0x10));
        mu->setFrameVisible(f);
        mu->setFrameNode((float)max);
    }

    if (max >= 30) {
        return best;
    } else {
        return -1;
    }
}
