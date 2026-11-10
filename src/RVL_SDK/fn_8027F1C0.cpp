#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

class Obj {
public:
    virtual ~Obj();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 alloc(s32 size, s32 align);
};

extern "C" s32 fn_8027F1C0(Obj* self, s32 a, s32 b, s32 c) {
    s32 t = a + b;
    s32 r = self->alloc(t + 0x10, c);
    s32 p = nw4r::ut::RoundUp(r + 0x10, a);

    *(s32*)(p - 0x10) = 0x02345656;
    *(s32*)(p - 0xC) = t;
    *(s32*)(p - 0x8) = c;
    *(s32*)(p - 0x4) = p - r;
    return p;
}
