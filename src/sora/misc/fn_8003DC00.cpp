#include <types.h>
#pragma force_active on

extern "C" float rsqrtf__Ff(float x);

typedef struct {
    float x;
    float y;
} Vec2f;

extern "C" void fn_8003DC00(Vec2f* out, const Vec2f* in) {
    float inv = rsqrtf__Ff(in->x * in->x + in->y * in->y);
    float nx = in->x * inv;
    float ny = in->y * inv;
    out->x = nx;
    out->y = ny;
}
