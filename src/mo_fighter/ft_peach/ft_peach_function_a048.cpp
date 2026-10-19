#include <types.h>
#pragma force_active on

struct PeachVec2 {
    f32 x;
    f32 y;
};

class PeachSource {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual PeachVec2 v2() = 0;
};

extern "C" {
extern const f32 lbl_103_rodata_8;

void fn_103_A048(f32* dst, PeachSource* src) {
    PeachVec2 r = src->v2();
    dst[0] = r.x;
    dst[1] = r.y;
    dst[2] = lbl_103_rodata_8;
}
}
