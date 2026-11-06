#pragma force_active on
#include <types.h>
#include <nw4r/math/math_arithmetic.h>

struct Node {
    u8 pad[0xE];
    u8 flagsE;
    u8 flagsF;
};

struct Record {
    Node* node;
    u32 unk4;
    void* owner;
};

struct Segment {
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
    f32 extra;
};

extern "C" {
s32 fn_80113DF8(void*, Record*);
s32 fn_80113EC0(void*, Record*);
void fn_80111968(void*, Segment*, Node*, s32);
extern f32 lbl_805A2980;

s32 fn_80119AD4(const Node* arg0, void* arg1, Record* arg2) {
    Segment seg;
    s32 result;

    if (arg0->flagsE & 1) {
        result = fn_80113DF8(arg1, arg2);
    } else {
        result = fn_80113EC0(arg1, arg2);
    }

    if (result != 0) {
        fn_80111968(arg2->owner, &seg, arg2->node, 0);

        if (seg.x1 < seg.x2)
            result = 0;

        if (!((arg2->node->flagsF >> 1) & 1))
            result = 0;

        if ((f32)(double)nw4r::math::FAbs(seg.x2 - seg.x1) < lbl_805A2980)
            result = 0;
    }

    return result;
}
}
