#pragma force_active on
#include <types.h>

struct Big {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual float get(void*, void*);
};

struct Ret {
    virtual void unused0();
    virtual void unused1();
    virtual int get();
};

struct Mid {
    virtual void unused0();
    virtual void unused1();
    virtual Ret* get();
};

struct Sub {
    char pad[0x28];
    int value;
};

struct R7 {
    char pad0[0xc];
    Big* big;
    char pad1[0x8];
    Mid* mid;
};

struct Obj {
    char pad0[0x8];
    Sub* sub;
    char pad1[0xcc];
    R7* r7;
};

extern "C" void fn_27_33647C(void*, int, int, int, float);

extern "C" s32 fn_27_331728(s32 a, void* b, Obj* obj, s32 d) {
    R7* r7 = obj->r7;
    Mid* mid = r7->mid;
    Sub* sub = obj->sub;
    int v = sub->value;
    float f = r7->big->get(sub, obj);
    Ret* ret = mid->get();
    fn_27_33647C(b, v, d, ret->get(), f);
    return 1;
}
