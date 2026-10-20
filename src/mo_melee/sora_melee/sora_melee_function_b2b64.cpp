#include <types.h>
#pragma force_active on

struct Pair {
    u32 a;
    u32 b;
};

struct Inner {
    virtual void vf0();
    virtual void* vf1(u32 x, float y);
};

struct Outer {
    char pad[0x18];
    Inner* m_inner;
};

extern "C" void fn_27_B1DA8(void* obj, float f, u32 a, Pair* p);

extern "C" void fn_27_B2B64(Outer* self, u32 a, u32 b, const Pair* p, float f) {
    Pair tmp = *p;
    void* ret = self->m_inner->vf1(b, f);
    fn_27_B1DA8(ret, f, a, &tmp);
}
