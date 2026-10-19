#include <types.h>
#pragma force_active on

class soTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual soTarget* vf2(u32 v);
};

struct soPair {
    soTarget* p;
    u8 b;
};

struct Inner {
    u32 pad;
    void* value;
};

struct Object {
    Inner* inner;
    u8 state;
};

class VObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 vf4(u32 v);
};

extern "C" {
soPair fn_27_778CC(soTarget* p, u32 n);
void* fn_113_2359C(Object* object);
}

extern "C" s32 fn_113_23900(void* this_, void* arg1, soTarget* arg2, void* arg3) {
    soPair pair = fn_27_778CC(arg2, 0);
    u32 mask = (u32)fn_113_2359C((Object*)&pair);
    void* mid = *(void**)((char*)arg3 + 0xd8);
    VObj* v = (VObj*)*(void**)((char*)mid + 0x64);
    s32 r = v->vf4(0x10000011);
    u32 x = (u32)r & mask;
    return (x != 0);
}
