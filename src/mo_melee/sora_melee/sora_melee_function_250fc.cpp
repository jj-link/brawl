#include <types.h>
#pragma force_active on

struct Vec2w {
    u32 x;
    u32 y;
};

struct Vec3w {
    Vec2w xy;
    u32 z;
};

struct InnerObj {
    virtual void unk0();
    virtual Vec3w* getVec(s32 idx);
};

struct OwnerObj {
    u8 pad[0x5c];
    InnerObj* inner;
};

extern "C" {
void fn_27_250FC(Vec3w* out, OwnerObj* owner, s32 arg) {
    Vec3w* src = owner->inner->getVec(arg);
    *out = *src;
}
}
