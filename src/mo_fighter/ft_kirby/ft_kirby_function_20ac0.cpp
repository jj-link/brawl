#include <ft/ft_common_data_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_145854(s32 unused, s32 slot, s32 kind, s32 arg);

struct VtObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(u32 id);
    virtual void v5();
    virtual void* v6();
};

struct Inner {
    char pad0[0x64];
    VtObj* c;
    char pad1[0xc0 - 0x68];
    VtObj* d;
};

struct Outer {
    char pad0[0xd8];
    Inner* inner;
};

struct Self {
    char pad0[8];
    Outer* outer;
};

inline VtObj* prepare(VtObj* c, Inner* b, VtObj*& d) {
    d = b->d;
    return c;
}

extern "C" void fn_96_20AC0(Self* self, s32 kind) {
    void* arg;
    Outer* a = self->outer;
    Inner* b = a->inner;
    VtObj* d;
    arg = prepare(b->c, b, d)->v4(0x10000049);
    void* slot = d->v6();
    fn_27_145854((s32)&g_ftCommonDataAccesser, (s32)slot, kind, (s32)arg);
}
