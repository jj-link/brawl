#include <types.h>
#pragma force_active on

struct Vec2fCopy {
    float x;
    float y;
};

extern "C" void fn_116_CB3C(Vec2fCopy* dst, const Vec2fCopy* src) {
    dst->x = src->x;
    dst->y = src->y;
}
