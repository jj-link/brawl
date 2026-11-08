#include <types.h>
#include <math.h>
#pragma force_active on
extern int lbl_805A2230;
extern int lbl_805A2234;
struct Vec2 { float x; float y; };
extern "C" Vec2 fn_800BA0E0(s32 arg0) {
    Vec2 result;
    if (arg0 == 8) {
        result.y = *(float*)&lbl_805A2230;
        result.x = *(float*)&lbl_805A2230;
        return result;
    } else {
        float angle = (*(float*)&lbl_805A2234) * (float)arg0;
        result.x = (float)sin(angle);
        result.y = (float)cos(angle);
        return result;
    }
}