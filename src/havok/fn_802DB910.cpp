#include <types.h>
#pragma force_active on
struct Vec { float x, y, z, w; } __attribute__((aligned(16)));
extern "C" void fn_802DB910(Vec* a, Vec* b) {
    Vec temp;
    temp.x = a->x;
    temp.y = a->y;
    temp.z = a->z;
    temp.w = a->w;
    *a = *b;
    *b = temp;
}