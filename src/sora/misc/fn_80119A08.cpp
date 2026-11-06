#pragma force_active on
#include <types.h>
#include <nw4r/math/math_arithmetic.h>

struct Entry {
    u8 pad[0xE];
    u8 flags;
};

struct Segment {
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
    f32 extra;
};

extern "C" s32 fn_80113DF8(void*, void*);
extern "C" s32 fn_80113EC0(void*, void*);
extern "C" void fn_80111968(void*, void*, void*, s32);
extern "C" const f32 lbl_805A2980;

extern "C" s32 fn_80119A08(const Entry* arg0, void* arg1, void* arg2) {
    s32 result;
    Segment buf;

    if (arg0->flags & 8) {
        result = fn_80113DF8(arg1, arg2);
    } else {
        result = fn_80113EC0(arg1, arg2);
    }

    if (result != 0) {
        fn_80111968(*(void**)((char*)arg2 + 8), &buf, *(void**)arg2, 0);

        if (buf.y1 <= buf.y2)
            result = 0;

        u8 flag = ((u8*)(*(void**)arg2))[0xF];
        if (!((flag >> 2) & 1))
            result = 0;

        if ((float)(double)nw4r::math::FAbs(buf.y2 - buf.y1) < lbl_805A2980)
            result = 0;
    }

    return result;
}
