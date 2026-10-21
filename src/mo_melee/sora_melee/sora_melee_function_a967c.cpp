#include <types.h>
#pragma force_active on

class gfGameFrameCounter {
public:
    s32 getCounter() const;
};

class soWaitObj {
public:
    virtual bool vf0();

    u8 m_pad0[0x8 - 0x4];
    u8 m_counterBuf[0x14 - 0x8];
    s32 m_0x14;
};

extern "C" bool fn_27_A91A0(soWaitObj* self, u32 a, u32 b);

extern "C" bool fn_27_A967C(soWaitObj* self, u32 a, u32 b) {
    if (!self->vf0()) {
        return false;
    }
    if (self->m_0x14 > 0) {
        gfGameFrameCounter* counter = (gfGameFrameCounter*)((u8*)self + 0x8);
        if (counter->getCounter() != 0) {
            return false;
        }
    }
    return fn_27_A91A0(self, a, b);
}
